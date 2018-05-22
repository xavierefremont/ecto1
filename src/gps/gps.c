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

/**
 * Initializes a new vector
 * @param x
 * @param y
 * @return vector pointer's
 */
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

/**
 * Initializes a new speed vector
 * @param src the origin's position
 * @param dest the destination's position
 * @return vector pointer's
 */
vector* vectorSpeed(position* src, position* dest) {

    int xMove = dest->col - src->col;
    int yMove = dest->row - src->row;

    vector* vMove = createVector(xMove, yMove);

    return vMove;

}

/**
 * Calculates the acceleration
 * @param src the origin's position
 * @param dest the destination's position
 * @param speed a vector
 * @return vector pointer's
 */
vector* calculateAcceleration(position* src, position* dest, vector* speed){
    vector* vMove = vectorSpeed(src, dest);
    int xSpeed = vMove->x - speed->x;
    int ySpeed = vMove->y - speed->y;
    vector* vSpeed = createVector(xSpeed, ySpeed);
    return vSpeed;

}

/**
 * Gets the norme of a vector
 * @param v the vector
 * @return float the norm
 */
float getVectorNorm(vector* v){

    return sqrt(pow(v->x,2)+pow(v->y,2));

}

/**
 * Gets the possible move of the car knowing the speed
 * @param speed vector
 * @param current position of the cap
 * @param map
 * @return ArrayList of the moves
 */
ArrayList getPossibleMoves(vector* speeed, position* current, map* map){

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
            if(getVectorNorm(v) < 2 && isCorrectPosition(map, p)){
                ArrayListAppend(possibleMoves, p);
            }
        }

        if(current->col + speeed->x + 1 < map->size->x && current->col + speeed->x + 1 >= 0
           && current->row + speeed->y - 1 < map->size->y && current->row + speeed->y - 1 >= 0) {
            p = map->plan[current->row + speeed->y - 1][current->col + speeed->x + 1];
            v = createVector(speeed->x + 1, speeed->y - 1);
            if(getVectorNorm(v) < 2 && isCorrectPosition(map, p)){
                ArrayListAppend(possibleMoves, p);
            }
        }

        if(current->col + speeed->x - 1 < map->size->x && current->col + speeed->x - 1 >= 0
           && current->row + speeed->y + 1 < map->size->y && current->row + speeed->y + 1 >= 0) {
            p = map->plan[current->row + speeed->y + 1][current->col + speeed->x - 1];
            v = createVector(speeed->x - 1, speeed->y + 1);
            if(getVectorNorm(v) < 2 && isCorrectPosition(map, p)){
                ArrayListAppend(possibleMoves, p);
            }
        }

        if(current->col + speeed->x - 1 < map->size->x && current->col + speeed->x - 1 >= 0
           && current->row + speeed->y - 1 < map->size->y && current->row + speeed->y - 1 >= 0) {
            p = map->plan[current->row + speeed->y - 1][current->col + speeed->x - 1];
            v = createVector(speeed->x - 1, speeed->y - 1);
            if(getVectorNorm(v) < 2 && isCorrectPosition(map, p)){
                ArrayListAppend(possibleMoves, p);
            }
        }

    }

    return possibleMoves;

}


/**
 * Gets arrivals on the map
 * @param map
 * @return ArrayList of arrivals
 */
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

/**
 * Gets the optimized path from the current position to arrival
 * @param map
 * @car to have current position
 * @return ArrayList of positions containig the path
 */
