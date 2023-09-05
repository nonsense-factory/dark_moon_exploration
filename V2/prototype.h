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
  short turn_count;
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

static char DRONE_NAME[2][5] = { "Red", "Blue" };


// MAP build_map(FILE* in_fp);
MAP   BuildMap(FILE *elevation_fp, FILE *biome_fp, FILE *river_fp);
void  PrintMap(MAP map);
void  RandomizeDrone(DRONE *drone_1, DRONE *drone_2, MAP map);
// void  PrintTile(TILE* tile); // < - Unused
int   GameStart(char type, MAP map, DRONE *red_drone, DRONE *blude_drone);
void  StrToLower(char *to_lower);
int   RelToGlobal(int rel, int heading);
int   GlobalToRel(int global, int heading);
COORD HexMovement(COORD loc, int global_dir, MAP map);
int   InputDirection(int heading);
int   ShoreStr(int cur_biome, int new_biome);
int   ReportElevation(TILE *current, TILE *next);
TILE* CheckBoundary(COORD coord, MAP map);
TILE* CoordToTile(COORD coord, MAP map);
char  FeatureCheck(int global_direction, TILE *map_hex);
void  PrintFeatures(int direction, char feature);
void  PrintBiomeCode(TILE* tile);
void  Survey(DRONE* drone, MAP map);
int   ElevationChange(TILE *a, TILE *b);
int   TravelReport(int global_direction, int drone_offset,
                    int old_height, TILE *map_hex);
int   StrategicAction();
int   MovementAction(DRONE* drone, MAP map);
int   SurveyAction(int id, DRONE* drone, MAP map);
int   Explore(DRONE *drone, MAP map);
int   Abandon(DRONE *drone, MAP map);
int   Ride(DRONE *drone, MAP map);
int   Plan(DRONE *drone, MAP map);
int   StringToCommand(char *ptr);
TILE* DroneTravel(int dir, DRONE* drone, MAP map);
int   IsImpassibleShore(TILE *prev, TILE *next);
#endif