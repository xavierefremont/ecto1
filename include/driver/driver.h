/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 21/04/2018
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


/**
 * Initialize the game by reading map and car datas
 * @param car : the game car
 * @param map : the track map
 */
void initGame(car* car, map* map);

/**
 * Initialize the round by reading current position
 * @param car : the game car
 * @param map : the track map
 */
void initRound(car* car, map* map);

/**
 * Calculate the acceleration and send it to the race program
 * @param car : the game car
 * @param map : the track map
 */
void playRound(car* car, map* map);


#endif //__DRIVER_H
