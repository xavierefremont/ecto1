/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file driver.c
 * @brief Driver file, deal with all interaction between the race program and the driver program
 */


#include "../../include/util/ArrayList.h"
#include "../../include/util/Stack.h"
#include "../../include/driver/driver.h"
#include "../../include/gps/map.h"
#include "../../include/car/car.h"
#include "../../include/gps/gps.h"

static ArrayList moves = NULL;
static Stack realPath = NULL;
static int currentMove;
/**
 * Initializes the game by reading map and car datas
 * @param a pointer to the number of rows
 * @param a pointer to the number of columns
 * @param a pointer to the start fuel amount
 */
void initGame(int* x, int* y, int* fuel){

    char c;

    /* Read the map size and the start fuel */
    fscanf(stdin, "%d %d %d", x, y, fuel);

    /* Read datas until the line end */
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n');

}

/**
 * Initializes the map by sending all datas to the map file
 * @param the structure vector containing the map size
 * @return the map created
 */
map* initMap(vector* mapSize){

    map* map = createMap(mapSize);
    generateMap(map);
    return map;

}

/**
 * Initializes the car by sending all datas to the car file
 * @param fuel at the begining
 * @return the map created
 */
car* initCar(int fuel){

    car* car = createCar(fuel);
    return car;

}

/**
 * Initializes the round by reading current position
 * @param car the game car
 * @param map the track map
 */
void initRound(car* car, map* map){

    position* carPosition;
    position* rival1Position;
    position* rival2Position;
    int ax, ay, bx, by, cx, cy;
    char c;

    /* Read current cars position */
    fscanf(stdin, "%d %d\t%d %d\t%d %d",
           &ax, &ay,
           &bx, &by,
           &cx, &cy);
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n');

    carPosition = map->plan[ay][ax];
    rival1Position = map->plan[by][bx];
    rival2Position = map->plan[cy][cx];


    /* Set car position into the map*/
    setPosition(map, rival1Position, rival2Position);
    car->currentPosition = carPosition;

    if(car->previousPosition){
        if(areEqualsPosition(car->currentPosition, car->previousPosition)){
            car->currentSpeed = createVector(0,0);
        }
    }




    //TODO : Check if the previous move was done and handle moves issues

}

/**
 * Calculate the acceleration and send it to the race program
 * @param car the game car
 * @param the track map
 * @return the acceleration vector to send
 */
vector* playRound(FILE* info, car* car, map* map){

    /* Calculate the acceleration vector */
    vector* acceleration = NULL;
    position* p = NULL;

    if (moves == NULL) {
        fprintf(info, "LIST NULL\n");
        fflush(info);
        moves = calculateDijkstra(info, map, car);
        realPath = getPathWithSpeed(info, map, car, moves);
        fprintf(info, "Stack generated\n");
        fflush(info);
        currentMove = ArrayListGetLength(moves)-1;
    }

    if(realPath == NULL){
        fprintf(info, "Stack NULL\n");
        fflush(info);
        p = (position*) ArrayListGet(moves, currentMove);
    }else{
        p = (position *) StackPop(realPath);
    }

    if (car->previousPosition == car->currentPosition || !isCorrectPosition(map, p)) {
        realPath = NULL;
        moves = calculateDijkstra(info, map, car);
        realPath = getPathWithSpeed(info, map, car, moves);
        currentMove = ArrayListGetLength(moves)-1;
        p = (position *) StackPop(realPath);
        if(realPath == NULL){
            fprintf(info, "MOVE NULL 2\n");
            fflush(info);
            p = (position*) ArrayListGet(moves, currentMove);
        }else{
            p = (position *) StackPop(realPath);
        }
    }

    currentMove--;

    acceleration = calculateAcceleration(car->currentPosition, p, car->currentSpeed);

    //TODO : Maybe verificate before sending datas

    return acceleration;

}

/**
 * Update the car and the map according to the acceleration
 * @param car the game car
 * @param map the game map
 * @param acceleration's vector
 */
void updateGame(car* car, map* map, vector* acceleration){

    //todo : Update the car presumed position and fuel by sending datas to the car file
    //todo : Update the map by sending new presumed position to the map file

    position* dest = map->plan[car->currentPosition->row + car->currentSpeed->y + acceleration->y]
            [car->currentPosition->col + car->currentSpeed->x + acceleration->x];
    car->fuel -= calculatePresumedFuel(acceleration, car->currentSpeed, dest);
    car->currentSpeed->x = car->currentSpeed->x + acceleration->x;
    car->currentSpeed->y = car->currentSpeed->y + acceleration->y;
    car->previousPosition = car->currentPosition;

}


/**
 * Sends datas through stdout
 * @param acceleration's vector
 */
void sendDatas(vector* acceleration){

   fprintf(stdout, "%d %d\n", acceleration->x, acceleration->y);
   fflush(stdout);

}


