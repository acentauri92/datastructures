#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;

typedef struct node{
    int data;
    link next;
}node;

typedef struct{
    link head;
    link tail;
    int sizeOfList;
}list;

void initList(list* pList);
void insertAtHead(list* pList, int data);
void insertAtTail(list* pList, int data);
node* createNewNode(void);
void printList(list* pList);
node* findTarget(list* pList, int target);
void deleteFirst(list* pList);
void deleteLast(list* pList);
void deleteTarget(list* pList, int target);
