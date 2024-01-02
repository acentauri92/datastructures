#include <stdio.h>
#include "btree.h"

bTreeNode* newTree = NULL;

int main(void){

    int sortedArray[10] = { 9, 15, 16, 18, 30, 44, 46, 48, 98, 110};
    bTreeBuild(&newTree, sortedArray, 10);
    bTreePostOrderTrav(newTree);
    printf("\n");

    bSearch(newTree, 148);
    return 0;
}