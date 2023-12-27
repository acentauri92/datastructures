#include "list.h"

Circularlist myLinkedList;

int main(void){
    initCircularList(&myLinkedList);

    addNodeClist(&myLinkedList, 1);
    addNodeClist(&myLinkedList, 2);
    addNodeClist(&myLinkedList, 3);
    addNodeClist(&myLinkedList, 4);
    addNodeClist(&myLinkedList, 5);
    printCircularList(&myLinkedList);

    deleteNodeClist(&myLinkedList);
    printCircularList(&myLinkedList);

    deleteNodeClist(&myLinkedList);
    printCircularList(&myLinkedList);
    return 0;
}