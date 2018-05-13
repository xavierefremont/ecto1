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
 * @param the map size in a position structure
 * @return the new map
 */
map* createMap(position mapSize);

/**
 * Initializes the map, i.e fill the plan in
 * @param map pointer to initialize
 */
void generateMap(map* map);

/**
 * Set in the map the current position of the rivals' cars
 * @param map pointer in which the positions will be set
 * @param rival1, rival2 position of the others
 */
void setPosition(map* map,  position rival1, position rival2);

/**
 * Send to the GPS the structure of the map changed to estimate
 * speed and acceleration
 * @param the new map
 */
void sendToGPS(map* map);


#endif //__MAP_H
