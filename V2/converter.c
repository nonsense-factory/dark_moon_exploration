
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototype.h"

#define DELIMS "\040\n,"


// typedef struct coord{
//     int col;
//     int row;
// } COORD;

// typedef struct edge{
//     COORD a;
//     COORD b;
// } EDGE;

// typedef struct tile
// {
//   int height;
//   int biome;
//   char north;
//   char north_east;
//   char south_east;
//   char south;
//   char south_west;
//   char north_west;
// }TILE;

// typedef struct map{
//     TILE *start;
//     COORD size;
//     //EDGE **rivers; 
// } MAP;


void print_map(MAP map);
MAP build_map(FILE *elevation_fp, FILE *biome_fp, FILE *river_fp);
void place_river(EDGE edge, int whitewater, int direction_from_a, int flow, MAP map);

int main(int argc, char* argv[]){
    
    char filename[3][256] = {"elevation.csv", "biome.csv", "rivers.csv"};
    FILE *elevation_fp;
    FILE *biome_fp;
    FILE *river_fp;
    
    printf("Convert a bunch of excel spreadsheets into a map!");

    if (argc >= 2){
        for (int i = 1; i < argc; i++){
            strcpy(filename[0], argv[1]);
        }
    }

    if (argc > 2){
      printf("Error: Only use one file. Please try again.");
      printf("\n%s {map.txt} \n", argv[0]);
      exit(1);
    } 

    // Elevation file read
    if (!(elevation_fp = fopen(filename[0], "r"))) {
      printf("Error opening file \'%s\'\n\n", filename[0]);
      exit(1);
    }

    // Biome File Read    
    if (!(biome_fp = fopen(filename[1], "r"))) {
      printf("Error opening file \'%s\'\n\n", filename[1]);
      exit(1);
    }

    // River File Read
    if (!(river_fp = fopen(filename[2], "r"))) {
      printf("Error opening file \'%s\'\n\n", filename[2]);
      exit(1);
    }



    MAP map = build_map(elevation_fp, biome_fp, river_fp);

    fclose(elevation_fp);
    fclose(biome_fp);
    fclose(river_fp);


    printf("\n\n~~~~~~~~~~~~~PRINT_MAP~~~~~~~~~~~~~\n\n");
    print_map(map);

}

// TILE* coord_to_tile(COORD coord, MAP map){
//     return map.start + coord.col + coord.row * map.size.col;
// }

enum DroneDirection {North = 0, NorthEast = 1, SouthEast = 2, 
                   South = 3, SouthWest = 4, NorthWest = 5};
enum Clockedness   {clockwise = 1, counter_clockwise = -1};

void print_map(MAP map){
    TILE *tmp = map.start;
    printf("%d, %d\n", map.size.col, map.size.row);
    for(int i = 0; i < map.size.row;i++){
        for(int j = 0; j < map.size.col; j++){
            COORD where = {j, i};

            TILE *to_print = coord_to_tile(where, map);
            if (to_print != NULL) printf("{%2d,%2d}",to_print->height, to_print->biome );
        }
    printf("\n");
    }
    
}

