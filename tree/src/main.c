#include <stdio.h>
#include "btree.h"

bTreeNode* newTree = NULL;

int main(void){
    // bTreeInsert(&newTree, 8);
    // bTreeInsert(&newTree, 13);
    // bTreeInsert(&newTree, 18);
    // bTreeInsert(&newTree, 30);
    // bTreeInsert(&newTree, 32);
    // bTreeInsert(&newTree, 39);
    // bTreeInsert(&newTree, 13);

    int sortedArray[10] = { 9, 15, 16, 18, 30, 44, 46, 48, 98, 110};
    bTreeBuild(&newTree, sortedArray, 10);
    bTreePostOrderTrav(newTree);
    printf("\n");
    return 0;
}