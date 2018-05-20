/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file gps.c
 * @brief GPS file : Calculate the car movement with algorithm
 */

#include "../../include/util/Stack.h"
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

vector* vectorSpeed(position* src, position* dest) {

    int xMove = dest->col - src->col;
    int yMove = dest->row - src->row;

    vector* vMove = createVector(xMove, yMove);
}

vector* calculateVector(car* car, position* dest){

  vector* vMove = vectorSpeed(car->currentPosition, dest);

    int xSpeed = vMove->x - car->currentSpeed->x;
    int ySpeed = vMove->y - car->currentSpeed->y;
    vector* vSpeed = createVector(xSpeed, ySpeed);
    return vSpeed;

}


float getVectorNorm(vector* v){

    return sqrt(pow(v->x,2)+pow(v->y,2));

}


ArrayList getPossibleMoves(FILE* info, vector* speeed, position* current, map* map){

    //TODO : Get the real possible position and not all

    ArrayList possibleMoves = newArrayList(sizeof(position));
    position* p = NULL;

   /* vector* speeed = createVector(0,0);*/
    vector* v = NULL;


    if(current->col + speeed->x < map->size->x && current->col + speeed->x >= 0
       && current->row + speeed->y < map->size->y && current->row + speeed->y >= 0){
        p = map->plan[current->row + speeed->y][current->col + speeed->x];
        v = createVector(speeed->x, speeed->y);
        if(getVectorNorm(v) < 5 && isCorrectPosition(map, p)){
            ArrayListAppend(possibleMoves, p);
        }
    }

    if(current->col + speeed->x + 1 < map->size->x && current->col + speeed->x + 1 >= 0
       && current->row + speeed->y < map->size->y && current->row + speeed->y >= 0) {
        p = map->plan[current->row + speeed->y][current->col + speeed->x + 1];
        v = createVector(speeed->x + 1, speeed->y);
        if(getVectorNorm(v) < 5 && isCorrectPosition(map, p)){
            ArrayListAppend(possibleMoves, p);
        }
    }

    if(current->col + speeed->x - 1 < map->size->x && current->col + speeed->x - 1 >= 0
       && current->row + speeed->y < map->size->y && current->row + speeed->y >= 0) {
        p = map->plan[current->row + speeed->y][current->col + speeed->x - 1];
        v = createVector(speeed->x - 1, speeed->y);
        if(getVectorNorm(v) < 5 && isCorrectPosition(map, p)){
            ArrayListAppend(possibleMoves, p);
        }
    }

    if(current->col + speeed->x < map->size->x && current->col + speeed->x >= 0
       && current->row + speeed->y + 1 < map->size->y && current->row + speeed->y + 1 >= 0) {
        p = map->plan[current->row + speeed->y + 1][current->col + speeed->x];
        v = createVector(speeed->x, speeed->y + 1);
        if(getVectorNorm(v) < 5 && isCorrectPosition(map, p)){
            ArrayListAppend(possibleMoves, p);
        }
    }

    if(current->col + speeed->x < map->size->x && current->col + speeed->x >= 0
       && current->row + speeed->y < map->size->y - 1 && current->row + speeed->y - 1 >= 0) {
        p = map->plan[current->row + speeed->y - 1][current->col + speeed->x];
        v = createVector(speeed->x, speeed->y - 1);
        if(getVectorNorm(v) < 5 && isCorrectPosition(map, p)){
            ArrayListAppend(possibleMoves, p);
        }
    }

    if(current->type != '~'){

        if(current->col + speeed->x + 1 < map->size->x && current->col + speeed->x + 1 >= 0
           && current->row + speeed->y + 1 < map->size->y && current->row + speeed->y + 1 >= 0) {
            p = map->plan[current->row + speeed->y + 1][current->col + speeed->x + 1];
            v = createVector(speeed->x + 1, speeed->y + 1);
            if(getVectorNorm(v) < 5 && isCorrectPosition(map, p)){
                ArrayListAppend(possibleMoves, p);
            }
        }

        if(current->col + speeed->x + 1 < map->size->x && current->col + speeed->x + 1 >= 0
           && current->row + speeed->y - 1 < map->size->y && current->row + speeed->y - 1 >= 0) {
            p = map->plan[current->row + speeed->y - 1][current->col + speeed->x + 1];
            v = createVector(speeed->x + 1, speeed->y - 1);
            if(getVectorNorm(v) < 5 && isCorrectPosition(map, p)){
                ArrayListAppend(possibleMoves, p);
            }
        }

        if(current->col + speeed->x - 1 < map->size->x && current->col + speeed->x - 1 >= 0
           && current->row + speeed->y + 1 < map->size->y && current->row + speeed->y + 1 >= 0) {
            p = map->plan[current->row + speeed->y + 1][current->col + speeed->x - 1];
            v = createVector(speeed->x - 1, speeed->y + 1);
            if(getVectorNorm(v) < 5 && isCorrectPosition(map, p)){
                ArrayListAppend(possibleMoves, p);
            }
        }

        if(current->col + speeed->x - 1 < map->size->x && current->col + speeed->x - 1 >= 0
           && current->row + speeed->y - 1 < map->size->y && current->row + speeed->y - 1 >= 0) {
            p = map->plan[current->row + speeed->y - 1][current->col + speeed->x - 1];
            v = createVector(speeed->x - 1, speeed->y - 1);
            if(getVectorNorm(v) < 5 && isCorrectPosition(map, p)){
                ArrayListAppend(possibleMoves, p);
            }
        }

    }

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


Stack calculateDijkstra(FILE* info, map* map, car* car){

    fprintf(info, "CALCUL\n");
    fflush(info);

    clock_t begin = clock();
    int x, y, i, tmpDist;
    int** distance;
    vector*** speed;
    vector* s = NULL;
    position*** previous;
    position* p = NULL;
    position* pNeighbor = NULL;
    PriorityQueue queue =  newPriorityQueue();
    ArrayList neighbors = NULL;
    ArrayList arrivals = NULL;
    Stack path = newStack();


    /*Initialisation of the algorithm*/
    distance = malloc(sizeof(int*) * map->size->y);
    previous = malloc(sizeof(position**) * map->size->y);
    speed = malloc(sizeof(vector**) * map->size->y);
    
    for(y = 0; y < map->size->y; y++){
      speed[y] = malloc(sizeof(vector*) * map->size->x);
        distance[y] = malloc(sizeof(int) * map->size->x);
        previous[y] = malloc(sizeof(position*) * map->size->x);
        for (x = 0; x < map->size->x; x++) {
            p = map->plan[y][x];
            previous[y][x] = NULL;
	    speed[y][x] = NULL;
            if(areEqualsPosition(car->currentPosition, p)){
                distance[y][x] = 0;
		speed[y][x] = car->currentSpeed;
            }else{
                distance[y][x] = INT_MAX;
            }
            if(isCorrectPosition(map, p)) {
                PriorityQueueAdd(queue, p, distance[y][x]);
            }
        }
    }


    /*Algorithm*/
    while(!PriorityQueueIsEmpty(queue)){
        p = (position*) PriorityQueuePop(queue);
	s = speed[p->row][p->col];
	fprintf(info, "p %dcol %drow --> sx %d, sy %d\n", p->col, p->row, s->x, s->y);
	fflush(info);
        neighbors = getPossibleMoves(info, s, p, map);
	if(!ArrayListGetLength(neighbors)) {
	   fprintf(info, "CALCULnexxxxx\n");
    fflush(info);
	  s = createVector(0,0);
	  neighbors = getPossibleMoves(info, s, p, map);
	}
        for(i=0; i<ArrayListGetLength(neighbors); i++){
            pNeighbor = (position*) ArrayListGet(neighbors, i);
            tmpDist = distance[p->row][p->col] +  getDistance(p, pNeighbor);
            if(tmpDist < distance[pNeighbor->row][pNeighbor->col] && !areEqualsPosition(p, pNeighbor)){
	      speed[pNeighbor->row][pNeighbor->col] = vectorSpeed(p, pNeighbor);
                distance[pNeighbor->row][pNeighbor->col] = tmpDist;
                previous[pNeighbor->row][pNeighbor->col] = p;
                PriorityQueueChangePrioSpecificSearch(queue, pNeighbor, tmpDist, (int (*)(T, T)) areEqualsPosition);
            }
        }
    }
    fprintf(info, "DEB algo");
    fflush(info);
    
    arrivals = getAllArrivals(map);
    tmpDist = INT_MAX;
    position* best;

    for(i=0; i<ArrayListGetLength(arrivals); i++){
        p = (position*) ArrayListGet(arrivals, i);
        if(distance[p->row][p->col] < tmpDist){
            tmpDist = distance[p->row][p->col];
            best = p;
        }
    }

    p = best;

    while(previous[p->row][p->col] != NULL){
        StackAdd(path, p);
        p = previous[p->row][p->col];
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    /*printf("TEMPS EXEC : %f\n", time_spent);*/

    return path;

}

int getDistance(position* p1, position* p2){
    float dist;
    dist = sqrt(pow(p2->row - p1->row,2) + pow(p2->col - p1->col,2));
    if(dist == 1){
        return 2;
    }else{
        return 3;
    }
}
