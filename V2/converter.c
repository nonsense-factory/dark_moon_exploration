// converter.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototype.h"

#define DELIMS "\040\n,"

void place_river(EDGE edge, int whitewater, int direction_from_a, int flow, MAP map);

enum DroneDirection {North = 0, NorthEast = 1, SouthEast = 2, 
                   South = 3, SouthWest = 4, NorthWest = 5};
enum Clockedness   {clockwise = 1, counter_clockwise = 0};

void PrintMap(MAP map){
    TILE *tmp = map.start;
    printf("%d, %d\n", map.size.col, map.size.row);
    for(int i = 0; i < map.size.row;i++){
        for(int j = 0; j < map.size.col; j++){
            COORD where = {j, i};

            TILE *to_print = CoordToTile(where, map);
            if (to_print != NULL) printf("{%2d,%2d}",to_print->height, to_print->biome );
        }
    printf("\n");
    }
    
}

// Read 3 files into a map program
MAP BuildMap(FILE *elevation_fp, FILE *biome_fp, FILE *river_fp){
        
    int buffer_size = 256;
    int num_cols = 0;
    int num_rows = 1;
    char buffer[3][256] = {"", "", ""};
    char *elevation, *biome;

    // Read the first line of the elevation file to find the size of the map
    elevation = fgets(buffer[0], buffer_size, elevation_fp);
    char *tok = strtok(elevation, DELIMS);
    num_cols = atoi(tok);
    // printf("\n%d\n",num_cols);
    tok = strtok(NULL, DELIMS);
    num_rows = atoi(tok);
    // printf("\n%d\n",num_rows);
    
    
    MAP map = {calloc(num_rows*num_cols, sizeof(TILE)), {num_cols, num_rows}};
    TILE *map_pointer = map.start;
    // printf("Malloc successful \n");
    
    // printf("\n\n~~~~~~~~~~~ELEVATION~~~~~~~~~~~~\n\n");
    // Do the elevation and biome files together
    for (int i = 0; i < num_rows; i++){
        COORD where = {0, i};
        elevation = fgets(buffer[0], buffer_size, elevation_fp);
        tok = strtok(elevation, DELIMS);
        int num = atoi(tok);
        (CoordToTile(where, map))->height = atoi(tok);
        for (int j = 1; j < num_cols; j++){
            where.col = j;
            tok = strtok(NULL, DELIMS);
            (CoordToTile(where, map))->height = atoi(tok);
        }
        // printf("\n")
    }

    // printf("\n\n~~~~~~~~~~~~~BIOMES~~~~~~~~~~~~~\n\n");
    for (int i = 0; i < num_rows; i++){
        biome = fgets(buffer[1], buffer_size, biome_fp);
        tok = strtok(biome, DELIMS);
        COORD where = {0, i};
        int num = atoi(tok);
        (CoordToTile(where, map))->biome = num;
        for (int j = 1; j < num_cols; j++){
            where.col = j;
            tok = strtok(NULL, DELIMS);
            num = atoi(tok);
            (CoordToTile(where, map))->biome = num;
        }
    }
    
    // printf("\n\n~~~~~~~~~~~~~RIVERS~~~~~~~~~~~~~\n\n");
    // Toss the first line of the river file
    char *river_ptr = fgets(buffer[2], buffer_size, river_fp);
    int num_rivers = atoi(strtok(buffer[2], DELIMS));
    // printf("%d rivers.\n", num_rivers);
    // while(fgets(buffer[2], buffer_size, river_fp)){
    for(int k = 0; k < num_rivers; k++){
        fgets(river_ptr, buffer_size, river_fp);
        char *col = strtok(river_ptr, DELIMS);
        char *row = strtok(NULL, DELIMS);
        COORD river_start = {atoi(col), atoi(row)};
        enum DroneDirection direction = atoi(strtok(NULL, DELIMS));
        int file_flow = atoi(strtok(NULL, DELIMS));
        // Print the starting tile's coordinates
        // printf("%d, %d - \n", river_start.col, river_start.row);

        enum Clockedness flow = (file_flow) ? counter_clockwise: clockwise;    
        int whitewater = 0 ;

        EDGE river_edge = {river_start, HexMovement(river_edge.a, direction, map)};

        if (river_edge.b.col == -1 || river_edge.a.col == -1) {
              printf("River flows off map edge.\n");
              continue;
            }
        place_river(river_edge, whitewater, direction, flow, map);

        char* next_char;
        // Main loop
        while (*(next_char = strtok(NULL, DELIMS)) != '5'){
            // Jump or no? 
            int next_river = atoi(next_char);
            printf("\nnext_river %d ",next_river);
            if (next_river % 2 == 0){
                direction += (flow == clockwise) ? 1 : 5;
                whitewater = (next_river == 2) ? 1 : 0;
            }
            else {
                river_edge.a = HexMovement(river_edge.a, direction, map);
                flow = (flow == clockwise) ? counter_clockwise : clockwise;
                direction += (flow == clockwise) ? 4 : 2;
                whitewater = (next_river == 3) ? 1 : 0;
            //river_edge.b  = HexMovement(river_edge.a, direction, map);
            }
            direction %= 6;
            river_edge.b = HexMovement(river_edge.a, direction, map);
            if (river_edge.b.col == -1 || river_edge.a.col == -1) {
              printf("River flows off map edge.\n");
              break;
            }
            // Update feature direction - need whitewater, direction, tile 1 and 2, clockwise
            place_river(river_edge, whitewater, direction, flow, map);
        }

    }
    return map;
}






