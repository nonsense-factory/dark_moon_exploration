#include "prototype.h"

int build_map(FILE *in_fp, TILE *board_ptr);
//void tile_survey(int num, DRONE* drone,  TILE *tile);
//
//void odd_row_survey(DRONE *drone, TILE *map);
//void even_row_survey(DRONE *drone, TILE *map);

int main(int argc, char *argv[]){
    char filename[256] = "the_map.txt";
    FILE *in_fp;
    TILE map_board[PLAY_MAP_COLUMNS * PLAY_MAP_ROWS];
    TILE *board_ptr = map_board;
    DRONE drone_1 = {0, 0, 0};
    DRONE drone_2 = {0, 0, 0};

    printf("\nBuilding the Moon.\n");

    if (argc == 2){
        strcpy(filename, argv[1]);
    }
    if (argc > 2){
      printf("Error: Only use one file. Please try again.");
      printf("\n%s {File_Name.c} {Outputfile.txt}\n", argv[0]);
      exit(1);
    } 

    if (!(in_fp = fopen(filename, "r"))) {
      printf("Error opening file \'%s\'\n\n", argv[1]);
      exit(1);
    }

    build_map(in_fp, board_ptr);
    
    fclose(in_fp);

    // Generate 2 random starting positions:     
    randomize_drone(&drone_1, &drone_2, board_ptr);

    game_start(board_ptr, &drone_1, &drone_2);

    printf("Press any key to exit ...");
    getchar();
    return 0;
}


/// @brief  Just about as simple as I could make it. Reads a standard format
///     10X10 hex grid from a file. 
/// @param in_fp    
/// @param board_ptr 
/// @return 1 = success 0 = failure ... Not implemented yet
int build_map(FILE *in_fp, TILE *board_ptr){
    char rawbuffer[MAP_BUFFER+1] = "";
    char *buffer = rawbuffer; 
    TILE * tmp = board_ptr;
    int line = 0;
    //fgets (buffer, MAP_BUFFER, in_fp);
    //
    while (fgets(buffer, MAP_BUFFER, in_fp)){
    // This is a bad way to do this.
        tmp->height       =  *buffer - 48;
        tmp->biome        =  *(buffer + 2) - 48;
        tmp->south        =  *(buffer + 4);
        tmp->south_west   =  *(buffer + 6);
        tmp->north_west   =  *(buffer + 8);
        tmp->north        =  *(buffer + 10);
        tmp->north_east   =  *(buffer + 12);
        tmp->south_east   =  *(buffer + 14);
        buffer = rawbuffer;
        // print_tile(tmp);
        // printf("%d\n", tmp->biome);
        tmp += 1;
    }
    return 1;
}


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
void randomize_drone(DRONE *drone_1, DRONE* drone_2, TILE *board_ptr){
    time_t t;
    srand((unsigned) time(&t));
    int random1 = rand() % 65536;

    drone_1->column = (random1) % PLAY_MAP_COLUMNS;
    drone_1->row = (random1 / 10) %  PLAY_MAP_ROWS;
    drone_1->heading = random1 % 6;
    int tile_position = drone_1->column + (PLAY_MAP_COLUMNS * drone_1->row);

    int random2 = rand() % 131072;
    drone_2->column = (random2 / 10 ) % PLAY_MAP_COLUMNS;
    drone_2->row = random2 % PLAY_MAP_ROWS;
    drone_2->heading = (random2 /100) % 6;
    tile_position = drone_2->column + (PLAY_MAP_COLUMNS *drone_2->row);
}
