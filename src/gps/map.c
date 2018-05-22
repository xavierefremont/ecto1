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
position* createPosition(int col, int row, char roadType) {

	position* p = (position*)malloc(sizeof(struct position));
	p->col = col;
	p->row = row;
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
  int col = 0;
  int row;
  position* p = NULL;

  /* Read the map from stdin and fill the track into an array*/
  for (row = 0; row < map->size->y; row++) {
    while (fread(&read, sizeof(char), 1, stdin) == 1 && read != '\n'){
      p = createPosition(col, row, read);
      map->plan[row][col] = p;
      col++;
    }
    col = 0;
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

  if(isPositionFree(map, target)){
    return 1;
  }

  return 0;

}


int isPositionFree(map* map, position* target){

  if(target->type == '#' || target->type == '~' || target->type == '='
     || target->type == '1' || target->type == '2' || target->type == '3'){
	if ( !areEqualsPosition(target, map->rival1) &&
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


void line(int x1, int y1, int x2, int y2, infoLine *data) {
  data->posStart.x = x1;
  data->posStart.y = y1;
  data->posActual.x = x1 + 0.5;
  data->posActual.y = y1 + 0.5;
  data->posEnd.x = x2;
  data->posEnd.y = y2;
  int adxi, adyi, dxi, dyi;
  adxi = dxi = x2 - x1;
  adyi = dyi = y2 - y1;
  if (adxi < 0)
    adxi = -dxi;
  if (adyi < 0)
    adyi = -dyi;
  data->pos = 0;
  data->len = adxi;
  if (adyi > adxi)
    data->len = adyi;
  data->delta.x = ((float)dxi) / data->len;
  data->delta.y = ((float)dyi) / data->len;
}


int nextPoint(infoLine *data, pos2Dint *point, int sens) {
  if (sens > 0) {
    if (data->pos == data->len) {
      point->x = data->posEnd.x;
      point->y = data->posEnd.y;
      return -1; // La fin de la ligne est atteinte
    }
    data->posActual.x += data->delta.x;
    data->posActual.y += data->delta.y;
    point->x = ((int)data->posActual.x);
    point->y = ((int)data->posActual.y);
    data->pos++;
    return 1; // un nouveau point est déterminé.
  }
  if (sens < 0) {
    if (data->pos == 0) {
      point->x = data->posStart.x;
      point->y = data->posStart.y;
      return -1; // La fin de la ligne est atteinte
    }
    data->posActual.x -= data->delta.x;
    data->posActual.y -= data->delta.y;
    point->x = ((int)data->posActual.x);
    point->y = ((int)data->posActual.y);
    data->pos--;

    return 1; // un nouveau point est déterminé.
  }
  return 1; // Avec sens==0, il n'y a pas de déplacement
}


/**
 * Verify if the path has no collision
 * @param map
 * @param p
 * @param speed
 * @return
 */
int verifyPath(map* map, position* p, vector* speed) {

  int res = 1;
  int posX0 = p->col;
  int posY0 = p->row;
  int velX = speed->x;
  int velY = speed->y;
  int posX1 = posX0 + velX;
  int posY1 = posY0 + velY;
  infoLine vline;
  line(posX0, posY0, posX1, posY1, &vline);
  pos2Dint pos;
  while (nextPoint(&vline, &pos, +1) > 0) {
    if (pos.x == posX0 && pos.y == posY0)
      continue;
    if (!isCorrectPosition(map, map->plan[pos.y][pos.x])) {
      res = 0;
      break;
    }
  }
  return res;
}
