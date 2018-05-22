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
 * @return map pointerthe new map
 */
map* createMap(vector* mapSize);

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
void setPosition(map* map, position* rival1, position* rival2);


/**
 * Verify if a position on the map is correct to move into
 * @param the map structure
 * @param the target position to check in the map
 * @return 1 if the position is correct, else 0
 */
int isCorrectPosition(map* map, position* target);


/**
 * Verify if a position is free i.e a road or sable without car
 * @param the map structure
 * @param the target position to check in the map
 * @return 1 if the position is in the free, else 0
 */
int isPositionFree(map* map, position* target);

/**
 * Create a new postion structure pointer
 * @param column
 * @param row
 * @param roadType
 * @return the pointer of the created structure
 */
position* createPosition(int col, int row, char roadType);


/**
 * @brief Definition d'un segment entre deux points
 */
void line(int x1, int y1, int x2, int y2, infoLine *data);

/**
 * @brief Deplacement sur un segment dans un sens donne (+1 vers la fin, et -1
 * vers le debut)
 */
int nextPoint(infoLine *data, pos2Dint *point, int sens);

/**
 * Verifies if the path has no collision
 * @param map to have the path
 * @param p the current position of the car
 * @param speed the vector to reach the destination
 */
int isCorrectMove(map* map, position* p, vector* speed);


/**
 * Destroy a map structure
 * @param the map to destroy
 */
void destroyMap(map* map);


/**
 * Destroy a position structure
 * @param the position to destroy
 */
void destroyPosition(position* p);




#endif //__MAP_H
