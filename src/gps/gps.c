/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file gps.c
 * @brief GPS file : Calculate the car movement with algorithm
 */

#include "../../include/util/ArrayList.h"
#include "../../include/gps/gps.h"


vector* calculateVector(car* car, map* map){

    //remove next line, just for tests
    vector* v = createVector(1,0);

    return v;
    //TODO : Calculer le vecteur avec un graphe et un algo

}


float getVectorNorm(vector* v){

    return sqrt(pow(v->x,2)+pow(v->y,2));

}


ArrayList getPossibleMoves(FILE* info, car* car, map* map){

    ArrayList possibleMoves = newArrayList(sizeof(position));
    vector* speed = car->currentSpeed;
    position* currentPosition = car->currentPosition;

    position* p1 = createPosition(currentPosition->x + speed->x, currentPosition->y + speed->y);

    if(isCorrectPosition(map, p1)){
        ArrayListAppend(possibleMoves, p1);
    }

    position* p2 = createPosition(currentPosition->x + speed->x + 1, currentPosition->y + speed->y);

    if(isCorrectPosition(map, p2)){
        ArrayListAppend(possibleMoves, p2);
    }

    position* p3 = createPosition(currentPosition->x + speed->x + 1, currentPosition->y + speed->y + 1);

    if(isCorrectPosition(map, p3)){
        ArrayListAppend(possibleMoves, p3);
    }

    position* p4 = createPosition(currentPosition->x + speed->x + 1, currentPosition->y + speed->y - 1);

    if(isCorrectPosition(map, p4)){
        ArrayListAppend(possibleMoves, p4);
    }

    position* p5 = createPosition(currentPosition->x + speed->x - 1, currentPosition->y + speed->y);

    if(isCorrectPosition(map, p5)){
        ArrayListAppend(possibleMoves, p5);
    }

    position* p6 = createPosition(currentPosition->x + speed->x - 1, currentPosition->y + speed->y + 1);

    if(isCorrectPosition(map, p6)){
        ArrayListAppend(possibleMoves, p6);
    }

    position* p7 = createPosition(currentPosition->x + speed->x - 1, currentPosition->y + speed->y - 1);

    if(isCorrectPosition(map, p7)){
        ArrayListAppend(possibleMoves, p7);
    }

    //TODO : Take care if the car is in sand and check the vector norm

    return possibleMoves;

}