// Read 3 files into a map program
MAP build_map(FILE *elevation_fp, FILE *biome_fp, FILE *river_fp){
        
    int buffer_size = 256;
    int num_cols = 0;
    int num_rows = 1;
    char buffer[3][256] = {"", "", ""};
    char *elevation, *biome;

    // Read the first line of the elevation file to find the size of the map
    elevation = fgets(buffer[0], buffer_size, elevation_fp);
    char *tok = strtok(elevation, DELIMS);
    num_cols = atoi(tok);
    printf("\n%d\n",num_cols);
    tok = strtok(NULL, DELIMS);
    num_rows = atoi(tok);
    printf("\n%d\n",num_rows);
    
    
    MAP map = {malloc(num_rows*num_cols*sizeof(TILE)), {num_cols, num_rows}};
    TILE *map_pointer = map.start;
    printf("Malloc successful \n");
    
    printf("\n\n~~~~~~~~~~~ELEVATION~~~~~~~~~~~~\n\n");
    // Do the elevation and biome files together
    for (int i = 0; i < num_rows; i++){
        COORD where = {0, i};
        elevation = fgets(buffer[0], buffer_size, elevation_fp);
        tok = strtok(elevation, DELIMS);
        int num = atoi(tok);
        (coord_to_tile(where, map))->height = atoi(tok);
        for (int j = 1; j < num_cols; j++){
            where.col = j;
            tok = strtok(NULL, DELIMS);
            (coord_to_tile(where, map))->height = atoi(tok);
        }
        // printf("\n")
    }

    printf("\n\n~~~~~~~~~~~~~BIOMES~~~~~~~~~~~~~\n\n");
    for (int i = 0; i < num_rows; i++){
        biome = fgets(buffer[1], buffer_size, biome_fp);
        tok = strtok(biome, DELIMS);
        COORD where = {0, i};
        int num = atoi(tok);
        (coord_to_tile(where, map))->biome = num;
        for (int j = 1; j < num_cols; j++){
            where.col = j;
            tok = strtok(NULL, DELIMS);
            num = atoi(tok);
            (coord_to_tile(where, map))->biome = num;
        }
    }
    
    printf("\n\n~~~~~~~~~~~~~RIVERS~~~~~~~~~~~~~\n\n");
    // Toss the first line of the river file
    char *river_ptr = fgets(buffer[2], buffer_size, river_fp);
    int num_rivers = atoi(strtok(buffer[2], DELIMS));
    printf("%d", num_rivers);
    // while(fgets(buffer[2], buffer_size, river_fp)){
    for(int k = 0; k < num_rivers; k++){
        fgets(river_ptr, buffer_size, river_fp);
        char *col = strtok(river_ptr, DELIMS);
        char *row = strtok(NULL, DELIMS);
        COORD river_start = {atoi(col), atoi(row)};
        enum DroneDirection direction = atoi(strtok(NULL, DELIMS));
        int file_flow = atoi(strtok(NULL, DELIMS));
        // Print the starting tile's coordinates
        printf("%d, %d - \n", river_start.col, river_start.row);

        enum Clockedness flow = (file_flow) ? clockwise: counter_clockwise;    
        int whitewater = 0 ;

        EDGE river_edge = {river_start, hex_movement(river_edge.a, direction, map)};

        place_river(river_edge, whitewater, direction, flow, map);

        char* next_char;
        // Main loop
        while (*(next_char = strtok(NULL, DELIMS)) != '5'){
            // Jump or no? 
            int next_river = atoi(next_char);
            if (next_river % 2 == 0){
                direction += (flow == clockwise) ? 1 : -1;
                whitewater = (next_river == 2) ? 1: 0;
                river_edge.b = hex_movement(river_edge.a, direction, map);
            }
            else {
                river_edge.a = hex_movement(river_edge.a, direction, map);
                direction += (flow == clockwise) ? 4 : 2;
                whitewater = (next_river == 4) ? 1 : 0;
                river_edge.b  = hex_movement(river_edge.a, direction, map);
            }
            
            place_river(river_edge, whitewater, direction, flow, map);
            }
            // Update feature direction - need whitewater, direction, tile 1 and 2, clockwise

        }
    
    return map;
    }






void place_river(EDGE edge, int whitewater, int direction_from_a, int flow, MAP map){
        
    printf("{%d,%d}{%d,%d}\n", edge.a.col, edge.a.row, edge.b.col, edge.b.row);
    char river_a = (flow == clockwise) ?  'a': 'b';
    river_a += (whitewater) ? 2 : 0;
    switch (direction_from_a % 6){
        case 0:
            (coord_to_tile(edge.a, map))->north = river_a;
            (coord_to_tile(edge.b, map))->south = river_a + flow;
            break;
        case 1:
            (coord_to_tile(edge.a, map))->north_east = river_a;
            (coord_to_tile(edge.b, map))->south_west = river_a + flow;
            break;
        case 2:
            (coord_to_tile(edge.a, map))->south_east = river_a;
            (coord_to_tile(edge.b, map))->north_west = river_a + flow;
            break;
        case 3:
            (coord_to_tile(edge.a, map))->south = river_a;
            (coord_to_tile(edge.b, map))->north = river_a + flow;
            break;
        case 4:
            (coord_to_tile(edge.a, map))->south_west = river_a;
            (coord_to_tile(edge.b, map))->north_east = river_a + flow;
            break;
        case 5:
            (coord_to_tile(edge.a, map))->north_west = river_a;
            (coord_to_tile(edge.b, map))->south_east= river_a + flow;
            break;
    }
}