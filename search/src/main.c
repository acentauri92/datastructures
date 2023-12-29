#include "binary.h"

#define ARRAY_SIZE 10
int array[ARRAY_SIZE] = {20, 2, 3, 5, 6, 7, 9, 14, 16, 19};

int main(void){

    binarySearchIter(array, ARRAY_SIZE, 19);
    return 0;
}