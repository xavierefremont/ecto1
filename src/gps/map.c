/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file map.c
 * @brief Map file : everything concerning the track map
 */

#include "../../include/util/ArrayList.h"
#include "../../include/gps/map.h"
#include "../../include/gps/gps.h"
#include "../../include/car/car.h"



/**
 * Initializes the map, i.e fill the plan in
 * @param map pointer to initialize
 */
void generateMap(map* map) {

  char read;
  int i;
  int j = 0;

  /* Read the map from stdin and fill the track into an array*/
  for (i = 0; i < map->size->y; i++) {
    while (fread(&read, sizeof(char), 1, stdin) == 1 && read != '\n'){
      map->plan[i][j] = read;
      j++;
    }
    j = 0;
  }

}


/**
 * Set in the map the current position of the rivals' cars
 * @param map pointer in which the positions will be set
 * @param rival1, rival2 position of the others
 */
void setPosition(map* map, position* rival1, position* rival2) {
  map->rival1 = rival1;
  map->rival2 = rival2;
}


int isCorrectPosition(map* map, position* target){

  if(isPositionInMap(map, target)){
    if(isPositionFree(map, target)){
      return 1;
    }
  }

  return 0;

}


int isPositionInMap(map* map, position* target){

  if(target->x < map->size->x && target->x > 0 && target->y < map->size->y && target->y > 0){
    return 1;
  }else{
    return 0;
  }

}


int isPositionFree(map* map, position* target){

  if(map->plan[target->y][target->x] == '#' ||
     map->plan[target->y][target->x] == '~' ||
     map->plan[target->y][target->x] == '='){
    //TODO : Check on the map structure if a car is in the position
    return 1;
  }

  return 0;

}
