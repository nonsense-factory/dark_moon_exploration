#include "prototype.h"



#define INPUT_BUFFER 81
#define FLUSH while( getchar()!= '\n')

// _ indicates local to this translation unit. These functions cannot be called
//      from other files
int _movement(DRONE *drone, TILE *map);
int _tokenize(char* string, char (*list)[TOKENS][TOKEN_LENGTH]);
int _travel_report(int global_direction, int drone_offset, int origin_height, TILE *map_hex);
int _river_crossing(int global_direction, int drone_offset, TILE *map_hex);
int _get_action(char (*command));
int _explore(int nume_directions, char (*move)[TOKEN_LENGTH], DRONE *drone, TILE *map);
int _convert_input(char *text);


int game_start(TILE *map, DRONE *red_drone, DRONE *blue_drone){
    //Main Input loop - "exit" to quit
    
    int valid = -1;
    printf(" (%d, %d), %d", red_drone->Loc.c, red_drone->Loc.r, red_drone->heading);
    survey(red_drone, map);
    printf("\n");
    
    int finish = 1;
    survey(blue_drone, map);
    while (finish){
        valid = -1;
        printf("\n\n");
        while (valid == -1){
            valid = _movement(blue_drone, map);
            if (valid == -10)
                return -1;
        } 

        survey(blue_drone, map);

        if (blue_drone->Loc.c == red_drone->Loc.c 
         && blue_drone->Loc.r == red_drone->Loc.r)
            finish = 0;
    }

}



int _movement(DRONE *drone, TILE *map){
    char buffer[INPUT_BUFFER] = {""};
    char input[TOKENS][TOKEN_LENGTH];
    char *input_ptr = buffer;    
    int invalid = 1;
    int num_tokens = 0;
    int steps_taken;
    


    do { // Keep looping until valid input or quit
        printf("Please enter instructions for Movement: ");
        fgets(input_ptr, INPUT_BUFFER, stdin);
        // FLUSH;
        if (*input_ptr == '\n'){
            printf("Error! No input detected please try again\n");
            continue;
        }
        //Moke tokens of the input
        num_tokens = _tokenize(input_ptr,&input);
        if (num_tokens == 0)
            continue;

        // do stuff!
        int command = _get_action(input[0]);
        if (command == -1){
            printf("Invalid command! Please try again.\n");
            continue;
        }
        if (command == 0){
            steps_taken = _explore(num_tokens - 1, (input + TOKEN_LENGTH), drone, map);
            printf("\n");
        }
        if (command == 5)
            return -10;
        else if (command == 1){
            break;
        }


        invalid = 0;
    } while(invalid);

    return 0;
}


int _tokenize(char* string, char (*list)[TOKENS][TOKEN_LENGTH]){
    int num_tokens = 0;
    char* copy = **(list);
    
    // create the first token from the string pointer
    char* token = strtok(string, DELIMITERS); 
    do{
        // if token too long - maybe not the best solution. 
        if ((strlen(token) > TOKEN_LENGTH - 1)){
            printf("Error - Message too long. Retry: ");
            *copy = '\7';
            copy += TOKEN_LENGTH;
            continue;
        }
        strcpy(copy, token);
        copy += TOKEN_LENGTH;
        num_tokens++;
    } while ((token = strtok(NULL, DELIMITERS) ));// As long as strtok continues
                                                  // to create tokens
    return num_tokens;
}


/// @brief This is intended to run every time the drone travels by "normal" 
///     means. Reports features after travel, so reported feature on opposite
///     side of the compass. (+3 direction)
/// @param global_direction Direction travelled
/// @param drone_offset     Used to convert to relative direction for reports
/// @param origin_height    Previous tile's height - needed to report Alt change
/// @param map_hex          Current map hex
/// @return 
int _travel_report(int global_direction, int drone_offset, 
                    int origin_height, TILE *map_hex){
    char direction[6][12] = { "North", "North-East", "South-East", 
                            "South", "South-West", "North-West"};
    char feature;
    if (map_hex == NULL){
        printf("OBSTRUCTION FOUND!! cannot proceed %s", 
                direction[(global_direction+drone_offset)%6]);
                return -1;
    }
    printf("Drone moves %s:\n", direction[(global_direction+6-drone_offset)%6]);
    printf("Altitude Change: %+d\n", map_hex->height - origin_height);
    printf("Updated ");
    print_biome_code(map_hex);
    printf("\n");
    if ('0' != (feature = feature_check((global_direction + 3) % 6, map_hex))){
        printf("Crossed");
        print_features(feature, global_direction + 6 - drone_offset + 3);
        printf("\n");
    }
}


void to_lower(char *to_lower){
    char *tmp = to_lower;
    while(*(tmp) != '\040' && *(tmp) != '\n' && *(tmp) != '\0')
        *(tmp++) |=  '\040'; 
}

