#include <stdio.h>
#include <stdlib.h>

typedef enum bool
{
    True = 1,False = 0
}Bool;

typedef struct stacknode
{
    int data;
    struct stack *pNext;
}Stacknode;

typedef struct stack
{
    Stacknode *pTop;
}Stack;

void push(Stack *myStack, int data);
Bool isEmpty(Stack *pTop);
void pop(Stack *myStack);
int top(Stack *myStack);