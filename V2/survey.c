#include "prototype.h"

// /// @brief Perform the Survey action, which will print a list of tile 
// ///     properties for the current tile, and it's surroundings.
// ///     Calls navigate_hex(), print_biome_code(), print_features() and 
// ///     elevation_change().
// ///     Indirectly calls print_edge()
// /// @param drone The Drone that is performing the survey
// /// @param map_start The start of the map - the "0th" tile
// void survey(DRONE* drone, MAP map){

//     char direction[6][12] = { "North:", "North-East:", "South-East:", 
//                             "South:", "South-West:", "North-West:"};
//     TILE *starting_tile = map.start + drone->Loc.col + (drone->Loc.row*map.size.col);
//     TILE *relative_tile = NULL;
//     int current_direction = drone->heading;
//     int height_difference;

//     printf("\nHere:               ");
//     print_biome_code(starting_tile);
//     printf("\n");

    
//     for (int i = 0; i < 6; i++){
//         // relative_tile = navigate_hex(current_direction + i, map.start, drone, 0);
//         relative_tile = (coord_to_tile(hex_movement(drone->Loc, current_direction + i, map), map));
//         printf("\nTo the %-13s", direction[i]);
//         if (relative_tile == NULL) {
//             printf("Map Edge.");
//             continue;
//         }
//         print_biome_code(relative_tile);
//         height_difference = elevation_change(starting_tile, relative_tile);
//         printf("%+d", height_difference);
//         if (height_difference > 2 || height_difference < -2)
//             printf(" Cliff!!");
//         if ((relative_tile->biome != starting_tile->biome )
//             && (relative_tile->biome == 0 || starting_tile->biome == 0))
//             printf(" Shore");
//         print_features(feature_check(current_direction + i, starting_tile),
//                         i);
//     }
// }


// /// @brief Prints the biome code for a given tile. If the tile is NULL prints 
// ///     Map Edge
// /// @param tile 
// /// @param drone 
// void print_biome_code(TILE* tile) {
//     if (tile == NULL) {
//         printf("Map Edge.\n");
//         return;
//     }
//     char biomes[7][9] = { "Blue", "Green", "Yellow", "Black", "White",
//                           "Purple", "Orange" };
//     printf("Biome code = %-10s ",biomes[tile->biome]);
// }


/// @brief Calculates the elevation change between two tiles. If either Tile is 
///     NULL,returns -200
/// @param a 
/// @param b 
/// @return 
int elevation_change(TILE *a, TILE *b){
    if (a == NULL || b == NULL)
        return -200;
    return b->height - a->height;
}


// /// @brief Print Features of the current tile in a given direction
// /// @param tile This is the Tile that the Drone is currently on
// /// @param global_direction This is the direction that the drone is currently 
// ///     looking. It will only print if there is a feature in that direction
// /// This Function does not detect emergent features like Coasts or Cliffs
// void print_features(int direction, char feature){
//     if (feature == '0')
//         return;
    
//     if (feature == 'A'|| feature == 'a' || feature == 'B' || feature == 'b')
//         printf(" a river flowing ");
//     else if(feature == 'C' ||feature == 'D' ||feature == 'c' ||feature == 'd')
//         printf(" whitewater flowing ");

//     // If the feature is counter-clockwise, rotate it by 3

//     if (feature == 'B' || feature == 'D' || feature == 'b' || feature == 'd' )
//         direction += 3;

//     direction %= 6;
//     // direction heading 4 - 
//     if (direction == 0)
//         printf("east");
//     if (direction == 1 || direction == 2)
//         printf("south");
//     if (direction == 3)
//         printf("west");
//     if (direction == 4 || direction == 5)
//         printf("north");
// }


// /// @brief  Checks to see if there is a feature in a direction.
// /// @param global_direction 
// /// @param map_hex 
// /// @return 
// char feature_check(int global_direction, TILE *map_hex){
//     switch (global_direction % 6){
//         case 0:
//             return map_hex->north;
//         case 1:
//             return map_hex->north_east;
//         case 2:
//             return map_hex->south_east;
//         case 3: 
//             return map_hex->south;
//         case 4: 
//             return map_hex->south_west;
//         case 5:
//             return map_hex->north_west;
//     }
// }
