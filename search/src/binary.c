#include "binary.h"

/*Binarch search using recursion*/
int binarySearchRec(int* array, int lower, int upper, int target){
    /*Target not found*/
    if(lower > upper){
        printf("Target not found.\n");
        return -1;
    }
    int middle = (lower + upper) / 2;

    /*Target found*/
    if(target == array[middle]){
        printf("Target found at index: %d\n", middle);
        return middle;
    }
    else if(target < array[middle]){
        upper = middle - 1;
    }
    else{
        lower = middle + 1;
    }
    /*Recursive call*/
    binarySearchRec(array, lower, upper, target);
}

/*Binarch search using iteration*/
int binarySearchIter(int* array, int size, int target){
    int lower = 0;
    int upper = size -1;
    while(lower <= upper){
        int middle = (lower + upper) / 2;
        if(target == array[middle]){
            printf("Target found at index: %d\n", middle);
            return middle;
        }
        else if (target > middle){
            lower = middle + 1;
        }
        else{
            upper = middle - 1;
        }
    }
    printf("Target not found in the array\n");
    return -1;
}