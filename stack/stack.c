#include <stdio.h>

/* Defines*/
#define SIZE    10

typedef struct{
    int top;
    int item[SIZE];
}stackt_t;

/*Prototype definitions*/
// void push(stackt_t* pStack, int number);
// int pop(stackt_t* pStack);
// int isEmpty(stackt_t* pStack);
// int isFull(stackt_t* pStack);
// void initStack(stackt_t* pStack);
// void printStack(stackt_t* pStack);

int isEmpty(stackt_t* pStack){
    return (pStack->top < 0);
}

int isFull(stackt_t* pStack){
    return (pStack->top == (SIZE - 1));
}

void push(stackt_t* pStack, int number){
    if(!isFull(pStack)){
        pStack->top++;
        pStack->item[pStack->top]  = number;
    }
}

int pop(stackt_t* pStack){
    if(!isEmpty(pStack)){
        return pStack->item[pStack->top--];
    }
}

void printStack(stackt_t* pStack){
    int temp = pStack->top;
    while(temp >= 0){
        printf("%d ", pStack->item[temp]);
        temp--;
    }
    printf("\n");
}

void initStack(stackt_t* pStack){
    pStack->top = -1;
}