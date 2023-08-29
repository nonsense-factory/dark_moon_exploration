#include "prototype.h"

int  _convert_input(char *text);
void _to_lower(char *to_lower);


void survey(DRONE *drone, MAP map){
    TILE *current_tile = coord_to_tile(drone->Loc, map);    
    int glob_dir; 
    TILE *next_tile = NULL;
        
    // survey here:
    print_biome_code(current_tile);
    printf("\n{%d, %d}\n", drone->Loc.col, drone->Loc.row);
    // survey surroundings
    for (int rel_dir = 0; rel_dir < 6; rel_dir++){
        printf("To the %-12s: ", DIRECTION[rel_dir]);
        
        // check that tile is within the map
        glob_dir = rel_to_global(rel_dir, drone->heading);
        next_tile = check_boundary(hex_movement(drone->Loc, glob_dir, map), map);
        if (next_tile == NULL){
            printf("Map edge...\n");
            continue;
        }
        // Print data for tile
        print_biome_code(next_tile);
        report_elevation(current_tile, next_tile);
        printf("%s",SHORE[_shore(current_tile->biome, next_tile->biome)]);
        printf("/%c/ ", feature_check(glob_dir, current_tile));
        print_features(rel_dir, feature_check(glob_dir, current_tile));
        printf("\n");

    }
}

// Convert coordinates to a tile
TILE* coord_to_tile(COORD coord, MAP map ){
    if(coord.col == -1 || coord.row == -1)
        return NULL;
    return map.start + coord.col + (coord.row*map.size.col);
}

// Prints the elevation change, and reports if it's a cliff - Possibly refactor?
int report_elevation(TILE *current, TILE *next){
    int change = next->height - current->height;
    printf("%+d ", change);
    if (change < -2 || change > 2)
        printf("Cliff!!");
    return change;
}

// Checks to see if a coordinate is within the playable area
TILE* check_boundary(COORD coord, MAP map){
    if (coord.col == -1 || coord.row == -1)
        return NULL;
    return map.start + coord.col + (coord.row*map.size.col);
}

// Checks if an edge is a shore
int _shore(int cur_biome, int new_biome){
    return (cur_biome != 0 && new_biome == 0) 
        || (cur_biome == 0 && new_biome != 0 ) ? 1 : 0;
}

// Converts text to lower case
void _to_lower(char *to_lower){
    char *tmp = to_lower;
    while(*(tmp) != '\040' && *(tmp) != '\n' && *(tmp) != '\0')
        *(tmp++) |=  '\040'; 
}

// Game Entry Point and Main loop:
int game_start(char game_type, MAP map, DRONE *red_drone, DRONE *blue_drone){
    printf("Game begins\n\n");
    int fun = 1;
    int turn = 0;
    // Main Game loop - One turn per loop:    
    do {
        turn++;
        fun = strategic_action();
	if (fun == 0) continue;
        fun = movement_action(red_drone, map);
	if (fun == 0) continue;
        fun = survey_action(red_drone, blue_drone, map);        
    } while (fun);
    return fun;
}



/// @brief Returns the coordinates of the hex in a given direction, gives 
///     invalid coord if the move would place the hex off the board.
/// @param loc  - Current Location
/// @param global_dir  - Direction to move, given from the global perspective
/// @return 
COORD hex_movement(COORD loc, int global_dir, MAP map){
    int parity = loc.row & 1;
    COORD dir = HEX_MOV[parity][global_dir % 6];
    COORD result = {loc.col+ dir.col, loc.row + dir.row};
    if (result.col< 0 || result.row < 0 
     || result.col>= map.size.col|| result.row >= map.size.row){
        result.col= -1,
        result.row = -1;
    }
    return result;
}

//Points that use the relative direction:
// Translates relative direction to global direction and back. 
int rel_to_global(int rel, int heading){
    return (rel + 6 - heading) % 6; 
}
int global_to_rel(int global, int heading){
    return (global + heading) % 6;
}


// Takes 2 characters of input from a user and converts it into a cardinal 
//  direction (N, NE, SE, S, SW, NW,)
int input_direction(int heading){
    char input[3] = "";
    char *input_pointer = input;
    int invalid = 2;
    int direction;
    do {
        if (invalid != 2){
            printf("Invalid command! Please try again.\n");
        }
        fgets(input_pointer, 3, stdin);
        if(*input == '\n'){
            printf("Error! No input detected please try again\n");
            continue;
        }

        _to_lower(input_pointer);
        if(*input_pointer == 'x') {
            direction = -1;
            break; 
        }
        direction = rel_to_global(_convert_input(input_pointer), heading);
        invalid = (!(direction >= 0 && direction <6));
    }while (invalid);

    return direction;
}

