#include "list.h"

void addFirst(list* pList, int data){
    node* newNode = createNewNode();
    if(newNode != NULL){
        newNode->data = data;
        /* empty list*/
        if(pList->sizeOfList == 0){
            pList->head = pList->tail = newNode;
        }
        else {           
            newNode->next = pList->head;
            pList->head->previous = newNode;
            /*Prev ptr already initialized to NULL in createNewNode*/
            pList->head = newNode;
        }
        pList->sizeOfList++;
    }
    else{
        printf("Node addition failed!\n");
    }
}

void addLast(list* pList, int data){
    node* newNode = createNewNode();
    if(newNode != NULL){
        newNode->data = data;
        /*Empty list*/
        if(pList->sizeOfList == 0){
            pList->head = pList->tail = newNode;
        }
        else {   
            newNode->previous = pList->tail;
            pList->tail->next = newNode;
            pList->tail = newNode;
        }
        pList->sizeOfList++;
    }
    else{
        printf("Node addition failed\n");
    }
}

void printReverse(list* pList){
    if(pList->sizeOfList == 0){
        printf("Cannot print. List is empty\n");
        return;
    }
    else{
        node* current = pList->tail;
        while(current != NULL){
            printf("%d ", current->data);
            current = current->previous;
        }
        printf("\n");
    }
}

void insertAfter(list* pList, int target, int data){
    node* targetNode = findTarget(pList, target);
    if(targetNode != NULL){
        /*If target is at tail*/
        if(targetNode == pList->tail){
            addLast(pList, data);
        }
        else{
            /*List not empty and target found*/
            node* newNode = createNewNode();
            /*Update links*/
            newNode->next = targetNode->next;
            newNode->previous = targetNode;
            targetNode->next->previous = newNode;
            targetNode->next = newNode;
            /*Update data and size of list*/
            newNode->data = data;
            pList->sizeOfList++;
        }
    }
    else {
        printf("Insert failed. List empty or target not found.\n");
        return;
    }
}

void insertBefore(list* pList, int target, int data){
    node* targetNode = findTarget(pList, target);
    if(targetNode != NULL){
        /*If target is at head*/
        if(targetNode == pList->head){
            addFirst(pList, data);
        }
        else{
            /*List not empty and target found*/
            node* newNode = createNewNode();
            /*Update links*/
            targetNode->previous->next = newNode;
            newNode->previous = targetNode->previous;
            newNode->next = targetNode;
            targetNode->previous = newNode;
            /*Update data and size of list*/
            newNode->data = data;
            pList->sizeOfList++;
        }
    }
    else {
        printf("Insert failed. List empty or target not found.\n");
        return;
    }
}

void freeList(list* pList){
    if(pList->sizeOfList == 0){
        printf("Nothing to free. Empty list\n");
        return;
    }
    else {
        node *current, *toDelete;
        current = pList->head->next;
        toDelete = pList->head;

        while(current != NULL){
            free(toDelete);
            toDelete = current;
            current = current->next;
        }
        /*Free the last remaining node*/
        free(toDelete);
    }
}

void dListDeleteFirst(list* pList){
    /*If list empty*/
    if(pList->sizeOfList == 0){
        printf("Cannot delete. List empty\n");
        return;
    }
    /*If only one element is present*/
    else if(pList->sizeOfList == 1){
        free(pList->head);
        pList->head = pList->tail = NULL;
    }
    else{
        node* toDelete = pList->head;
        /*Update links*/
        pList->head = pList->head->next;
        pList->head->previous = NULL;
        free(toDelete);
    }
}

void dListDeleteLast(list* pList){
    /*If list empty*/
    if(pList->sizeOfList == 0){
        printf("Cannot delete. List empty\n");
        return;
    }
    /*If only one element is present*/
    else if(pList->sizeOfList == 1){
        free(pList->head);
        pList->head = pList->tail = NULL;
    }
    else{
        node* toDelete = pList->tail;
        /*Update links*/
        pList->tail = pList->tail->previous;
        pList->tail->next = NULL;
        free(toDelete);
    }
}