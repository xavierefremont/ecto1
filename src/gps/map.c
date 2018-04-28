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
map* createMap(int width, int heigth) {
  map* map;
  return map;
  //TODO : Calloc de map et assignation x et y dans la structure
}

/**
 * Initializes the map, i.e fill the plan in
 * @param map pointer to initialize
 */
void initMap(map* map) {
  //TODO : Lecture de la map sur stdin et remplissage tableau
}

/**
 * Set int the map the current position of the three cars
 * @param map pointer in which the positions will be set
 * @param car position ouf ourselves
 * @param rival1, rival2 position of the others
 */
void setPosition(map* map, position car, position rival1, position rival2) {
  //TODO : Mettre les voitures dans la map
}

/**
 * Send to the GPS the structure of the map changed to estimate
 * speed and acceleration
 * @param the new map
 */
void sendToGPS(map* map) {

}
