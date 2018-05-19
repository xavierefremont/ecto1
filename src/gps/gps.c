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
#include "../../include/util/PriorityQueue.h"
#include "../../include/gps/map.h"
#include "../../include/car/car.h"
#include "../../include/gps/gps.h"


vector* createVector(int x, int y){

    vector* v = NULL;
    v = malloc(sizeof(struct vector));
    if(v == NULL){
        return NULL;
    }
    v->x = x;
    v->y = y;

    return v;

}


vector* calculateVector(car* car, map* map){

    //remove next line, just for tests
    vector* v = createVector(1,0);

    return v;
    //TODO : Calculer le vecteur avec un graphe et un algo

}


float getVectorNorm(vector* v){

    return sqrt(pow(v->x,2)+pow(v->y,2));

}


ArrayList getPossibleMoves(vector* speed, position* current, map* map){

    //TODO : Get the real possible position and not all

    ArrayList possibleMoves = newArrayList(sizeof(position));

    position* p1 = map->plan[current->y + speed->y][current->x + speed->x];

    if(isCorrectPosition(map, p1)){
        ArrayListAppend(possibleMoves, p1);
    }else{
        free(p1);
    }

    position* p2 = map->plan[ current->y + speed->y][current->x + speed->x + 1];

    if(isCorrectPosition(map, p2)){
        ArrayListAppend(possibleMoves, p2);
    }else{
        free(p2);
    }

    position* p3 = map->plan[current->y + speed->y][current->x + speed->x + 1];

    if(isCorrectPosition(map, p3)){
        ArrayListAppend(possibleMoves, p3);
    }else{
        free(p3);
    }

    position* p4 = map->plan[current->y + speed->y - 1][current->x + speed->x + 1];

    if(isCorrectPosition(map, p4)){
        ArrayListAppend(possibleMoves, p4);
    }else{
        free(p4);
    }

    position* p5 = map->plan[current->y + speed->y][current->x + speed->x - 1];

    if(isCorrectPosition(map, p5)){
        ArrayListAppend(possibleMoves, p5);
    }else{
        free(p5);
    }

    position* p6 = map->plan[current->y + speed->y + 1][current->x + speed->x - 1];

    if(isCorrectPosition(map, p6)){
        ArrayListAppend(possibleMoves, p6);
    }else{
        free(p6);
    }

    position* p7 = map->plan[current->y + speed->y - 1][current->x + speed->x - 1];

    if(isCorrectPosition(map, p7)){
        ArrayListAppend(possibleMoves, p7);
    }else{
        free(p7);
    }

    //TODO : Take care if the car is in sand and check the vector norm

    return possibleMoves;

}

ArrayList getAllArrivals(map* map){

    int x, y;
    ArrayList arrivals = newArrayList(sizeof(position));

    for(y=0; y<map->size->y; y++){
        for(x=0; x<map->size->x; x++){
            if(map->plan[y][x]->type == '='){
                position* p = map->plan[y][x];
                ArrayListAppend(arrivals, p);
            }
        }
    }

    return arrivals;

}


ArrayList calculateDijkstra(map* map, car* car){

    clock_t begin = clock();
    int x, y, i, tmpDist;
    int** distance;
    position*** previous;
    position* p = NULL;
    position* pNeighbor = NULL;
    PriorityQueue queue =  newPriorityQueue();
    ArrayList neighbors = NULL;
    ArrayList arrivals = NULL;
    ArrayList path = newArrayList(sizeof(position));

    /*Initialisation of the algorithm*/
    distance = malloc(sizeof(int*) * map->size->y);
    previous = malloc(sizeof(position**) * map->size->y);

    for(y = 0; y < map->size->y; y++){
        distance[y] = malloc(sizeof(int) * map->size->x);
        previous[y] = malloc(sizeof(position*) * map->size->x);
        for (x = 0; x < map->size->x; x++) {
            p = map->plan[y][x];
            previous[y][x] = NULL;
            if(areEqualsPosition(car->currentPosition, p)){
                distance[y][x] = 0;
            }else{
                distance[y][x] = INT_MAX;
            }
            if(isCorrectPosition(map, p)){
                PriorityQueueAdd(queue, p, distance[y][x]);
            } else {
                free(p);
            }
        }
    }

    /*Algorithm*/
    while(!PriorityQueueIsEmpty(queue)){
        p = (position*) PriorityQueuePop(queue);
        neighbors = getPossibleMoves(car->currentSpeed, p, map);
        for(i=0; i<ArrayListGetLength(neighbors); i++){
            pNeighbor = (position*) ArrayListGet(neighbors, i);
            tmpDist = distance[p->y][p->x] + 1;
            if(tmpDist < distance[pNeighbor->y][pNeighbor->x] && !areEqualsPosition(p, pNeighbor)){
                distance[pNeighbor->y][pNeighbor->x] = tmpDist;
                previous[pNeighbor->y][pNeighbor->x] = p;
                PriorityQueueChangePrioSpecificSearch(queue, pNeighbor, tmpDist, (int (*)(T, T)) areEqualsPosition);
            }
        }
    }

    arrivals = getAllArrivals(map);
    tmpDist = INT_MAX;
    position* best;

    for(i=0; i<ArrayListGetLength(arrivals); i++){
        p = (position*) ArrayListGet(arrivals, i);
        if(distance[p->y][p->x] < tmpDist){
            best = p;
        }
    }

    p = best;

    while(previous[p->y][p->x] != NULL){
        ArrayListAppend(path, previous[p->y][p->x]);
        p = previous[p->y][p->x];
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("TEMPS EXEC : %f\n", time_spent);

    return path;

}
