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

void deleteFirst(list* pList){
    node* current = NULL;
    // No elements present
    if(pList->sizeOfList == 0){
        printf("Cannot delete. List empty\n");
        return;
    }
    // Only one element present
    if(pList->sizeOfList == 1){
       current = pList->head;
       pList->head = pList->tail = NULL;
    }
    // All other cases
    else {
        current = pList->head;
        pList->head = pList->head->next;

    }
    free(current);
    pList->sizeOfList--;
}

void deleteLast(list* pList){
    node* current = NULL;
    //If list empty
    if(pList->sizeOfList == 0){
        printf("Cannot delete. List empty\n");
        return;
    }
    //If list has just one element
    if(pList->sizeOfList == 1){
        current = pList->tail;
        pList->tail = pList->head = NULL;
        free(current);
    }
    //All other cases
    else {
        current = pList->head;
        //Loop till last but one element
        while(current->next->next != NULL){
            current = current->next;
        }
        pList->tail = current;
        free(current->next);
        current->next = NULL;
    }
}

void deleteTarget(list* pList, int target){
    node* current;
    node* previous;
    //Empty list
    if(pList->sizeOfList == 0){
        printf("Cannot delete. List empty\n");
        return;  
    }
    else {
        current = pList->head;
        //Loop till target found and save previous node's address
        while(current->data != target){
            previous = current;
            current = current->next;
        }
        // If target is in first Node
        if(current == pList->head){
            deleteFirst(pList);
        }
        // If target is in last Node
        else if(current == pList->tail){
            deleteLast(pList);
        }
        else{
            previous->next = current->next;
            free(current);
        }
    }
}