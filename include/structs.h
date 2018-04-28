//
// Created by julien on 28/04/18.
//

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
};

struct car{
    position previousPosition;
    position currentPosition;
    int currentSpeed;
    int fuel;
    int presumedFuel;
    int nbrBoosts;
};


#endif //_STRUCTS_H