void place_river(EDGE edge, int whitewater, int direction_from_a, int flow, MAP map){
        
    // printf("{%d,%d}{%d,%d}\n", edge.a.col, edge.a.row, edge.b.col, edge.b.row);
    char river_a = (flow == clockwise) ?  'a': 'b';
    char river_b = (flow == counter_clockwise) ? 'a' : 'b';
    river_a += whitewater*2;
    river_b += whitewater*2;
    printf("river_a %c, river_b %c", river_a, river_b);
    switch (direction_from_a % 6){
        case 0:
            (CoordToTile(edge.a, map))->north = river_a;
            (CoordToTile(edge.b, map))->south = river_b;
            break;
        case 1:
            (CoordToTile(edge.a, map))->north_east = river_a;
            (CoordToTile(edge.b, map))->south_west = river_b;
            break;
        case 2:
            (CoordToTile(edge.a, map))->south_east = river_a;
            (CoordToTile(edge.b, map))->north_west = river_b;
            break;
        case 3:
            (CoordToTile(edge.a, map))->south = river_a;
            (CoordToTile(edge.b, map))->north = river_b;
            break;
        case 4:
            (CoordToTile(edge.a, map))->south_west = river_a;
            (CoordToTile(edge.b, map))->north_east = river_b;
            break;
        case 5:
            (CoordToTile(edge.a, map))->north_west = river_a;
            (CoordToTile(edge.b, map))->south_east= river_b;
            break;
    }
}
/// @brief  Generates 2 random drones - Red drone and Blue drone using a random
///     number generation scheme that attempts to create two unique drones.
/// @param drone_1 
/// @param drone_2 
/// @param board_ptr  The starting tile of the map.
void RandomizeDrone(DRONE *drone_1, DRONE* drone_2, MAP map){
    time_t t;
    srand((unsigned) time(&t));
    int random1 = rand() % 65536;

    drone_1->Loc.col = (random1) % map.size.col;
    drone_1->Loc.row = (random1 / 10) %  map.size.row;
    drone_1->heading = random1 % 6;
    int tile_position = drone_1->Loc.col + (map.size.col * drone_1->Loc.row);

    int random2 = rand() % 131072;
    drone_2->Loc.col = (random2 / 10 ) % map.size.col;
    drone_2->Loc.row = random2 % map.size.row;
    drone_2->heading = (random2 /100) % 6;
    tile_position = drone_2->Loc.col + (map.size.col *drone_2->Loc.row);
}

/// @brief Calculates the elevation change between two tiles. If either Tile is 
///     NULL,returns -200
/// @param a 
/// @param b 
/// @return 
int ElevationChange(TILE *a, TILE *b){
    if (a == NULL || b == NULL)
        return -200;
    return b->height - a->height;
}

/// @brief This is intended to run every time the drone travels by "normal" 
///     means. Reports features after travel, so reported feature on opposite
///     side of the compass. (+3 direction)
/// @param global_direction Direction travelled
/// @param drone_offset     Used to convert to relative direction for reports
/// @param origin_height    Previous tile's height - needed to report Alt change
/// @param map_hex          Current map hex
/// @return 
int TravelReport(int global_direction, int drone_offset, int old_height, TILE *map_hex){
    char feature;
    if (map_hex == NULL){
        printf("OBSTRUCTION FOUND!! cannot proceed %s", 
                DIRECTION[(global_direction+drone_offset)%6]);
                return -1;
    }
    printf("\nDrone moves %s:\n", DIRECTION[(global_direction+6-drone_offset)%6]);

    printf("Altitude Change: %+d\n", map_hex->height - old_height);
    printf("Updated ");
    PrintBiomeCode(map_hex);
    
    if ('\0' != (feature = FeatureCheck((global_direction + 3) % 6, map_hex))){
        printf("Crossed ");
        PrintFeatures(global_direction + 6 - drone_offset + 3, feature);
    
    }
    return 0;
}