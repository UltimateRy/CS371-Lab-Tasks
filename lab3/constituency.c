#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "constituency.h"

void constructConstituency(struct Constituency * const obj, char const *name, unsigned int const *neighbours, unsigned int const numOfNeighbours) {

    obj->name = NULL;
    obj->neighbours = NULL;
    obj->numNeighbours = 0;

    obj->name = malloc((strlen(name) * sizeof(char)) + 1);
    obj->neighbours = malloc(numOfNeighbours * sizeof(unsigned int));

    memcpy(obj->name, name, (strlen(name) * sizeof(char)) + 1);

    if (numOfNeighbours > 0) {
        memcpy(obj->neighbours, neighbours, numOfNeighbours * sizeof(unsigned int));
        obj->numNeighbours = numOfNeighbours;
    }
}

void destructConstituency(struct Constituency * const obj) {

    free(obj->name);
    free(obj->neighbours);

    obj->name = NULL;
    obj->neighbours = NULL;
    obj->numNeighbours = 0;
}

void printConstituency(struct Constituency * const obj) {

    printf("Name : %s", obj->name);
    printf("\n  Neighbours : %u", obj->numNeighbours);
    printf("\n");

    for (int i = 0; i < obj->numNeighbours; i++) {
        printf("        Neighbour : %u", obj->neighbours[i]);
        printf("\n");
    }
}

struct Constituency *copyConstituencies(struct Constituency obj[], const unsigned int numOfConstituencies) {
 
    struct Constituency * newConstituency = malloc(numOfConstituencies * sizeof(struct Constituency));

    for (int i = 0; i < numOfConstituencies; i++) {

        struct Constituency copy;
        constructConstituency(&copy, obj[i].name, obj[i].neighbours, obj[i].numNeighbours);
        memcpy(&newConstituency[i], &copy, sizeof(struct Constituency));
    }
    return newConstituency;
}