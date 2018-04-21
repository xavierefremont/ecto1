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
  int currentSpeed;
  int fuel;
  int presumedFuel;
  int nbrBoosts;
};

/**
 * Calculates the current fuel, remaining after the move
 * @param pointer on Car structure to have the presumed fuel, the previous position and then change the fuel
 * @param Map structure to get the current position
 */
void currentFuel(struct car* car, struct map map) {

}

/**
 * Calculates the fuel wich would be used if the motion is done
 * it calculation is realized before trying the motion in the race
 * the value is négative
 * @param Car structure 
 */
void calculatePresumedFuel(struct car car) {
  //modified the function using a car structure
    int valeur = accX * accX + accY * accY;
    valeur += (int)(sqrt(velX * velX + velY * velY) * 3.0 / 2.0);
    if (dansSable)
        valeur += 1;
    //  -valeur : insert in the car structure;
}

#endif //GRANDPRIX2018_3_0_3_CAR_H
