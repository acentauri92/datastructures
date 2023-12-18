#include "list.h"

list myLinkedList;

int main(void){
    initList(&myLinkedList);
    insertAtHead(&myLinkedList, 1);
    insertAtHead(&myLinkedList, 2);
    insertAtHead(&myLinkedList, 3);
    insertAtTail(&myLinkedList, 4);
    insertAtTail(&myLinkedList, 5);
    insertAtTail(&myLinkedList, 6);

    printf("Node: %p\n", findTarget(&myLinkedList, 0));
    printList(&myLinkedList);

    return 0;
}