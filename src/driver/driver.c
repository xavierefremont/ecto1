/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 21/04/2018
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

    map = createMap(x, y);
    initMap(map);
    car = initCar(fuel);

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
    setPosition(carPosition, rival1Position, rival2Position);
    car->currentPosition = carPosition;

    //TODO : Verif deplacement ok

}

/**
 * Calculate the acceleration and send it to the race program
 * @param car : the game car
 * @param map : the track map
 */
void playRound(car* car, map* map){

    /* Calculate the acceleration vector */
    vector v;
    v = calculateVector(car, map);

    /* Send */
    sprintf(action, "%d %d", v.x, v.y);
    sendDatas();

}

/**
 * Send datas through stdout
 */
void sendDatas(){

    fprintf(stdout, "%s\n", action);
    memset(action, 0, sizeof(action));

}
