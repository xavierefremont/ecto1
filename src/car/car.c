/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file car.c
 * @brief Car file : everything dealing with car state and its speed
 */

#include "../../include/car/car.h"

/**
 * Initialize a car structure
 * @param pointer on Car structure to initialize
 * @param the fuel value
 */
car* initCar(int fuel) {
    car *car;
    return car;
    //TODO : Malloc de car et assignation fuel
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
void calculatePresumedFuel(car* car) {
    int accX = 0;
    int accY = 0;
    int velX = 0;
    int velY = 0;
    int dansSable = 0;
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
int positionEquals(car* car) {

  return (car->currentPosition.x == car->previousPosition.x && car->currentPosition.y == car->previousPosition.y);
  
}
