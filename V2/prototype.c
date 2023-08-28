#include "prototype.h"

MAP build_map(FILE *in_fp);
//void tile_survey(int num, DRONE* drone,  TILE *tile);
//
//void odd_row_survey(DRONE *drone, TILE *map);
//void even_row_survey(DRONE *drone, TILE *map);

int main(int argc, char *argv[]){
    char filename[256] = "the_map.txt";
    FILE *in_fp;
    DRONE drone_1 = {{0, 0}, 0};
    DRONE drone_2 = {{0, 0}, 0};

    printf("\nBuilding the Moon.\n");

    if (argc == 2){
        strcpy(filename, argv[1]);
    }
    if (argc > 2){
      printf("Error: Only use one file. Please try again.");
      printf("\n%s {map.txt} \n", argv[0]);
      exit(1);
    } 

    if (!(in_fp = fopen(filename, "r"))) {
      printf("Error opening file \'%s\'\n\n", argv[1]);
      exit(1);
    }

    MAP map = build_map(in_fp);
    
    fclose(in_fp);

    printf("Success!\n");
    // Generate 2 random starting positions:     
    randomize_drone(&drone_1, &drone_2, map);

    // drone_1.Loc.c = 7;
    // drone_1.Loc.r = 7;
    game_start(1, map, &drone_1, &drone_2);

    printf("Press any key to exit ...");
    getchar();
    free(map.start);
    return 0;
}


// /// @brief  Just about as simple as I could make it. Reads a standard format
// ///     10X10 hex grid from a file. 
// /// @param in_fp    
// /// @param board_ptr 
// /// @return 1 = success 0 = failure ... Not implemented yet
// MAP build_map(FILE *in_fp){
//     MAP new_map;
//     char rawbuffer[MAP_BUFFER+1] = "";
//     char *buffer = rawbuffer; 
//     int line = 0;

//     fgets (buffer, MAP_BUFFER, in_fp); 
//     new_map.size.col = atoi(strtok(buffer, ",\040"));
//     new_map.size.row = atoi(strtok(buffer, "\n\040"));
//     printf("%d %d \n",new_map.size.col, new_map.size.row);

//     new_map.start = (TILE*)malloc((new_map.size.col*new_map.size.row)* sizeof(TILE));
//     //
//     TILE *tmp = new_map.start;
//     for (line; line < new_map.size.col * new_map.size.row; line++){

//         fgets(buffer, MAP_BUFFER, in_fp);
//         tmp = new_map.start + line;
//         // DATA structure update next
//         tmp->height       =  *buffer - 48;
//         tmp->biome        =  *(buffer + 2) - 48;
//         tmp->south        =  *(buffer + 4);
//         tmp->south_west   =  *(buffer + 6);
//         tmp->north_west   =  *(buffer + 8);
//         tmp->north        =  *(buffer + 10);
//         tmp->north_east   =  *(buffer + 12);
//         tmp->south_east   =  *(buffer + 14);
//         buffer = rawbuffer;
//         // printf("%d: ", line);
//         // print_tile(tmp);
//         // line++;
//     // }
//     }

//     return new_map;
// }


/// @brief  For troubleshooting. Prints the untranslated properties of the tile
/// @param tile 
void print_tile(TILE *tile){
    
    printf("%d,%d,", tile->height, tile->biome);      
    printf("%c,%c,", tile->north, tile->north_east); 
    printf("%c,%c,", tile->south_east, tile->south);
    printf("%c,%c\n", tile->south_west, tile->north_west);

}


/// @brief  Generates 2 random drones - Red drone and Blue drone using a random
///     number generation scheme that attempts to create two unique drones.
/// @param drone_1 
/// @param drone_2 
/// @param board_ptr  The starting tile of the map.
void randomize_drone(DRONE *drone_1, DRONE* drone_2, MAP map){
    time_t t;
    srand((unsigned) time(&t));
    int random1 = rand() % 65536;
    drone_1->Loc.col = (random1) % map.size.col;
    drone_1->Loc.row = (random1 / 10) %  map.size.row;
    drone_1->heading = random1 % 6;
    
    int random2 = rand() % 131072;
    drone_2->Loc.col = (random2 / 10 ) % map.size.col;
    drone_2->Loc.row = random2 % map.size.row;
    drone_2->heading = (random2 /100) % 6;

}
