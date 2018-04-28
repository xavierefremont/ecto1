/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
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

#include "../../include/structs.h"


void initGame(car* car, map* map);


void initRound(car* car, map* map);


void playRound(car* car, map* map);


void sendDatas();


#endif //__DRIVER_H
