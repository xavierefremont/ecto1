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
#include <time.h>

#include "../../include/structs.h"

vector* createVector(int x, int y);

vector* calculateVector(car* car, map* map);

float getVectorNorm(vector* v);

ArrayList getPossibleMoves(vector* speed, position* current, map* map);

ArrayList getAllArrivals(map* map);

ArrayList calculateDijkstra(map* map, car* car);

void destroyVector(vector* v);


#endif //__GPS_H
