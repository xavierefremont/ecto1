/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 21/04/2018
 */

/**
 * @file car.h
 * @brief Header of car file
 */

#ifndef _CAR_H
#define _CAR_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/structs.h"

car* initCar(int fuel);


/**
 * Calculates the current fuel, remaining after the move
 * @param pointer on Car structure to have the presumed fuel, the previous position and then change the fuel
 * @param Map structure to get the current position
 */
void currentFuel(car* car, map* map);

/**
 * Calculates the fuel wich would be used if the motion is done
 * it calculation is realized before trying the motion in the race
 * the value is négative
 * @param Car structure 
 */
void calculatePresumedFuel(car* car);

#endif //_CAR_H
