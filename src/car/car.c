/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file car.c
 * @brief Car file : everything dealing with car state and its speed
 */

#include "../../include/util/ArrayList.h"
#include "../../include/gps/map.h"
#include "../../include/gps/gps.h"
#include "../../include/car/car.h"

/**
 * Initialize a new car using starts' datas
 * @param the start car fuel value
 * @return pointer on the created Car structure
 */
car* createCar(int fuel) {

    car *car = NULL;
    car = (struct car*) malloc(sizeof(struct car));
    if(car == NULL){
        return NULL;
    }
    car->fuel = fuel;
    car->previousPosition = NULL;
    car->currentPosition = NULL;
    car->currentSpeed = createVector(0,0);
    car->presumedFuel = 0;
    car->nbrBoosts = 5;

    return car;

}

/**
 * Calculates the current fuel, remaining after the move
 * @param pointer on Car structure to have the presumed fuel, the previous position and then change the fuel
 */
void currentFuel(car* car) {

  if(!areEqualsPosition(car->currentPosition, car->previousPosition)) {
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
 * @param acceleration vector
 * @param speed vector
 */
int calculatePresumedFuel(vector* acc, vector* spe, position* dest) {
  //TODO dans sable
  int accX = acc->x;
  int accY = acc->y;
  int velX = spe->x;
  int velY = spe->y;
  int valeur = accX * accX + accY * accY;
  valeur += (int)(sqrt(velX * velX + velY * velY) * 3.0 / 2.0);
  if (dest->type == '~')
    valeur += 1;
  return valeur;
}

/**
 * Determines if the car has moved
 * @param car 
 * @return 1 if current and previous positions are equals, 0 either
 */
int verifyPosition(car* car) {

  return areEqualsPosition(car->previousPosition, car->currentPosition);
  
}

/**
 * Determines if two position are equals
 * @param first position
 * @param second position
 * @return 1 if both positions are equals, 0 either
 */
int areEqualsPosition(position* p1, position* p2){
    if(!p1 || !p2){
        return 0;
    }
    if(p1 == p2){
        return 1;
    }
    return (p1->col == p2->col && p1->row == p2->row);

}

/**
 * Destroy a car structure
 * @param the car to destroy
 */
void destroyCar(car* car){
    car->currentPosition = NULL;
    car->currentSpeed = NULL;
    car->previousPosition = NULL;
    free(car);
}
