// startup.c
#include "prototype.h"


int main(int argc, char* argv[]){

    
    char filename[3][256] = {"elevation.csv", "biome.csv", "rivers.csv"};
    FILE *elevation_fp;
    FILE *biome_fp;
    FILE *river_fp;
    
    // printf("Convert a bunch of excel spreadsheets into a map!");

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



    MAP map = BuildMap(elevation_fp, biome_fp, river_fp);

    fclose(elevation_fp);
    fclose(biome_fp);
    fclose(river_fp);

    DRONE drone_1, drone_2;
    // RandomizeDrone(&drone_1, &drone_2, map);
    drone_1.Loc.col = 9;
    drone_1.Loc.row = 7;
    drone_1.heading = 0;
    drone_1.turn_count = 0;
    drone_2.Loc.col = 4;
    drone_2.Loc.row = 5;
    drone_2.heading = 1;
    drone_2.turn_count = 0;
    // drone_1.Loc.c = 7;
    // drone_1.Loc.r = 7;
    // PrintMap(map);
    GameStart(1, map, &drone_1, &drone_2);

    // printf("\n\n~~~~~~~~~~~~~PRINT_MAP~~~~~~~~~~~~~\n\n");

}

