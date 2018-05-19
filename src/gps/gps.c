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

    printf("Current : %d %d %c\n", current->col, current->row, current->type);
    for(int i = 0; i < map->size->y; i++){
        for(int j = 0; j < map->size->x; j++){
            if(areEqualsPosition(map->plan[i][j], current)){
                printf("X");
            }else
                printf("%c", map->plan[i][j]->type);

        }
        printf("\n");
    }


    ArrayList possibleMoves = newArrayList(sizeof(position));
    position* p = NULL;

    p = map->plan[current->row + speed->y][current->col + speed->x];

    if(isCorrectPosition(map, p)){
        printf("ADD : %d %d %c\n", p->col, p->row, p->type);
        ArrayListAppend(possibleMoves, p);
    }

    p = map->plan[ current->row + speed->y][current->col + speed->x + 1];

    if(isCorrectPosition(map, p)){
        printf("ADD : %d %d %c\n", p->col, p->row, p->type);
        ArrayListAppend(possibleMoves, p);
    }

    p = map->plan[current->row + speed->y][current->row + speed->x + 1];

    if(isCorrectPosition(map, p)){
        printf("ADD : %d %d %c\n", p->col, p->row, p->type);
        ArrayListAppend(possibleMoves, p);
    }

    p = map->plan[current->row + speed->y - 1][current->col + speed->x + 1];

    if(isCorrectPosition(map, p)){
        printf("ADD : %d %d %c\n", p->col, p->row, p->type);
        ArrayListAppend(possibleMoves, p);
    }

    p = map->plan[current->row + speed->y][current->col + speed->x - 1];

    if(isCorrectPosition(map, p)){
        printf("ADD : %d %d %c\n", p->col, p->row, p->type);
        ArrayListAppend(possibleMoves, p);
    }

    p = map->plan[current->row + speed->y + 1][current->col + speed->x - 1];

    if(isCorrectPosition(map, p)){
        printf("ADD : %d %d %c\n", p->col, p->row, p->type);
        ArrayListAppend(possibleMoves, p);
    }

    p = map->plan[current->row + speed->y - 1][current->col + speed->x - 1];

    if(isCorrectPosition(map, p)){
        printf("ADD : %d %d %c\n", p->col, p->row, p->type);
        ArrayListAppend(possibleMoves, p);
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
                printf("ADDQ %d %d %c\n", p->col, p->row, p->type);
                PriorityQueueAdd(queue, p, distance[y][x]);
            }
        }
    }


    /*Algorithm*/
    while(!PriorityQueueIsEmpty(queue)){
        p = (position*) PriorityQueuePop(queue);
        neighbors = getPossibleMoves(car->currentSpeed, p, map);
        printf("(%d %d %c) poss moves : \n", p->col, p->row, p->type);
        for(i=0; i<ArrayListGetLength(neighbors); i++){
            printf("\t(%d %d) with dist %d : \n", pNeighbor->col, pNeighbor->row, distance[pNeighbor->row][pNeighbor->col]);
            pNeighbor = (position*) ArrayListGet(neighbors, i);
            tmpDist = distance[p->row][p->col] + 1;
            if(tmpDist < distance[pNeighbor->row][pNeighbor->col] && !areEqualsPosition(p, pNeighbor)){
                printf("\tNew d %d\n", tmpDist);
                distance[pNeighbor->row][pNeighbor->col] = tmpDist;
                previous[pNeighbor->row][pNeighbor->col] = p;
                PriorityQueueChangePrioSpecificSearch(queue, pNeighbor, tmpDist, (int (*)(T, T)) areEqualsPosition);
            }
        }
    }

    arrivals = getAllArrivals(map);
    tmpDist = INT_MAX;
    position* best;

    for(i=0; i<ArrayListGetLength(arrivals); i++){
        p = (position*) ArrayListGet(arrivals, i);
        if(distance[p->row][p->col] < tmpDist){
            best = p;
        }
    }

    p = best;

    while(previous[p->row][p->col] != NULL){
        ArrayListAppend(path, previous[p->row][p->col]);
        p = previous[p->row][p->col];
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("TEMPS EXEC : %f\n", time_spent);

    return path;

}
