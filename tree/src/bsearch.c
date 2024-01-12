#include "btree.h"
#include <stdio.h>

bTreeNode* bSearch(bTreeNode* pRoot, int target){
    if(pRoot == NULL){
        printf("Empty tree\n");
        return NULL;
    }
    else if(target == pRoot->key){
        printf("Target %d found\n", pRoot->key);
        return pRoot;
    }
    else if(target > pRoot->key){
        bSearch(pRoot->right, target);
    }
    else{
        bSearch(pRoot->left, target);
    }
}