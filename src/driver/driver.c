/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file driver.c
 * @brief Driver file, deal with all interaction between the race program and the driver program
 */


#include "../../include/driver/driver.h"
#include "../../include/gps/map.h"
#include "../../include/car/car.h"
#include "../../include/gps/gps.h"

/**
 * Buffer that contain all action to be sent to the main program
 */
static char action[100];

//Remove next line (just for tests)
static int debug = 0;


/**
 * Initialize the game by reading map and car datas
 * @param a pointer to a structure position containing the map size
 * @param a pointer to the start fuel amount
 */
void initGame(position* mapSize, int* fuel){

    char c;

    /* Read the map size and the start fuel */
    fscanf(stdin, "%d %d %d", &mapSize->x, &mapSize->y, fuel);

    /* Read datas until the line end */
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n');

}

/**
 * Initialize the map by sending all datas to the map file
 * @param the structure position containing the map size
 * @return the map created
 */
map* initMap(position mapSize){

    map* map = createMap(mapSize);
    generateMap(map);
    return map;

}

/**
 * Initialize the car by sending all datas to the car file
 * @param the structure position containing the map size
 * @return the map created
 */
car* initCar(int fuel){

    car* car = createCar(fuel);
    return car;

}

/**
 * Initialize the round by reading current position
 * @param car : the game car
 * @param map : the track map
 */
void initRound(car* car, map* map){

    position carPosition;
    position rival1Position;
    position rival2Position;

    /* Read current cars position */
    fscanf(stdin, "%d %d\t%d %d\t%d %d\n",
           &carPosition.x, &carPosition.y,
           &rival1Position.x, &rival1Position.y,
           &rival2Position.x, &rival2Position.y);


    /* Set car position into the map*/
    //setPosition(map, carPosition, rival1Position, rival2Position);
    car->currentPosition = carPosition;

    //TODO : Check if the previous move was done and handle moves issues

}

/**
 * Calculate the acceleration and send it to the race program
 * @param car : the game car
 * @param map : the track map
 * @return the acceleration vector to send
 */
vector playRound(car* car, map* map){

    /* Calculate the acceleration vector */
    vector acceleration;
    //v = calculateVector(car, map);

    //Remove next block (just for tests)
    if(debug == 0){
        acceleration.x = 1;
        debug++;
    }else{
        acceleration.x = 0;
    }
    acceleration.y = 0;

    return acceleration;

}

/**
 * Update the car and the map according to the acceleration
 * @param car : the game car
 * @param map : the game map
 * @param acceleration : the acceleration vector
 */
void updateGame(car* car, map* map, vector acceleration){

    //todo : Update the car presumed position and fuel by sending datas to the car file
    //todo : Update the map by sending new presumed position to the map file

}


/**
 * Send datas through stdout
 */
void sendDatas(vector acceleration){

    sprintf(action, "%d %d", acceleration.x, acceleration.y);
    fprintf(stdout, "%s\n", action);
    fflush(stdout);

}

