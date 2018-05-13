/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
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

#include "../../include/util/structs.h"


/**
 * Calculates the current fuel, remaining after the move
 * @param pointer on Car structure to have the presumed fuel, the previous position and then change the fuel
 */
void currentFuel(car* car);


/**
 * Calculates the fuel wich would be used if the motion is done
 * it calculation is realized before trying the motion in the race
 * the value is négative
 * @param Car structure 
 */
void calculatePresumedFuel(car* car);


/**
 * Determines if the car has moved
 * @param car 
 * @return 1 if current and previous positions are equals, 0 either
 */
int verifyPosition(car* car);

/**
 * Determines if two position are equals
 * @param first position
 * @param second position
 * @return 1 if both positions are equals, 0 either
 */
int areEqualsPosition(position* p1, position* p2);

#endif //_CAR_H

