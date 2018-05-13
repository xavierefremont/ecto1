/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.1 / 28/04/2018
 */

/**
 * @file structs.h
 * @brief Header containing all structures used in the program
 */

#ifndef _STRUCTS_H
#define _STRUCTS_H

typedef struct vector vector;
typedef struct position position;
typedef struct map map;
typedef struct car car;


struct vector{
    int x;
    int y;
};

struct position {
    int x;
    int y;
};

typedef struct map {
  position size;
  char** plan;
  position rival1;
  position rival2;
};

struct car{
    position* previousPosition;
    position* currentPosition;
    vector* currentSpeed;
    int fuel;
    int presumedFuel;
    int nbrBoosts;
};


/**
 * Creates a structure map initializing the size sent by the driver
 * @param width of the map
 * @param height of the map
 * @return the new map
 */
map* createMap(vector* mapSize);


position* createPosition(int x, int y);


vector* createVector(int x, int y);


/**
 * Initialize a new car using starts' datas
 * @param the start car fuel value
 * @return pointer on the created Car structure
 */
car* createCar(int fuel);

#endif //_STRUCTS_H
