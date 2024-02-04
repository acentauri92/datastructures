#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

int bTreeInsert(bTreeNode** ppRoot, int key){
    /*Empty tree. Create new node and updae the root node ptr*/
    if(*ppRoot == NULL){
        bTreeNode* newNode = (bTreeNode*) malloc(sizeof(bTreeNode));

        if(NULL == newNode){
            printf("New node could not be created.\n");
            return -1;
        }
        else{
            newNode->key = key;
            newNode->left = newNode->right = NULL;
            *ppRoot = newNode;       
        }
    }

    else if(key > (*ppRoot)->key ){
        /*Insert right*/
        bTreeInsert( &((*ppRoot)->right), key);
    }

    else if(key < (*ppRoot)->key ){
        /*Insert left*/
        bTreeInsert( &((*ppRoot)->left), key);
    }
    
    else{
        printf("Duplicate key %d. Cannot insert\n", key);
    }

    return 0;
}


bTreeNode* insertToBST(bTreeNode* root, int data){
    if(root == NULL){
        root = (bTreeNode*) malloc(sizeof(bTreeNode));
        root->left = root->right = NULL;
        return root;
    }

    else if(data > root->key){
        root->right = insertToBST(root->right, data);
    }
    else{
        root->left = insertToBST(root->left, data);
    }
    return root;
}

void bTreeBuild(bTreeNode** ppRoot, int* sortedArray, int size){
    for(int i = 0; i < size; i++){
        bTreeInsert(ppRoot, sortedArray[i]);
    }
}

/*Traversal algorithms*/
void bTreeInOrderTrav(bTreeNode* pRoot){
    /*Empty tree*/
    if(pRoot == NULL){
        return;
    }
    else{
        bTreeInOrderTrav(pRoot->left);
        printf("%d ", pRoot->key);
        bTreeInOrderTrav(pRoot->right);
    }
}

void bTreePreOrderTrav(bTreeNode* pRoot){
    /*Empty tree*/
    if(pRoot == NULL){
        return;
    }
    else{
        printf("%d ", pRoot->key);
        bTreeInOrderTrav(pRoot->left);     
        bTreeInOrderTrav(pRoot->right);
    }
}
void bTreePostOrderTrav(bTreeNode* pRoot){
    /*Empty tree*/
    if(pRoot == NULL){
        return;
    }
    else{
        bTreeInOrderTrav(pRoot->left);     
        bTreeInOrderTrav(pRoot->right);
        printf("%d ", pRoot->key);
    }
}
