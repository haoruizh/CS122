#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    char c;
}Data;

typedef struct node
{
    Data item;
    struct node *pNext;
}Node;

typedef struct stack
{
    Node *pTop;
}Stack;

Node *makeNode(Data newData);

//inset at front
int push(Stack *pStack, Data newData);
//precondition: stack must not be empty, n>0;
Data pop(Stack *pStackm);


#endif
