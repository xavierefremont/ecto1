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

#include "../../include/structs.h"


/**
 * Creates a structure map initializing the size sent by the driver
 * @param width of the map
 * @param height of the map
 * @return the new map
 */
map* createMap(vector* mapSize);

/**
 * Initializes the map, i.e fill the plan in
 * @param map pointer to initialize
 */
void generateMap(map* map);


position* createPosition(int x, int y);


/**
 * Set in the map the current position of the rivals' cars
 * @param map pointer in which the positions will be set
 * @param rival1, rival2 position of the others
 */
void setPosition(map* map, position* rival1, position* rival2);


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
