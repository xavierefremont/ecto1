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
  position* size;
  char** plan;
  position* rival1;
  position* rival2;
};

struct car{
    position* previousPosition;
    position* currentPosition;
    vector* currentSpeed;
    int fuel;
    int presumedFuel;
    int nbrBoosts;
};



#endif //_STRUCTS_H
