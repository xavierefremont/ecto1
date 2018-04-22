/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 21/04/2018
 */

/**
 * @file ecto1.c
 * @brief Ecto1 file :  Main program of Formula 1 project
 */

#include "../include/car/car.h"
#include "../include/gps/map.h"
#include "../include/driver/driver.h"

int main() {

    car* car;
    map* map;

    initGame(car, map);

    while (!feof(stdin)) {

        initRound(car, map);
        playRound(car, map);

    }

    return EXIT_SUCCESS;

}
