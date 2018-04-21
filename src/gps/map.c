//
// Created by julien on 18/04/18.
//

#include "../../include/gps/map.h"

/**reading the map**/
void readMap() {
    int i, j;

    /**Fuel in the car's tank**/
    int fuel;

    /** Reading size and fuel **/
    fscanf(stdin, "%d %d %d", &tx, &ty, &fuel);

    for (i = 0; i < ty; i++) {
        for (j = 0; j< tx; j++ ) {         /* Lecture de la carte ligne par ligne */
            while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n')
                fprintf(info, "%c", c);
            fprintf(info, "\n");
        }
    }
}