//
// Created by julien on 18/04/18.
//

#ifndef GRANDPRIX2018_3_0_3_CAR_H
#define GRANDPRIX2018_3_0_3_CAR_H

typedef struct car car;

struct car{
    int fuel;
    int nbrBoosts;
};

int deltaCarburantAcceleration(int accX, int accY, int velX, int velY, int dansSable);

#endif //GRANDPRIX2018_3_0_3_CAR_H
