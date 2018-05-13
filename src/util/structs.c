/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 12/05/2018
 */

/**
 * @file structs.c
 * @brief all functions for creating and deleting games structures
 */

#include "../../include/util/structs.h"

#include <stdio.h>
#include <stdlib.h>

map* createMap(vector* mapSize) {

    map* map = NULgit L;
    map = (struct map*) malloc(sizeof(struct map));
    if(map){
        map->size = mapSize;
        map->plan = (char**) calloc(mapSize->y, sizeof(char*));
        for(int i=0;i<mapSize->y;i++)
            map->plan[i] = (char *) calloc(mapSize->x, sizeof(char));
        if(map->plan){
            return map;
        }
    }

    return NULL;

}


position* createPosition(int x, int y){

    position* p = malloc(sizeof(struct position));
    p->x = x;
    p->y = y;

    return p;

}


vector* createVector(int x, int y){

    vector* v = NULL;
    v = malloc(sizeof(struct vector));
    if(v == NULL){
        return NULL;
    }
    v->x = x;
    v->y = y;

    return v;

}


/**
 * Initialize a car structure
 * @param pointer on Car structure to initialize
 * @param the fuel value
 */
car* createCar(int fuel) {

    car *car = NULL;
    car = (struct car*) malloc(sizeof(struct car));
    if(car == NULL){
        return NULL;
    }
    car->fuel = fuel;
    car->previousPosition = createPosition(0,0);
    car->currentPosition = createPosition(0,0);
    car->currentSpeed = createVector(0,0);
    car->presumedFuel = 0;
    car->nbrBoosts = 5;

    return car;

}

