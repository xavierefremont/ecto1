/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 21/04/2018
 */

/**
 * @file ecto1.c
 * @brief Ecto1 file :  Main program of Formula 1 project
 */

#include "../include/util/ArrayList.h"
#include "../include/driver/driver.h"
#include "../include/gps/gps.h"
#include "../include/gps/map.h"
#include "../include/car/car.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    map* map = NULL;
    car* car = NULL;
    vector* acceleration;
    vector* mapSize;
    int fuel, x, y;

    initGame(&x, &y, &fuel);
    mapSize = createVector(x, y);
    map = initMap(mapSize);
    car = initCar(fuel);
    while (!feof(stdin)) {
        initRound(car, map);
        acceleration = playRound(car, map);
        updateGame(car, map, acceleration);
        sendDatas(acceleration);
    }
    destroyMap(map);
    destroyCar(car);

    return 0;
}
