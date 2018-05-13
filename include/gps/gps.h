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

#include "../../include/util/structs.h"

vector* calculateVector(car* car, map* map);

float getVectorNorm(vector* v);

ArrayList getPossibleMoves(FILE* info, car* car, map* map);



#endif //__GPS_H
