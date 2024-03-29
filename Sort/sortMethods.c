/*Merge sort implementation*/
#include <stdio.h>
#include <stdlib.h>
 
#define leftArraySize       4
#define rightArraySize      7
#define CombinedSize        ( (leftArraySize) + (rightArraySize) )

int less(int a, int b){
    return (a < b);
}

 void merge(int* merged, int* left, int leftSize, int* right, int rightSize){
    int i, j, k;
    for(i = 0, j = 0, k = 0; k < (leftSize + rightSize); k++){
        //left array done
        if(i == leftSize){
            merged[k] = right[j++];
            continue;
        }
        //right array done
        if(j == rightSize){
            merged[k] = left[i++];
            continue;
        }
        merged[k] = ( less(left[i], right[j]) ? left[i++] : right[j++] );
    }
    
 }

 void mergeSort(int* array, int arraySize){
    int mid;
    int *left, *right;

    if(arraySize  < 2)
        return;

    mid = arraySize/2;

    left = (int*) malloc( mid  * sizeof(int));
    right = (int*) malloc((arraySize - mid) * sizeof(int));

    for(int i = 0; i < mid; i++)
        left[i] = array[i];
    for(int i = mid;  i < arraySize; i++)
        right[i - mid] = array[i];
    
    mergeSort(left, mid);
    mergeSort(right, arraySize - mid);
    
    merge(array, left, mid, right, arraySize - mid);

    free(left);
    free(right);

 }

 void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* array, int size){
    for(int i = 0; i < size-1; i++){
        //Take first index as min value
        int minValue = i;

        //Find min value
        for(int j = i+1; j < size; j++){
            if(array[j] < array[minValue]){
                minValue = j;
            }
        }

        swap(array + i, array + minValue);  
    }
}

void bubbleSort(int* array, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1-i; j++){
            if(array[j] > array[j+1]){
                swap(array + j, array + (j+1));
            }
        }
    }
}

void insertionSort(int* array, int size){
    int i = 0;
    for(i = 1; i < size; i++){
        int j = i;
        while (j>=0 && (array[j] < array[j-1]) ){
            swap(array + j, array +(j-1));
            j--;
        } 
    }
}
