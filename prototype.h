#ifndef PROTOTYPE_HEADER_FILE
#define PROTOTYPE_HEADER_FILE
// Dark Moon Exploration 
// Written by Ricky Barbieri
// Programming by Alex Barbieri
// This is a header file. It contains the structs for the board and the drones
// and function declarations. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAY_MAP_ROWS 10
#define PLAY_MAP_COLUMNS 10
#define MAP_BUFFER 17

#define TOKENS 30
#define TOKEN_LENGTH 26
#define DELIMITERS "\040\n\t(){}[]<>;,./=+-!:?*"

typedef struct tile
{
  int height;
  int biome;
  char north;
  char north_east;
  char south_east;
  char south;
  char south_west;
  char north_west;
}TILE;

typedef struct drone
{
  int column;
  int row;
  int heading;
} DRONE;

int build_map(FILE* in_fp, TILE* board_ptr);
void randomize_drone(DRONE *drone_1, DRONE *drone_2, TILE *board_ptr);
void print_tile(TILE* tile);
void print_tile(TILE* tile);
void print_features(char feature, int direction);
void print_edge(char a);
void survey(DRONE* drone, TILE *map);
void print_biome_code(TILE* tile);
int elevation_change(TILE *a, TILE *b);
int game_start(TILE *map, DRONE *red_drone, DRONE *blude_drone);
char feature_check(int global_direction, TILE *map_hex);
TILE* navigate_hex(int direction, TILE *map_start, DRONE *drone, int move);
void to_lower(char *to_lower);


#endif

