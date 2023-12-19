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

    printList(&myLinkedList);

    deleteFirst(&myLinkedList);
    printList(&myLinkedList);

    deleteLast(&myLinkedList);
    printList(&myLinkedList);

    deleteTarget(&myLinkedList, 4);
    printList(&myLinkedList);

    deleteTarget(&myLinkedList, 2);
    printList(&myLinkedList);

    deleteTarget(&myLinkedList, 5);
    printList(&myLinkedList);

    return 0;
}