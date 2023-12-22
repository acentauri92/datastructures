#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;

typedef struct node{
    int data;
    link next;
    /*Previous only used by double lists*/
    link previous;
}node;

typedef struct{
    link head;
    link tail;
    int sizeOfList;
}list;

/*Single list prototypes*/

void insertAtHead(list* pList, int data);
void insertAtTail(list* pList, int data);
node* findTarget(list* pList, int target);
void deleteFirst(list* pList);
void deleteLast(list* pList);
void deleteTarget(list* pList, int target);
void reverseList(list* pList);

/*dlist prototypes*/
void addFirst(list* pList, int data);
void addLast(list* pList, int data);
void printReverse(list* pList);
void insertAfter(list* pList, int target, int data);
void insertBefore(list* pList, int target, int data);
void dListDeleteFirst(list* pList);
void dListDeleteLast(list* pList);
// void deleteTarget(list* pList);

/*Common prototypes*/
node* createNewNode(void);
void initList(list* pList);
void printList(list* pList);
void freeList(list* pList);
