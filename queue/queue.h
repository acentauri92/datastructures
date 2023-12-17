#include <stdio.h>
#include <stdlib.h>

#define SIZE    5

typedef struct{
    int item[SIZE];
    int front;
    int rear;
}Queue_t;

void initQueue(Queue_t* pQueue);
int isQueueFull(Queue_t* pQueue);
int isQueueEmpty(Queue_t* pQueue);
void enqueue(Queue_t* pQueue, int data);
int dequeue(Queue_t* pQueue);
