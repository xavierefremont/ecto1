/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file driver.h
 * @brief Header of gps file
 */

#ifndef __GPS_H
#define __GPS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <time.h>

#include "../../include/util/Stack.h"
#include "../../include/structs.h"

/**
 * Initializes a new vector
 * @param x
 * @param y
 * @return vector pointer's
 */
vector* createVector(int x, int y);

/**
 * Initializes a new speed vector
 * @param src the origin's position
 * @param dest the destination's position
 * @return vector pointer's
 */
vector* vectorSpeed(position* src, position* dest);

/**
 * Calculates the acceleration
 * @param src the origin's position
 * @param dest the destination's position
 * @param speed a vector
 * @return vector pointer's
 */
vector* calculateAcceleration(position* src, position* dest, vector* speed);

/**
 * Gets the norme of a vector
 * @param v the vector
 * @return float the norm
 */
float getVectorNorm(vector* v);

/**
 * Gets the possible move of the car knowing the speed
 * @param speed vector
 * @param current position of the cap
 * @param map
 * @return ArrayList of the moves
 */
ArrayList getPossibleMoves(FILE* info, vector* speeed, position* current, map* map);

/**
 * Gets arrivals on the map
 * @param map
 * @return ArrayList of arrivals
 */
ArrayList getAllArrivals(map* map);

/**
 * Gets the optimized path from the current position to arrival
 * @param map
 * @car to have current position
 * @return ArrayList of positions containig the path
 */
ArrayList calculateDijkstra(FILE* info, map* map, car* car);

/**
 * Gets the distance from a position to another
 * @param p pointer
 * @param p2 pointer
 * @return int the distance
 */
int getDistance(position* p, position* p2);

/**
 * Gets the path using speed
 * @param map
 * @param car
 * @param path calculates with Dijkstra
 * @return Stack the final path
 */
Stack getPathWithSpeed(FILE* info, map* map, car* car, ArrayList path);

/**
 * Checks if the move is authorized
 * @param map
 * @param current position of the car
 * @param speed vector's
 * @param fuel
 * @param path arraylist of positions
 * @param step
 * @param previous three entry tab's of position 
 * @return int boolean if the path is correct
 */
int checkMove(FILE* info, map* map, position* current, vector* speed, int fuel,
              ArrayList path, int step, position*** previous);

/**
 * Gets final moves of the path
 * @param map
 * @param current position
 * @param speed vector's
 * @param fuel
 * @param path arraylist of positions
 * @param step
 * @param previous three entry tab's of position 
 * @return int boolean if the path is correct
 */
int getFinalMoves(FILE* info, map* map, position* current, vector* speed, int fuel, ArrayList path,
                  position*** previous);

#endif //__GPS_H
