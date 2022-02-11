#include "arrays.h"

double mean(int length, int *arr) {
    double total = 0;
    for (int i = 0; i < length; i++) {
        total = total + arr[i];
    }
    total = total / length;
    return total;
}