ArrayList calculateDijkstra(map* map, car* car){

    int x, y, i, tmpDist;
    int** distance;
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
            if(isCorrectPosition(map, p)) {
                PriorityQueueAdd(queue, p, distance[y][x]);
            }
        }
    }


    /*Algorithm*/
    while(!PriorityQueueIsEmpty(queue)){
        p = (position*) PriorityQueuePop(queue);
        neighbors = getPossibleMoves(s, p, map);
        for(i=0; i<ArrayListGetLength(neighbors); i++){
            pNeighbor = (position*) ArrayListGet(neighbors, i);
            tmpDist = distance[p->row][p->col] +  getDistance(p, pNeighbor);
            if(tmpDist < distance[pNeighbor->row][pNeighbor->col] && !areEqualsPosition(p, pNeighbor)){
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

    for(y = 0; y < map->size->y; y++) {
        free(distance[y]);
        free(previous[y]);
    }

    free(distance);
    free(previous);
    ArrayListDelete(arrivals);

    return path;

}

/**
 * Gets the distance from a position to another
 * @param p pointer
 * @param p2 pointer
 * @return int the distance
 */
int getDistance(position* p1, position* p2){
    int val;
    vector* v = vectorSpeed(p1, p2);
    val = abs(v->x) + abs(v->y);
    if(p2->type == '~'){
        val += 2;
    }
    return val;
}

/**
 * Gets the path using speed
 * @param map
 * @param car
 * @param path calculates with Dijkstra
 * @return Stack
 */
Stack getPathWithSpeed(map* map, car* car, ArrayList path){

    int y;
    Stack finalPath = newStack();
    position*** previous;
    position* p = NULL;

    previous = malloc(sizeof(position**) * map->size->y);
    for(y = 0; y < map->size->y; y++) {
        previous[y] = malloc(sizeof(position *) * map->size->x);
    }

    getFinalMoves(map, car->currentPosition, car->currentSpeed, car->fuel,  path, previous);

    p = ArrayListGet(path, 0);
    while(previous[p->row][p->col]){
        StackAdd(finalPath, p);
        p = previous[p->row][p->col];
    }

    for(y = 0; y < map->size->y; y++) {
        free(previous[y]);
    }
    free(previous);

    return finalPath;

}

/**
 * Checks if the move is authorized
 * @param map
 * @param current position of the car
 * @param speed vector's
 * @param fuel
 * @param path arraylist of positions
 * @param step
 * @param previous three entry tab's of position 
 * @return int boolean if the path is correct
 */
int checkMove(map* map, position* current, vector* speed, int fuel,
              ArrayList path, int step, position*** previous){

    int i;
    int tmp, tmpFuel;
    int minValue = INT_MAX;
    position* p = NULL;
    vector* acceleration = NULL;
    vector* newSpeed = NULL;

    if(current->type == '='){
        return step;
    }

    ArrayList moves = getPossibleMoves(speed, current, map);
    if(!ArrayListGetLength(moves)){
        return INT_MAX;
    }else{
        for(i=0; i<ArrayListGetLength(moves); i++){
            p = (position *) ArrayListGet(moves, i);

            if(ArrayListContains(path, p) && !areEqualsPosition(current, p)){
                newSpeed = vectorSpeed(current, p);
                acceleration = calculateAcceleration(current, p, speed);
                tmpFuel = fuel - calculatePresumedFuel(acceleration, newSpeed, p);
                if(tmpFuel > 0){
                    tmp = checkMove(map, p, newSpeed, tmpFuel, path, step+1, previous);
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

/**
 * Gets final moves of the path
 * @param map
 * @param current position
 * @param speed vector's
 * @param fuel
 * @param path arraylist of positions
 * @param step
 * @param previous three entry tab's of position 
 * @return int boolean if the path is correct
 */
int getFinalMoves(map* map, position* current, vector* speed, int fuel, ArrayList path,
                  position*** previous){

    int result, tmpFuel, i;
    float norm;
    position* p = NULL;
    vector* acceleration = NULL;
    vector* newSpeed = NULL;
    PriorityQueue queue = newPriorityQueue();

    if(current->type == '=' && fuel > 0){
        PriorityQueueDelete(queue);
        return 1;
    }
    if(fuel <= 5){
        PriorityQueueDelete(queue);
        return 0;
    }

    ArrayList moves = getPossibleMoves(speed, current, map);
    if(!ArrayListGetLength(moves)){
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
            if(isCorrectMove(map, current, newSpeed)){
                result = getFinalMoves(map, p, newSpeed, tmpFuel, path, previous);
                if(result){
                    previous[p->row][p->col] = current;
                    PriorityQueueDelete(queue);
                    return 1;
                }
            }



        }

    }
    PriorityQueueDelete(queue);
    return 0;
}
