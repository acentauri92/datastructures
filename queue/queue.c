/**
 * @file       queue.c
 * @author     Dheeraj Reddy J
 * @brief      Brief description of file
 * @version    0.1
 * @date       17-12-2023
 * 
 * 
 */
#include "queue.h"

void initQueue(Queue_t* pQueue){
    pQueue->front = pQueue->rear = (SIZE - 1);
};

int isQueueFull(Queue_t* pQueue){
    return ( (pQueue->rear + 1) % SIZE == pQueue->front);
};

int isQueueEmpty(Queue_t* pQueue){
    return (pQueue->rear == pQueue->front);
};

void enqueue(Queue_t* pQueue, int data){
    if(isQueueFull(pQueue)){
        printf("Error: Cannot enqueue %d. Queue is full\n", data);
        exit(EXIT_FAILURE);
    }
    pQueue->rear = (pQueue->rear + 1) % SIZE;
    pQueue->item[pQueue->rear] = data;
};

int dequeue(Queue_t* pQueue){
    if(isQueueEmpty(pQueue)){
        printf("Error: Cannot dequeue. Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    pQueue->front = (pQueue->front + 1) % SIZE;
    return (pQueue->item[pQueue->front]);
};
