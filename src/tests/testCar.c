 /**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 27/04/2018
 */

/**
 * @file testCar.c
 * @brief Car test file
 */


#include "../../include/car/car.h"

int main(){

    car* car = NULL;
    vector acceleration;

    position mapSize;
    int fuel = 28;

    info = fopen("ecto1/etc/testCar.log", "w");
    debug_print("=====> START CAR <=====\n");

    car = createCar(fuel);
    if(car) {
	    debug_print(" ---> CREATE CAR DONE \n");
	    fflush(info);
	    fprintf(info, " -> fuel : %d \t prevPosition : %d,%d \t currPosition : %d,%d\n", car->fuel, car->previousPosition->x, car->previousPosition->y, car->currentPosition->x, car->currentPosition->y,);
	    fflush(info);
    } else {
	debug_print(" --> CREATE CAR ERROR\n");
    }

}

