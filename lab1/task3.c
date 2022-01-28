#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>
#define FIBONACCI_NUM 10

int main(int argc, char* argv[]) {


    if (argv[1] == NULL) {

        printf("ERROR: User did not provide a number input");

    } else {

        int commandLineArg = atoi(argv[1]);
        
        int result = fibonacci(commandLineArg);

        printf("Fibonacci of %d = %d\n", commandLineArg, result);

        return 0;

    }

}