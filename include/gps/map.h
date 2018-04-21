//
// Created by julien on 18/04/18.
//

#ifndef __MAP_H
#define __MAP_H

typedef struct position position;
typedef struct map map;

struct position {
  int x;
  int y;
};

typedef struct map {
  position size;
  char** plan;
}map;

/**
 * Creates a structure map initializing the size sent by the driver
 * @param width of the map
 * @param height of the map
 * @return the new map
 */
map createMap(int width, int heigth);

/**
 * Initializes the map, i.e fill the plan in
 * @param map pointer to initialize
 */
void initMap(struct map*);

/**
 * Set int the map the current position of the three cars
 * @param car position ouf ourselves
 * @param rival1, rival2 position of the others
 */
void setPosition(position car, position rival1, position rival2);

/**
 * Send to the GPS the structure of the map changed to estimate
 * speed and acceleration
 * @param the new map
 */
void sendToGPS(struct map);

#endif //__MAP_H