// Converts simple input from cardinal initials to directional number
// + Flushes the input buffer for the 2 char strings. 
int _convert_input(char *text){
    _to_lower(text);
    if (*text == 'x'){
        return -1;
    }
    char cmp[6][3] = { "n\n", "ne", "se", "s\n", "sw", "nw"};
    for (int i = 0; i < 6; i++){
        if (strcmp(text, cmp[i]) == 0){
            if (i != 0 && i != 3) FLUSH; 
            return i;
        }
    }
    return -10;
}

/// @brief Prints the biome code for a given tile with consistant formatting.
/// @param tile 
void print_biome_code(TILE* tile) {
    printf("Biome code = %-10s ",BIOMES[tile->biome]);
}

/// @brief Print Features of the current tile in a given direction
/// @param direction This is the direction that the drone is currently 
///     looking. It will only print if there is a feature in that direction
/// @param feature  This takes a feature key, example: a, b, c or d for rivers
/// This Function does not detect emergent features like Coasts or Cliffs
void print_features(int direction, char feature){
    if (feature == '\0' || feature == '0')
        return;

    feature = tolower(feature);
    if (feature == 'a' || feature == 'b')
        printf(" a river flowing ");
    else if(feature == 'c' ||feature == 'd')
        printf(" whitewater flowing ");

    // If the feature is counter-clockwise, rotate it by 3

    if (feature == 'b' || feature == 'd' )
        direction += 3;

    direction %= 6;
    // direction heading 4 - 
    if (direction == 0)
        printf("east");
    if (direction == 1 || direction == 2)
        printf("south");
    if (direction == 3)
        printf("west");
    if (direction == 4 || direction == 5)
        printf("north");
}


/// @brief  Checks to see if there is a feature in a direction.
/// @param global_direction 
/// @param map_hex 
/// @return 
char feature_check(int global_direction, TILE *map_hex){
    switch (global_direction % 6){
        case 0:
            return map_hex->north;
        case 1:
            return map_hex->north_east;
        case 2:
            return map_hex->south_east;
        case 3: 
            return map_hex->south;
        case 4: 
            return map_hex->south_west;
        case 5:
            return map_hex->north_west;
        default:
          return '0';

    }
}


int strategic_action(){
  return 1;
};


int movement_action(DRONE* drone ,MAP map){
    int (*movement[])(DRONE*, MAP) = {Explore, Plan, Ride, Abandon};
    char command_str[40];
    char *command_ptr = command_str;

    printf("Drone locomotion initialized ... enter command # ");
    fgets(command_ptr, 39, stdin);
    command_ptr = strtok(command_ptr, DELIMITERS);
    _to_lower(command_ptr);
    int command = string_to_command(command_ptr);

    int abandon = (*movement[command])(drone, map);    
    if (abandon == -1)
        return 0;

    return 1;
};

int string_to_command(char *ptr){
    for (int i = 0; i< 4; i++){
        if(strcmp(ptr, MOVEMENT_STEP[i]) == 0)
            return i;
    }
    return -1;
}

int survey_action(DRONE *red_drone, DRONE *blue_drone, MAP map){
    printf("Survey Action Begin: \n");
    survey(red_drone, map);
    // suvey(blue_drone, map);
    return 1;
};
  
int Plan(DRONE *drone, MAP map){

}
int Ride(DRONE *drone, MAP map){

}
int Explore(DRONE *drone, MAP map) {
    TILE *next = NULL;
    int glob_dir[6] = {-1,-1,-1,-1,-1,-1};
    int i = 0;

    printf("User input\n");
    for (int i = 0; i < 6; i++){
        glob_dir[i] = input_direction(drone->heading);
        if (glob_dir[i] == -1)
            break;
    }    
    printf("input complete\n");

    for (int i = 0; i < 6; i++){
        int old_height = (coord_to_tile(drone->Loc, map))->height;
        if (glob_dir[i] == -1)
            break;
        COORD move = hex_movement(drone->Loc, glob_dir[i], map);
        if (move.col== -1 || move.row == -1){
            printf("Map edge...\n");
            break;
        }
        
        drone->Loc.col = move.col;
        drone->Loc.row = move.row;

        travel_report(glob_dir[i], drone->heading, old_height, coord_to_tile(move, map));
        printf("\n");
    }
    return 1;
};

int Abandon(DRONE *drone, MAP map){
    printf("Mission failed. post mission analysis and debriefing to follow.");
    return -1;
}
