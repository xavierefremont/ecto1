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

//TODO : CHANGE


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

    return vMove;

}

vector* calculateAcceleration(position* src, position* dest, vector* speed){

    vector* vMove = vectorSpeed(src, dest);

    int xSpeed = vMove->x - speed->x;
    int ySpeed = vMove->y - speed->y;
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

    //speeed = createVector(0,0);
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


ArrayList calculateDijkstra(FILE* info, map* map, car* car){

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
    ArrayList path = newArrayList(sizeof(struct position));

    //for step by step
    s = createVector(0, 0);

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
        //s = speed[p->row][p->col];
        neighbors = getPossibleMoves(info, s, p, map);
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
        ArrayListAppend(path, p);
        p = previous[p->row][p->col];
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(info, "TEMPS EXEC : %f\n", time_spent);
    fflush(info);

    return path;

}

int getDistance(position* p1, position* p2){
    /*float dist;
    dist = sqrt(pow(p2->row - p1->row,2) + pow(p2->col - p1->col,2));
    if(dist == 1){
        return 2;
    }else{
        return 3;
    }*/
    int val;
    vector* v = vectorSpeed(p1, p2);
    val = abs(v->x) + abs(v->y);
    if(p2->type == '~'){
        val++;
    }
    return val;
}


Stack getPathWithSpeed(FILE* info, map* map, car* car, ArrayList path){

    int y;
    Stack finalPath = newStack();
    position*** previous;
    position* p = NULL;

    previous = malloc(sizeof(position**) * map->size->y);
    for(y = 0; y < map->size->y; y++) {
        previous[y] = malloc(sizeof(position *) * map->size->x);
    }

    for(int i=0; i<ArrayListGetLength(path); i++){
        p = (position*) ArrayListGet(path, i);
        fprintf(info, "%d %d\n", p->col, p->row);
        fflush(info);
    }
    fprintf(info, "BEFORE\n");
    fflush(info);

    /*
    int step = checkMove(info, map, car->currentPosition, car->currentSpeed, car->fuel, path, 0, previous);
    if(step == 0){
        return NULL;
    }
    */

    getFinalMoves(info, map, car->currentPosition, car->currentSpeed, car->fuel,  path, previous);

    fprintf(info, "AFTER\n");
    fflush(info);
    p = ArrayListGet(path, 0);
    while(previous[p->row][p->col]){
        fprintf(info, "%d %d\n", p->col, p->row);
        fflush(info);
        StackAdd(finalPath, p);
        p = previous[p->row][p->col];
    }

    return finalPath;

}


int checkMove(FILE* info, map* map, position* current, vector* speed, int fuel,
              ArrayList path, int step, position*** previous){

    int i;
    int tmp, tmpFuel;
    int minValue = INT_MAX;
    position* p = NULL;
    vector* acceleration = NULL;
    vector* newSpeed = NULL;

    fprintf(info, "P : %d %d, S : %d %d, F : %d, N : %d\n", current->col, current->row, speed->x, speed->y, fuel, step);

    if(current->type == '='){
        fprintf(info, "ARR\n");
        fflush(info);
        return step;
    }

    ArrayList moves = getPossibleMoves(NULL, speed, current, map);
    if(!ArrayListGetLength(moves)){
        fprintf(info, "JEJ\n");
        fflush(info);
        return INT_MAX;
    }else{
        for(i=0; i<ArrayListGetLength(moves); i++){
            p = (position *) ArrayListGet(moves, i);
            fflush(info);
            if(ArrayListContains(path, p) && !areEqualsPosition(current, p)){
                newSpeed = vectorSpeed(current, p);
                acceleration = calculateAcceleration(current, p, speed);
                tmpFuel = fuel - calculatePresumedFuel(acceleration, newSpeed, p);
                if(tmpFuel > 0){
                    tmp = checkMove(info, map, p, newSpeed, tmpFuel, path, step+1, previous);
                    if(minValue > tmp){
                        minValue = tmp;
                        previous[p->row][p->col] = current;
                    }
                }
            }
        }
        return minValue;
    }

}


int getFinalMoves(FILE* info, map* map, position* current, vector* speed, int fuel, ArrayList path,
                  position*** previous){

    int result, tmpFuel, i;
    float norm;
    position* p = NULL;
    vector* acceleration = NULL;
    vector* newSpeed = NULL;
    PriorityQueue queue = newPriorityQueue();

    fprintf(info, "P : %d %d, S : %d %d, F : %d\n", current->col, current->row, speed->x, speed->y, fuel);

    if(current->type == '=' && fuel >= 0){
        fprintf(info, "ARR\n");
        fflush(info);
        return 1;
    }
    if(fuel < 0){
        fprintf(info, "FUEL OFF\n");
        fflush(info);
        return 0;
    }

    ArrayList moves = getPossibleMoves(NULL, speed, current, map);
    if(!ArrayListGetLength(moves)){
        fprintf(info, "NO MOVES\n");
        fflush(info);
        return 0;
    }else{
        for(i=0; i<ArrayListGetLength(moves); i++){
            p = (position *) ArrayListGet(moves, i);
            if(ArrayListContains(path, p) && !areEqualsPosition(current, p)){
                newSpeed = vectorSpeed(current, p);
                norm = (abs(newSpeed->x) + abs(newSpeed->y));
                if(norm <= 3){
                    PriorityQueueAdd(queue, p, -norm);
                }

            }
        }
        while(!PriorityQueueIsEmpty(queue)){
            p = (position*) PriorityQueuePop(queue);
            newSpeed = vectorSpeed(current, p);
            acceleration = calculateAcceleration(current, p, speed);
            tmpFuel = fuel - calculatePresumedFuel(acceleration, speed, p);
            if(verifyPath(map, current, newSpeed)){
                result = getFinalMoves(info, map, p, newSpeed, tmpFuel, path, previous);
                if(result){
                    previous[p->row][p->col] = current;
                    return 1;
                }
            }



        }

    }
    return 0;
}
