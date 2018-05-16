/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file driver.h
 * @brief Header of driver file
 */

#ifndef __DRIVER_H
#define __DRIVER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../structs.h"


void initGame(int* x, int* y, int* fuel);


map* initMap(vector* mapSize);


car* initCar(int fuel);


void initRound(car* car, map* map);


vector* playRound(car* car, map* map);


void updateGame(car* car, map* map, vector* acceleration);


void sendDatas(vector* acceleration);


void readChar();


#endif //__DRIVER_H
