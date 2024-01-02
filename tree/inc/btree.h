#ifndef BTREE_H
#define BTREE_H

typedef struct bTreeNode* link;

typedef struct bTreeNode{
    int key;
    link left;
    link right;    
}bTreeNode;


int bTreeInsert(bTreeNode** ppRoot, int key);
void bTreeBuild(bTreeNode** ppRoot, int* sortedArray, int size);

/*Traversal algorithms*/
void bTreeInOrderTrav(bTreeNode* pRoot);
void bTreePreOrderTrav(bTreeNode* pRoot);
void bTreePostOrderTrav(bTreeNode* pRoot);


bTreeNode* bSearch(bTreeNode* pRoot, int target);

#endif 