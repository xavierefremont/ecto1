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

/**
 * Initializes the game by reading map and car datas
 * @param a pointer to the number of rows
 * @param a pointer to the number of columns
 * @param a pointer to the start fuel amount
 */
void initGame(int* x, int* y, int* fuel);

/**
 * Initializes the map by sending all datas to the map file
 * @param the structure vector containing the map size
 * @return the map created
 */
map* initMap(vector* mapSize);

/**
 * Initializes the car by sending all datas to the car file
 * @param fuel at the begining
 * @return the map created
 */
car* initCar(int fuel);

/**
 * Initializes the round by reading current position
 * @param car the game car
 * @param map the track map
 */
void initRound(car* car, map* map);

/**
 * Calculate the acceleration and send it to the race program
 * @param car the game car
 * @param the track map
 * @return the acceleration vector to send
 */
vector* playRound(car* car, map* map);

/**
 * Update the car and the map according to the acceleration
 * @param car the game car
 * @param map the game map
 * @param acceleration's vector
 */
void updateGame(car* car, map* map, vector* acceleration);

/**
 * Sends datas through stdout
 * @param acceleration's vector
 */
void sendDatas(vector* acceleration);


#endif //__DRIVER_H
