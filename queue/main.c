#include "queue.h"

int main(void){
    Queue_t queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    

    // printf("Dequeued element: %d\n", dequeue(&queue));
    // printf("Dequeued element: %d\n", dequeue(&queue));
    // printf("Dequeued element: %d\n", dequeue(&queue));
    // printf("Dequeued element: %d\n", dequeue(&queue));
    // printf("Dequeued element: %d\n", dequeue(&queue));

}