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

int verifyPath(map* map, position* p, vector* speed);

vector* createVector(int x, int y);

vector* vectorSpeed(position* src, position* dest);

vector* calculateAcceleration(position* src, position* dest, vector* speed);

float getVectorNorm(vector* v);

ArrayList getPossibleMoves(FILE* info, vector* speeed, position* current, map* map);

ArrayList getAllArrivals(map* map);

ArrayList calculateDijkstra(FILE* info, map* map, car* car);

void destroyVector(vector* v);

int getDistance(position* p, position* p2);

Stack getPathWithSpeed(FILE* info, map* map, car* car, ArrayList path);

int checkMove(FILE* info, map* map, position* current, vector* speed, int fuel,
              ArrayList path, int step, position*** previous);

#endif //__GPS_H
