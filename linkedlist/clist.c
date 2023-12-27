#include "list.h"

void initCircularList(Circularlist* pClist){
    pClist->head = NULL;
    pClist->sizeOfList = 0;
}

void addNodeClist(Circularlist* pClist, int data){
    node* newNode = createNewNode();

    if(newNode != NULL){
        newNode->data = data;
        /*Empty list. Head and next point ot the same node*/
        if(pClist->sizeOfList == 0){
            pClist->head = newNode;
            pClist->head->next = newNode;
        }

        /*All other cases. Node inserted immediately after first node*/
        else{
            newNode->next = pClist->head->next;
            pClist->head->next = newNode;
        }
        /*Update size*/
        pClist->sizeOfList++;
    }
    else{
        /*memory alloc failed*/
        printf("Node addition failed.\n");
        exit(EXIT_FAILURE);
    }
}

void deleteNodeClist(Circularlist* pClist){
    /*Empty list. Head and next point ot the same node*/
    if(pClist->sizeOfList == 0){
        printf("Cannot delete node. List empty\n");
        return;
    }
    /*List has only one node*/
    else if(pClist->sizeOfList == 1){
        node* current = pClist->head;
        pClist->head = NULL;
        free(current);
    }
    /*All other cases*/
    else{
        /*Temporary node is the node after the first. This node
        is deleted*/
        node* current = pClist->head->next;
        pClist->head->next = current->next;
        free(current);
    }
    /*Update size*/
    pClist->sizeOfList--;
}

void printCircularList(Circularlist* pClist){
    /*Empty list. Head and next point ot the same node*/
    if(pClist->sizeOfList == 0){
        printf("Cannot print. List empty\n");
        return;
    }
    else{
        node* current = pClist->head;
        do{
            printf("%d ", current->data);
            current = current->next;
        }while(current != pClist->head);
        printf("\n");
    }
}