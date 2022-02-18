// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// 
// (c) Martin Porcheron
//     m.a.w.porcheron@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>

#include "constituency.h"

int main() {

  const int numConstituencies = 5;
  
  int mostNeighbours = 0;
  int leastNeighbours = 0;


  struct Constituency constituencies[numConstituencies];

  constructConstituency(
      &constituencies[0], "Swansea East",
      (unsigned int[]){1, 2, 3, 4}, 4);
  constructConstituency(
      &constituencies[1], "Swansea West",
      (unsigned int[]){0, 2}, 2);
  constructConstituency(
      &constituencies[2], "Gower",
      (unsigned int[]){0, 1, 3}, 3);
  constructConstituency(
      &constituencies[3], "Neath",
      (unsigned int[]){0, 2, 4}, 3);
  constructConstituency(
      &constituencies[4], "Aberavon",
      (unsigned int[]){0 , 3}, 2);


  struct Constituency * copy = copyConstituencies(constituencies, numConstituencies);
  int i = 0;
  for(i = 0; i < numConstituencies; i++) {
    destructConstituency(&constituencies[i]);
  }


  for (int i = 0; i < numConstituencies; i++) {
    printConstituency(&copy[i]);
    printf("\n");

    if (copy[i].numNeighbours > copy[mostNeighbours].numNeighbours) {
      mostNeighbours = i;
    }

    if (copy[i].numNeighbours < copy[leastNeighbours].numNeighbours) {
      leastNeighbours = i;
    }
  }

  printf("Constituency with the most neighbours is : %s", copy[mostNeighbours].name);
  printf("\n");

  for (int i = 0; i < copy[mostNeighbours].numNeighbours; i++) {
    printf("  %s", copy[copy[mostNeighbours].neighbours[i]].name);
    printf("\n");
  }

  printf("\n");

  printf("Constituency with the fewest neighbours is : %s", copy[leastNeighbours].name);
    printf("\n");


  for (int i = 0; i < copy[leastNeighbours].numNeighbours; i++) {
    printf("  %s", copy[copy[leastNeighbours].neighbours[i]].name);
    printf("\n");
  }

  printf("\n");

  for (int i = 0; i < numConstituencies; i++) {
    destructConstituency(&copy[i]);
  }
  
  return 0;
}