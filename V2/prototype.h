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
#include <ctype.h>

#define MAP_BUFFER 17

#define TOKENS 30
#define TOKEN_LENGTH 26
#define DELIMITERS "\040\n\t(){}[]<>;,./=+-!:?*"

#define FLUSH while( getchar()!= '\n')



typedef struct coords{
    int col, row;
} COORD;

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

typedef struct map
{
  TILE *start;
  COORD size;
}MAP;

typedef struct drone
{
  COORD Loc;
  int heading;
  //Other stuff
} DRONE;

typedef struct edge
{
  COORD a;
  COORD b;
} EDGE;

static COORD HEX_MOV[2][6]  = {
    //[0] = Even Row, [1] = Odd row
    //[0]=N, [1]=NE, [2]=SE, [3]=S, [4]=SW, [5]= NW
    { // Even rows
    {+1,  0}, { 0, +1}, {-1, +1}, {-1,  0}, {-1, -1}, { 0, -1} 
    },
    { // Odd rows
    {+1,  0}, {+1, +1}, { 0, +1}, {-1,  0}, { 0, -1}, {+1, -1},
    }
};
static char DIRECTION[6][12] = { "north", "north-east", "south-east", 
                            "south", "south-west", "north-west"};
static char BIOMES[7][9] = { "Blue", "Green", "Yellow", "Black", "White",
                             "Purple", "Orange" };
static char SHORE[2][7] = {" ", " shore"};

static char MOVEMENT_STEP[4][8] = {"explore", "ride", "plan", "abandon"};


// MAP build_map(FILE* in_fp);
MAP   build_map(FILE *elevation_fp, FILE *biome_fp, FILE *river_fp);
void  print_map(MAP map);
void  randomize_drone(DRONE *drone_1, DRONE *drone_2, MAP map);
void  print_tile(TILE* tile);
int   game_start(char type, MAP map, DRONE *red_drone, DRONE *blude_drone);
void  to_lower(char *to_lower);
int   rel_to_global(int rel, int heading);
int   global_to_rel(int global, int heading);
COORD hex_movement(COORD loc, int global_dir, MAP map);
int   input_direction(int heading);
int   _shore(int cur_biome, int new_biome);
int   report_elevation(TILE *current, TILE *next);
TILE* check_boundary(COORD coord, MAP map);
TILE* coord_to_tile(COORD coord, MAP map);
char  feature_check(int global_direction, TILE *map_hex);
void  print_features(int direction, char feature);
void  print_biome_code(TILE* tile);
void  survey(DRONE* drone, MAP map);
int   elevation_change(TILE *a, TILE *b);
int   travel_report(int global_direction, int drone_offset, 
                    int origin_height, TILE *map_hex);
int strategic_action();
int movement_action(DRONE* drone, MAP map);
int survey_action(DRONE* red_drone, DRONE* blue_drone, MAP map);
int Explore(DRONE *drone, MAP map);
int Abandon(DRONE *drone, MAP map);
int Ride(DRONE *drone, MAP map);
int Plan(DRONE *drone, MAP map);
int string_to_command(char *ptr);
#endif
