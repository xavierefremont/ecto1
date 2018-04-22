/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 21/04/2018
 */

/**
 * @file driver.c
 * @brief Driver file, deal with all interaction between the race program and the driver program
 */

#include "../../include/car/car.h"
#include "../../include/map/map.h"
#include "../../include/driver/driver.h"

/**
 * Initialize the game by reading map and car datas
 * @param car : the game car
 * @param map : the track map
 */
void initGame(car* car, map* map){

    int x, y;
    int fuel;

    /* Read the map size and the start fuel */
    fscanf(stdin, "%d %d %d", &x, &y, &fuel);

    initMap(map, x, y);
    initCar(car, fuel);

}

/**
 * Initialize the round by reading current position
 * @param car : the game car
 * @param map : the track map
 */
void initRound(car* car, map* map){

    char c;

    /*read current cars position*/
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
        //modif position courrant voiture
        //modif position adversaire
        //verif deplacement précédent
    }

}

/**
 * Calculate the acceleration and send it to the race program
 * @param car : the game car
 * @param map : the track map
 */
void playRound(car* car, map* map){

    //Vector* v;
    // v = calculateVector(struct car*);
    //envoi v a stdout
    //modif des données de déplacement

}