int _get_action(char *command){
    to_lower(command);
    // printf("%s", command);
    char list_of_valid_commands[6][17] = 
        {"explore",
         "plan",
         "planned movement",
         "ride", 
         "river ride",
         "exit"
        };
    for (int i = 0; i < 6; i++){

        int found; 
        if ((found = strcmp(command, list_of_valid_commands[i])) == 0)
            return i;
    }
    return -1;
      

}
    // Explore - enter. The bot confirms it will explore and prompts for directions. The player enters a direction 
    //  (N/NE/SE/S/SW/SE) which the bot accepts (if it is valid, but if there is a typo it rejects the input throws it 
    //  out and prompts again) then it repeats the prompt for as many directions as the player cares to enter until they 
    //  enter STOP. You can put as many directions as you want but the drone won’t be able to use all of them. The 
    //  maximum explore distance is 3, but there are some other factors that influence this. Each direction is a “step”,
    //  so if you say “Explore. N. NE. N. STOP.” the drone goes to its north, then its northeast, then its north again.
int _explore(int num_directions, char (*move)[TOKEN_LENGTH], DRONE *drone, TILE *map){
    int valid = 1;
    char input[4] = "";
    int directions[6] = {-1, -1, -1, -1, -1, -1};
    int counter = 0;

    printf("Enter exploration steps using the cardinal directions N, NE, SE, S, SW, NW. x to end.\n");

    do{
        printf("Enter direction: ");
        fgets(input, 3, stdin);
        if (*input == '\n'){
            printf("Error! No input detected please try again\n");
            continue;
        }
        directions[counter] = _convert_input(input);
        if (directions[counter] == -10)  {
            printf("Invalid direction, please try again.\n");
            continue;
        } 
        if(directions[counter] ==  -1)
            break;
        counter++;
    }while(counter < 6);


    if (counter == 6){
        printf("\nError! Cannot accept additional exploration steps.\n"); 
        printf("Memory utilization exceeds safety threshold.\n\n");
    }
    
    printf("Executing expoloration. . . \n\n");
    TILE *current_tile = map + (drone->Loc.c) + (drone->Loc.r * PLAY_MAP_COLUMNS);
    for (int i = 0; i < 6; i++){
        if (directions[i] == -1)
            break;
        int global_direction = directions[i] + drone->heading;
        printf("%d %d \n", global_direction, drone->heading);
        COORD candidate = hex_movement(drone->Loc, global_direction);
        if (candidate.c == -1) {
            printf("Map edge - area beyond this point outside of mission parameters."); 
            break;
        }
        TILE *new_tile = map + candidate.c + (candidate.r*PLAY_MAP_COLUMNS);
        int height_difference = new_tile->height - current_tile->height;
        if (height_difference > 2 || height_difference < -2) {
            printf("\nObstruction detected - Cliff. Stopping all movement.");
            break;
        }

        _travel_report(global_direction, drone->heading, current_tile->height, new_tile); 
        
    }
}

int _convert_input(char *text){

        to_lower(text);
        if (*text == 'x'){
            return -1;
        }
        if (strcmp(text, "n\n") == 0){
            return 0;
        }
        if (strcmp(text, "ne") == 0){
            FLUSH;
            return 1;
        }
        if (strcmp(text, "se") == 0){
            FLUSH;
            return 2;
        }
        if (strcmp(text, "s\n") == 0){
            return 3;
        }
        if (strcmp(text, "sw") == 0){
            FLUSH;
            return 4;
        }
        if (strcmp(text, "nw") == 0){
            FLUSH;
            return 5;
        }
        
            return -10;
            
        


}



    
    // Ride - enter. Then input a direction (N/NE/SE/S/SW/SE). this tells the drone to look at the river that borders 
    //  its current hex in the indicated direction and then do a river ride, which will sweep it along the path of the 
    //  river.
    //  This form of travel ignores all obstructions other than the map edge; if this movement tries to cross a map edge, end the movement.
    //  If the river being ridden terminates at a blue hex along the route, the drone gets dumped into the blue hex and ends movement there.
    //      Player Procedure
    //          1: Declare a river ride
    //          2: Select which edge of your hex contains the river you want to ride (whitewater included). 
    //          3: Declare whether you want to cross the river during the movement or not (end on the near side or far side of the river).

    //      Cartographer Procedure
    //          1: Make sure the players have given a valid instruction. If there is no river on the edge they target, this movement option fails, and the drone doesn’t move this turn. (That being said, you can clarify directions if they make an honest mistake and you feel generous). 
    //          2: Move the player drone 5 steps down the river, sliding the drone alongside the river so that the drone only moves via hexes that are bordered by that river on one or more edge. Make a travel report for step. 
    //          3: If any of the ridden river’s edges are whitewater on a hex that the drone moves into, the cartographer simply adds “whitewater” to the travel report, and the step costs 0. The players do not learn specifically which edges of that hex are whitewater, only that at least one of them is. 
    //          4: Once you have expended the 5 steps of travel, then:
    //          5: If the players decided to cross the river, take a 6th step of movement to move directly across the furthest downriver edge of the ridden river on their current hex (even if it is whitewater).
    //          6: If the players decided not to cross the river, take a 6th step downriver just like the other 5.


    
    // Plan - enter. Plan will then prompt the player for their first step, for which they ust enter a direction, 
    //  followed by an elevation change, followed by a color, separated by commas (NE, +1, Yellow) for example. If they 
    //  are right, the bot moves into the given space and you repeat this step until the players give a wrong command or
    //  a STOP. 
    // {
    //     printf("Planned Travel. \"Execute\" to begin movement.");
    //     printf("\nDirection entered as as {Direction, alt change, biome code}")
    // }