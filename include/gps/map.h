/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file map.h
 * @brief Header of map file
 */

#ifndef __MAP_H
#define __MAP_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/util/structs.h"


/**
 * Initializes the map, i.e fill the plan in
 * @param map pointer to initialize
 */
void generateMap(map* map);

/**
 * Set int the map the current position of the three cars
 * @param map pointer in which the positions will be set
 * @param car position ouf ourselves
 * @param rival1, rival2 position of the others
 */
void setPosition(map* map, position* car, position* rival1, position* rival2);

/**
 * Send to the GPS the structure of the map changed to estimate
 * speed and acceleration
 * @param the new map
 */
void sendToGPS(map* map);


/**
 * Verify if a position on the map is correct to move into
 * @param the map structure
 * @param the target position to check in the map
 * @return 1 if the position is correct, else 0
 */
int isCorrectPosition(map* map, position* target);


/**
 * Verify if a position is in the map
 * @param the map structure
 * @param the target position to check in the map
 * @return 1 if the position is in the map, else 0
 */
int isPositionInMap(map* map, position* target);


/**
 * Verify if a position is free i.e a road or sable without car
 * @param the map structure
 * @param the target position to check in the map
 * @return 1 if the position is in the free, else 0
 */
int isPositionFree(map* map, position* target);

/**
 * Create a new postion structure pointer
 * @param x
 * @param y
 * @return the pointer of the created structure
 */
position* createPosition(int x, int y);

#endif //__MAP_H
