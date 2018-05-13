/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.2 / 28/04/2018
 */

/**
 * @file map.c
 * @brief Map file : everything concerning the track map
 */

#include "../../include/gps/map.h"

/**
 * Creates a structure map initializing the size sent by the driver
 * @param width of the map
 * @param height of the map
 * @return the new map
 */
map* createMap(position mapSize) {

  map* map = NULL;
  map = (struct map*) malloc(sizeof(struct map));
  if(map){
    map->size.x = mapSize.x;
    map->size.y = mapSize.y;
    map->plan = (char**) calloc(mapSize.y, sizeof(char*));
    for(int i=0;i<mapSize.y;i++)
      map->plan[i] = (char *) calloc(mapSize.x, sizeof(char));
    if(map->plan){
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
  int i;
  int j = 0;

  /* Read the map from stdin and fill the track into an array*/
  for (i = 0; i < map->size.y; i++) {
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
void setPosition(map* map, position rival1, position rival2) {
  map->rival1 = rival1;
  map->rival2 = rival2;
}

/**
 * Send to the GPS the structure of the map changed to estimate
 * speed and acceleration
 * @param the new map
 */
void sendToGPS(map* map) {

}
