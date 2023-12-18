/**
 * @file       list.c
 * @author     Dheeraj Reddy J
 * @brief      Linked list implementation
 * @version    0.1
 * @date       18-12-2023
 * 
 * 
 */

#include "list.h"

void initList(list* pList){
    pList->head = pList->tail = NULL;
    pList->sizeOfList = 0;
}

void insertAtHead(list* pList, int data){
    node* newNode = createNewNode();
    //Empty list- head and tail point to same node
    if(pList->sizeOfList == 0){
        pList->head = pList->tail = newNode;
    }
    else {
        newNode->next = pList->head;
        pList->head = newNode;
    }
    newNode->data = data;
    pList->sizeOfList++;
}

void insertAtTail(list* pList, int data){
    node* newNode = createNewNode();
    //Empty list- head and tail point to same node
    if(pList->sizeOfList == 0){
        pList->head = pList->tail = newNode;
    }
    else{
        //Assign the new node to current tail
        pList->tail->next = newNode;
        //Update the new tail
        pList->tail = newNode;
    }
    newNode->data = data;
    pList->sizeOfList++;
}

node* createNewNode(void){
    node* newNode = (node*) malloc(sizeof(node));
    if(newNode == NULL){
        printf("Error: Unable to alloc memory\n");
        return NULL;
    }
    return newNode;
}

void printList(list* pList){
    node* current = pList->head;
    if(pList->sizeOfList == 0){
        printf("Cannot print. List is empty!\n");
        return;
    }
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

node* findTarget(list* pList, int target){
    if(pList->sizeOfList == 0){
        printf("Could not find target. List is empty.\n");
        return NULL;
    }
    else {
        node* current = pList->head;
        while(current != NULL){
            if(current->data == target){
                return current;
            }
            current = current->next;
        }
        printf("Target not found in the list\n");
        return NULL;
    }
}

