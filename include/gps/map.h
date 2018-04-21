//
// Created by julien on 18/04/18.
//

#ifndef __MAP_H
#define __MAP_H

typedef struct Position {
  int x;
  int y;
}Position;

typedef struct Map {
  Position size;
  char** plan;
}Map;

/**
 * Creates a structure map initializing the size sent by the driver
 * @param width of the map
 * @param height of the map
 * @return the new map
 */
Map createMap(int width, int heigth);

/**
 * Initializes the map, i.e fill the plan in
 * @param map pointer to initialize
 */
void initMap(struct Map*);

/**
 * Set int the map the current position of the three cars
 * @param car position ouf ourselves
 * @param rival1, rival2 position of the others
 */
void setPosition(Position car, Position rival1, Position rival2);

/**
 * Send to the GPS the structure of the map changed to estimate
 * speed and acceleration
 * @param the new map
 */
void sendToGPS(struct Map);

#endif //__MAP_H
