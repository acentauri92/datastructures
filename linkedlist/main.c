#include "list.h"

list myLinkedList;

int main(void){
    initList(&myLinkedList);

    addFirst(&myLinkedList, 1);
    addFirst(&myLinkedList, 2);
    addFirst(&myLinkedList, 3);

    addLast(&myLinkedList, 4);
    addLast(&myLinkedList, 5);
    addLast(&myLinkedList, 6);

    printList(&myLinkedList);

    dListDeleteFirst(&myLinkedList);
    printList(&myLinkedList);

    dListDeleteLast(&myLinkedList);
    printList(&myLinkedList);

    freeList(&myLinkedList);

    return 0;
}