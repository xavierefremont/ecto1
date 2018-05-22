/**
 * @author Xavière FREMONT
 * @author Julien CHEVRON
 * @version 0.0.1 / 28/04/2018
 */

/**
 * @file structs.h
 * @brief Header containing all structures used in the program
 */

#ifndef _STRUCTS_H
#define _STRUCTS_H

typedef struct vector vector;
typedef struct position position;
typedef struct map map;
typedef struct car car;


struct vector{
    int x;
    int y;
};

struct position {
    int col;
    int row;
    char type;
};

typedef struct map {
  vector* size;
  position*** plan;
  position* rival1;
  position* rival2;
};

struct car{
    position* previousPosition;
    position* currentPosition;
    vector* currentSpeed;
    int fuel;
    int presumedFuel;
    int nbrBoosts;
};

/**
 * @brief Structure pour le position d'un element sur la map avec des
 * coordonnees entieres
 */
typedef struct {
    int x;
    int y;
} pos2Dint;

/**
 * @brief Structure pour une position 2D avec des coordonnees flottantes
 */
typedef struct {
    float x;
    float y;
} pos2Dfloat;

/**
 * @brief Structure permettant de definir un segment et de se deplacer le long
 */
typedef struct {
    pos2Dint posStart;    /*< Debut du segment */
    pos2Dint posEnd;      /*< Fin du segment */
    pos2Dfloat posActual; /*< Position Actuel sur le segment */
    pos2Dfloat delta;     /*< Variation en x et en y pour le deplacement */
    int len;              /*< Longueur suivant l'axe principale */
    int pos;              /*< Position de reference sur la ligne */
} infoLine;



#endif //_STRUCTS_H
