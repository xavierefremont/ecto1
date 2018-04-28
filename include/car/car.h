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

<<<<<<< HEAD
=======
struct car{
  position previousPosition;
  position currentPosition;
  int currentSpeed;
  int fuel;
  int presumedFuel;
  int nbrBoosts;
};
>>>>>>> 024f95e8f10323bef9a7dcfdbbd2872f65248034

/**
 * Initialize a new car using starts' datas
 */
void initCar(car* car );

/**
 * Calculates the current fuel, remaining after the move
 * @param pointer on Car structure to have the presumed fuel, the previous position and then change the fuel
 * @param Map structure to get the current position
 */
<<<<<<< HEAD
void currentFuel(car* car, map* map);
=======
void currentFuel(car* car);
>>>>>>> 024f95e8f10323bef9a7dcfdbbd2872f65248034

/**
 * Calculates the fuel wich would be used if the motion is done
 * it calculation is realized before trying the motion in the race
 * the value is négative
 * @param Car structure 
 */
<<<<<<< HEAD
void calculatePresumedFuel(car* car);

#endif //_CAR_H
=======
void calculatePresumedFuel(struct car car);

/**
 * Determines if the car has moved
 * @param car 
 * @return 1 if current and previous positions are equals, 0 either
 */
int positionEquals(car car);

#endif //GRANDPRIX2018_3_0_3_CAR_H

>>>>>>> 024f95e8f10323bef9a7dcfdbbd2872f65248034
