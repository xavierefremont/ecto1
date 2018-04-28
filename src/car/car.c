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
 * Initialize a car structure
 * @param pointer on Car structure to initialize
 * @param the fuel value
 */
car* initCar(int fuel){
    car* car;
    int a;
    return car;
}

/**
 * Calculates the current fuel, remaining after the move
 * @param pointer on Car structure to have the presumed fuel, the previous position and then change the fuel
 * @param Map structure to get the current position
 */
void currentFuel(car* car, map* map) {

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

    //modified the function using a car structure
    int valeur = accX * accX + accY * accY;
    valeur += (int)(sqrt(velX * velX + velY * velY) * 3.0 / 2.0);
    if (dansSable)
        valeur += 1;
    //  -valeur : insert in the car structure;
}
