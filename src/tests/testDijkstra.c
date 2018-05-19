/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 15/05/2018
 */

/**
 * @file testDijkstra.c
 * @brief Test Dijkstra file
 */

#include "../../include/util/ArrayList.h"
#include "../../include/driver/driver.h"
#include "../../include/gps/map.h"
#include "../../include/gps/gps.h"
#include "../../include/car/car.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


map* readMapFromFile(FILE* fp){

    printf("Start\n");

    map* map = NULL;
    vector* mapSize = NULL;
    int x, y, f;
    int j = 0;
    char read;

    fscanf(fp, "%d %d %d\n", &x, &y, &f);
    mapSize = createVector(x, y);
    map = createMap(mapSize);

    if(map == NULL){
        return NULL;
    }

    int a;
    for (int i = 0; i < map->size->y; i++) {
        while (fread(&read, sizeof(char), 1, fp) == 1 && read != '\n'){
            map->plan[i][j] = createPosition(j, i, read);
            j++;
        }
        j = 0;
    }

    return map;

}


void displayMap(map* map){
    for(int i = 0; i < map->size->y; i++){
        for(int j = 0; j < map->size->x; j++){
            printf("%c", map->plan[i][j]->type);
        }
        printf("\n");
    }
}


int main(){

    int i;
    map* map = NULL;
    car* car = NULL;
    FILE* fp = NULL;
    ArrayList path = NULL;
    position* p = NULL;

    fp = fopen("../tracks/starter_droit_au_but.txt", "r+");
    if(fp == NULL){
        exit(-1);
    }

    map = readMapFromFile(fp);
    if(map == NULL){
        exit(-1);
    }

    displayMap(map);

    car = createCar(50);
    car->currentPosition = map->plan[5][3];
    printf("A %d %d\n", car->currentPosition->col, car->currentPosition->row);
    printf("B %d %d\n", map->plan[car->currentPosition->row][car->currentPosition->col]->col, map->plan[car->currentPosition->row][car->currentPosition->col]->row);
    car->currentSpeed = createVector(0,0);

    FILE* info = fopen("etc/save.log", "w");

    path = calculateDijkstra(info, map, car);

    for(i=0; i<ArrayListGetLength(path); i++){
        p = (position*) ArrayListGet(path, i);
        map->plan[p->row][p->col]->type = '-';
    }

    displayMap(map);

    return 0;

}

