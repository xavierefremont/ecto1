/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 21/04/2018
 */

/**
 * @file car.c
 * @brief Car file : everything dealing with car state and its speed
 */

#include "../../include/car/car.h"

/**
 * Initialize a new car using starts' datas
 */
void initCar(car* car ) {

  
}

/**
 * Calculates the current fuel, remaining after the move
 * @param pointer on Car structure to have the presumed fuel, the previous position and then change the fuel
  */
void currentFuel(car* car) {

  if(car->currentPosition != car->previousPosition) {
    car->fuel = car->fuel + car->presumedFuel;
  } else {
    car->fuel = car->fuel - 1;
  }
  
}

/**
 * Calculates the fuel wich would be used if the motion is done
 * it calculation is realized before trying the motion in the race
 * the value is négative
 * @param Car structure 
 */
void calculatePresumedFuel(car car) {
  //modified the function using a car structure
    int valeur = accX * accX + accY * accY;
    valeur += (int)(sqrt(velX * velX + velY * velY) * 3.0 / 2.0);
    if (dansSable)
        valeur += 1;
    //  -valeur : insert in the car structure;
}

/**
 * Determines if the car has moved
 * @param car 
 * @return 1 if current and previous positions are equals, 0 either
 */
int positionEquals(car car) {

  return (car.currentPosition.x == car.previousPosition.x && car.currentPosition.y == car.previousPosition.y);
  
}
