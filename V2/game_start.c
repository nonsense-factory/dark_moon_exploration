#include "prototype.h"

//Points that use the relative direction:
// Translates relative direction to global direction and back. 
int rel_to_global(int rel, int heading){
    return (rel + 6 - heading) % 6; 
}

int global_to_rel(int global, int heading){
    return (global + heading) % 6;
}

int input_direction(int heading){
    char input[3] = "";
    int invalid = 1;
    int direction;
    do {
        fgets(&input, 3, stdin);
        if(input == '\n'){
            printf("Error! No input detected please try again\n");
            continue;
        }

        to_lower(&input);
        direction = rel_to_global(_convert_input(&input), heading);
        invalid = (direction >= 0 && direction <6);
    }while (invalid);

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

/// @brief Print Features of the current tile in a given direction
/// @param tile This is the Tile that the Drone is currently on
/// @param global_direction This is the direction that the drone is currently 
///     looking. It will only print if there is a feature in that direction
/// This Function does not detect emergent features like Coasts or Cliffs
void print_features(int direction, char feature){
    if (feature == '0')
        return;
    
    if (feature == 'A'|| feature == 'a' || feature == 'B' || feature == 'b')
        printf(" a river flowing ");
    else if(feature == 'C' ||feature == 'D' ||feature == 'c' ||feature == 'd')
        printf(" whitewater flowing ");

    // If the feature is counter-clockwise, rotate it by 3

    if (feature == 'B' || feature == 'D' || feature == 'b' || feature == 'd' )
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
    }
}
