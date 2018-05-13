/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 27/04/2018
 */

/**
 * @file testDriver.c
 * @brief Driver test file
 */


#include "../../include/driver/driver.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE* info;

void debug_print(char* text){
    fprintf(info, text);
    fflush(info);
}


void readDatas(){
    char c;
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n');
}


int main(){

    map* map = NULL;
    car* car = NULL;
    vector acceleration;

    position mapSize;
    int fuel;
    int tour = 1;
 
    int verifyPosition;

    info = fopen("ecto1/etc/testDriver.log", "w");
    debug_print("=====> START TESTDRIVER <=====\n");

    initGame(&mapSize, &fuel);
    fprintf(info, " ---> INIT GAME DONE (x : %d, y : %d, fuel : %d) \n", mapSize.x, mapSize.y, fuel);
    fflush(info);

    map = initMap(mapSize);
    debug_print(" ---> INIT MAP DONE \n");
    fprintf(info, "\t -> x : %d, y : %d \n", map->size.x, map->size.y);
    fflush(info);
    fprintf(info, "\t -> map : \n");
    fflush(info);
    for(int i=0; i < map->size.y; i++){
        for(int j=0; j < map->size.x; j++){
            fprintf(info, "%c", map->plan[i][j]);
            fflush(info);
        }
        fprintf(info, "\n");
        fflush(info);
    }

    car = initCar(fuel);
    debug_print(" ---> INIT CAR DONE \n");
    fprintf(info, "\t -> fuel : %d \n", car->fuel);
    fflush(info);

    debug_print("=====> START RACE <=====\n");

    while (!feof(stdin)) {

        fprintf(info, " ---> Tour %d \n", tour);
        fflush(info);
        initRound(car, map);
        fprintf(info, "\t -> position (%d,%d)  \n", car->currentPosition.x, car->currentPosition.y);
        fflush(info);
        acceleration = playRound(car, map);
        fprintf(info, "\t -> supposed acceleration (%d,%d)  \n", acceleration.x, acceleration.y);
        fflush(info);
        sendDatas(acceleration);
        tour++;

    }

}

