//
// Created by julien on 18/04/18.
//

#include "../../include/car/car.h"


int deltaCarburantAcceleration(int accX, int accY, int velX, int velY, int dansSable) {
    int valeur = accX * accX + accY * accY;
    valeur += (int)(sqrt(velX * velX + velY * velY) * 3.0 / 2.0);
    if (dansSable)
        valeur += 1;
    return -valeur;
}
