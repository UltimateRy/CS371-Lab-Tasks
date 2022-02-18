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


  for (int i = 0; i < numConstituencies; i++) {
    printConstituency(&constituencies[i]);
    printf("\n");

    if (constituencies[i].numNeighbours > constituencies[mostNeighbours].numNeighbours) {
      mostNeighbours = i;
    }

    if (constituencies[i].numNeighbours < constituencies[leastNeighbours].numNeighbours) {
      leastNeighbours = i;
    }
  }

  printf("Constituency with the most neighbours is : %s", constituencies[mostNeighbours].name);
  printf("\n");

  for (int i = 0; i < constituencies[mostNeighbours].numNeighbours; i++) {
    printf("  %s", constituencies[constituencies[mostNeighbours].neighbours[i]].name);
    printf("\n");
  }

  printf("\n");

  printf("Constituency with the fewest neighbours is : %s", constituencies[leastNeighbours].name);
    printf("\n");


  for (int i = 0; i < constituencies[leastNeighbours].numNeighbours; i++) {
    printf("  %s", constituencies[constituencies[leastNeighbours].neighbours[i]].name);
    printf("\n");
  }

  printf("\n");

  for (int i = 0; i < numConstituencies; i++) {
    destructConstituency(&constituencies[i]);
  }
  
  return 0;
}