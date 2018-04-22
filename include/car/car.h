/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 21/04/2018
 */

/**
 * @file car.h
 * @brief Header of car file
 */

#ifndef GRANDPRIX2018_3_0_3_CAR_H
#define GRANDPRIX2018_3_0_3_CAR_H

typedef struct car car;

struct car{
  position previousPosition;
  position currentPosition;
  int currentSpeed;
  int fuel;
  int presumedFuel;
  int nbrBoosts;
};

/**
 * Initialize a new car using starts' datas
 */
void initCar(car* car );

/**
 * Calculates the current fuel, remaining after the move
 * @param pointer on Car structure to have the presumed fuel, the previous position and then change the fuel
 * @param Map structure to get the current position
 */
void currentFuel(car* car);

/**
 * Calculates the fuel wich would be used if the motion is done
 * it calculation is realized before trying the motion in the race
 * the value is négative
 * @param Car structure 
 */
void calculatePresumedFuel(struct car car);

/**
 * Determines if the car has moved
 * @param car 
 * @return 1 if current and previous positions are equals, 0 either
 */
int positionEquals(car car);

#endif //GRANDPRIX2018_3_0_3_CAR_H

