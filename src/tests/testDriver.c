/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 27/04/2018
 */

/**
 * @file testDriver.c
 * @brief Driver test file
 */


#include "../../include/util/ArrayList.h"
#include "../../include/driver/driver.h"
#include "../../include/gps/gps.h"
#include "../../include/gps/map.h"
#include "../../include/car/car.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


FILE* info;

void debug_print(char* text){
    fprintf(info, text);
    fflush(info);
}


void readDatas(FILE* info){
    char c;
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n'){
        fprintf(info, "c : %c\n", c);
    }
}


int main(){

    map* map = NULL;
    car* car = NULL;
    vector* acceleration;

    vector* mapSize;
    int fuel, x, y;
    int tour = 1;
    int timeout = 0;

    int verifyPosition;

    info = fopen("ecto1/etc/testDriver.log", "w");
    debug_print("=====> START TESTDRIVER <=====\n");

    initGame(&x, &y, &fuel);
    mapSize = createVector(x, y);
    fprintf(info, " ---> INIT GAME DONE (x : %d, y : %d, fuel : %d) \n", mapSize->x, mapSize->y, fuel);
    fflush(info);
    debug_print("=====> ICI <=====\n");

    map = initMap(mapSize);
    debug_print(" ---> INIT MAP DONE \n");
    fprintf(info, "\t -> x : %d, y : %d \n", map->size->x, map->size->y);
    fflush(info);
    fprintf(info, "\t -> map : \n");
    fflush(info);
    for(int i=0; i < map->size->y; i++){
        for(int j=0; j < map->size->x; j++){
            fprintf(info, "%c", map->plan[i][j]->type);
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

        clock_t begin = clock();

        fprintf(info, " ---> Tour %d \n", tour);
        fflush(info);
        initRound(car, map);
        fprintf(info, "\t -> position (%d,%d)  \n", car->currentPosition->col, car->currentPosition->row);
        fflush(info);
        acceleration = playRound(car, map);
        fprintf(info, "\t -> supposed acceleration (%d,%d)  \n", acceleration->x, acceleration->y);
        fprintf(info, "\t -> current speed (%d,%d)  \n", car->currentSpeed->x, car->currentSpeed->y);
        fprintf(info, "\t -> current fuel : %d \n", car->fuel);
        position* kek = map->plan[car->currentPosition->row + car->currentSpeed->y + acceleration->y]
                [car->currentPosition->col + car->currentSpeed->x + acceleration->x];
        fprintf(info, "\t -> supposed move : (%d %d) \n", kek->col, kek->row);
        fflush(info);
        updateGame(car, map, acceleration);
        sendDatas(acceleration);

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        fprintf(info, "\t -> Tour over : %f s \n", time_spent);
        fflush(info);

        if(time_spent > 1){
            fprintf(info,"TIMEOUT\n");
            fflush(info);
            timeout = 1;
        }

        tour++;






    }

}

