// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// 
// (c) Martin Porcheron
//     m.a.w.porcheron@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "timestables.h"

int main(int argc , char *argv[]) {
	
	int *array[(MAX_TIMES_TABLE + 1) * MAX_TABLE_SIZE];

	for (int i = 0; i <= MAX_TIMES_TABLE; i++) {

		int *t = (int *) malloc(MAX_TABLE_SIZE * sizeof(int));

		array[i] = t;

		generateTable(i, array[i]);
	}

	printTables(array);

	for (int i = 0; i <= MAX_TIMES_TABLE; i++) {

		free(array[i]);

	}
	
	return 0;
}


