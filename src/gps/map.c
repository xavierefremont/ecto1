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
 * Create a new postion structure pointer
 * @param x
 * @param y
 * @param the road type
 * @return the pointer of the created structure
 */
position* createPosition(int x, int y, char roadType) {

	position* p = (position*)malloc(sizeof(struct position));
	p->x = x;
	p->y = y;
	p->type = roadType;
	return p;

}

map* createMap(vector* mapSize) {

  map* map = NULL;
  map = (struct map*) malloc(sizeof(struct map));
  if(map){
    map->size = mapSize;
    map->plan = (position***) calloc(mapSize->y, sizeof(position**));
    for(int i=0;i<mapSize->y;i++)
      map->plan[i] = (position **) calloc(mapSize->x, sizeof(position*));
    if(map->plan){
      map->rival1 = NULL;
      map->rival2 = NULL;
      return map;
    }
  }

  return NULL;

}

/**
 * Initializes the map, i.e fill the plan in
 * @param map pointer to initialize
 */
void generateMap(map* map) {

  char read;
  int x = 0;
  int y;
  position* p = NULL;

  /* Read the map from stdin and fill the track into an array*/
  for (y = 0; y < map->size->y; y++) {
    while (fread(&read, sizeof(char), 1, stdin) == 1 && read != '\n'){
      p = createPosition(y, x, read);
      map->plan[y][x] = p;
      x++;
    }
    x = 0;
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

    printf("D : %d %d %c\n", target->x, target->y, target->type);
    printf("E : %d %d %c\n", map->plan[target->y][target->x]->x, map->plan[target->y][target->x]->y, map->plan[target->y][target->x]->type);

  if(map->plan[target->y][target->x]->type == '#' ||
     map->plan[target->y][target->x]->type == '~' ||
     map->plan[target->y][target->x]->type == '='){
	if ( !areEqualsPosition(target, map->rival1) ||
	     !areEqualsPosition(target, map->rival2)) {
	  return 1;
	}
  }
  return 0;

}


int isMoveCorrect(position* source, position* target){

  return 0;

}


void destroyMap(map* map){

  int x, y;
  map->rival1 = NULL;
  map->rival2 = NULL;

  for(y=0; y<map->size->y; y++){
    for(x=0; x<map->size->x; x++){
      destroyPosition(map->plan[y][x]);
    }
  }

  free(map->plan);

}


/**
 * Destroy a position structure
 * @param the position to destroy
 */
void destroyPosition(position* p){

  free(p);

}

