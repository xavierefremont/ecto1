/**
 * @author Xavière FREMONT & Julien CHEVRON
 * @version 0.0.1 / 27/04/2018
 */

/**
 * @file testMap.c
 * @brief Test map file
 */

#include "../../include/gps/map.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE* info;

void debug_print(char* text){
    fprintf(info, text);
    fflush(info);
}


void readDatas(){
    char c;
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n');
}


int main(){

    map* map = NULL;

    position mapSize;
 

    info = fopen("ecto1/etc/testMap.log", "w");
    debug_print("=====> START TESTMAP <=====\n");

	//TODO generate mapSize
 
    map = createMap(mapSize);
    if(map) {
	debug_print(" ---> CREATE MAP DONE \n");
    	fprintf(info, "\t -> x : %d, mapSize.x : %d\t y : %d mapSize.y : %d\n", map->size.x, mapSize->x, map->size.y, mapSize->y);
    	fflush(info);
    } else {
	debug_print(" ---> CREATE MAP ERROR\n");
    	return;
    }

	//TODO prepare plan
    generateMap(map);
    fprintf(info, "\t -> map : \n");
    fflush(info);
    debug_print("---> MAP PLAN\n");
    for(int i=0; i < map->size.y; i++){
        for(int j=0; j < map->size.x; j++){
            fprintf(info, "%c", map->plan[i][j]);
            fflush(info);
        }
        fprintf(info, "\n");
        fflush(info);
    }

	//todo generate rival position
    setPosition(map, position rival1, position rival2);
    debug_print(" ---> SET POSITION DONE \n");
    fprintf(info, "\t -> position r1 : %d,%d map->r1 : %d,%d\n", map->rival1->x, map->rival1->y, rival1->x, rival1->y);
    fflush(info);
    fprintf(info, "\t -> position r2 : %d,%d map->r2 : %d,%d\n", map->rival2->x, map->rival2->y, rival2->x, rival2->y);
    fflush(info);

    debug_print("=====> MAP END <=====\n");



}

