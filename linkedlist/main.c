#include "list.h"

list myLinkedList;

int main(void){
    initList(&myLinkedList);

    insertAtTail(&myLinkedList, 1);
    insertAtTail(&myLinkedList, 2);
    insertAtTail(&myLinkedList, 3);
    insertAtTail(&myLinkedList, 4);
    insertAtTail(&myLinkedList, 5);
    insertAtTail(&myLinkedList, 6);

    printList(&myLinkedList);

    reverseList(&myLinkedList);
    printList(&myLinkedList);

    // deleteFirst(&myLinkedList);
    // printList(&myLinkedList);

    // deleteLast(&myLinkedList);
    // printList(&myLinkedList);

    // deleteTarget(&myLinkedList, 4);
    // printList(&myLinkedList);

    // deleteTarget(&myLinkedList, 2);
    // printList(&myLinkedList);

    // deleteTarget(&myLinkedList, 5);
    // printList(&myLinkedList);

    return 0;
}