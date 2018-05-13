/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 27/04/2018
 */

/**
 * @file testGPS.c
 * @brief Test GPS file
 */

#include "../../include/util/ArrayList.h"
#include "../../include/driver/driver.h"
#include "../../include/gps/gps.h"

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
    vector* acceleration = NULL;
    position* possiblePosition = NULL;
    ArrayList possibleMoves = NULL;

    vector* mapSize;
    int fuel, x, y;
    int tour = 1;
    int arraySize = 0;

    info = fopen("ecto1/etc/testGPS.log", "w");
    debug_print("=====> START TESTGPS <=====\n");

    initGame(&x, &y, &fuel);
    mapSize = createVector(x, y);
    fprintf(info, " ---> INIT GAME DONE (x : %d, y : %d, fuel : %d) \n", mapSize->x, mapSize->y, fuel);
    fflush(info);

    map = initMap(mapSize);
    debug_print(" ---> INIT MAP DONE \n");
    fprintf(info, "\t -> x : %d, y : %d \n", map->size->x, map->size->y);
    fflush(info);
    fprintf(info, "\t -> map : \n");
    fflush(info);
    for(int i=0; i < map->size->y; i++){
        for(int j=0; j < map->size->x; j++){
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
        fprintf(info, "\t -> position (%d,%d)  \n", car->currentPosition->x, car->currentPosition->y);
        fflush(info);
        fprintf(info, "\t -> speed (%d,%d)  \n", car->currentSpeed->x, car->currentSpeed->y);
        fflush(info);
        acceleration = playRound(car, map);
        fprintf(info, "\t -> supposed acceleration (%d,%d)  \n", acceleration->x, acceleration->y);
        fflush(info);
        possibleMoves = getPossibleMoves(info, car, map);
        fprintf(info, "\t -> possibles moves : \n");
        fflush(info);

        for(unsigned int i=0; i<ArrayListGetLength(possibleMoves); i++){
            possiblePosition = ArrayListGet(possibleMoves, i);
            fprintf(info, "\t\t -> (%d,%d)  \n", possiblePosition->x, possiblePosition->y);
            fflush(info);
        }

        ArrayListDelete(possibleMoves);
        sendDatas(acceleration);
        tour++;
        updateGame(car, map, acceleration);

    }

}

