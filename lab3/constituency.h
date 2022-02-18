#ifndef constituency_h

#define constituency_h

struct Constituency {

    char *name;
    unsigned int *neighbours;
    unsigned int numNeighbours;

};

void constructConstituency(struct Constituency *, char const *name, unsigned int const *neighbours, unsigned int const numOfNeighbours);

void destructConstituency(struct Constituency * const obj);

void printConstituency(struct Constituency * const obj);

struct Constituency* copyConstituencies(struct Constituency obj[], const unsigned int);


#endif