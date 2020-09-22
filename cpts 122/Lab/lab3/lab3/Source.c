#include "Header.h"

void push(Stack *myStack, int data)
{
    Stacknode *pMem = (Stack *)malloc(sizeof(Stack*));
    if (pMem != NULL)
    {
        pMem->data = data;
        pMem->pNext = NULL;
    }

    
    myStack->pTop = pMem;
    pMem->pNext = myStack->pTop;
}

Bool isEmpty(Stack *pTop)
{
    return(!pTop);
}

void pop(Stack *myStack)
{
    Stack *pCur = myStack->pTop;
    if (myStack->pTop != NULL)
    {
        pCur->pTop = myStack->pTop->pNext;
        free(myStack->pTop);
    }
}

int top(Stack *myStack)
{
    if(myStack->pTop!=NULL)
    {
        return(myStack->pTop->data); 
    }
}