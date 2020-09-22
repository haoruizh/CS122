#include "Stack.h"

Node *makeNode(Data newData)
{
	Node *pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		// can initialize node
		pMem->item = newData;
		pMem->pNext = NULL;
	}

	return pMem;
}

int push(Stack *pStack, Data newData)
{
	Node *pMem = makeNode(newData);
	int success = 0;

	if (pMem != NULL)
	{
		success = 1;
		pMem->pNext = pStack->pTop;
		pStack->pTop = pMem;
	}

	return success;
}


Data pop(Stack *pStack)
{
	Node *pTemp = pStack->pTop;
	Data returnData = pStack->pTop->item;

	pStack->pTop = pStack->pTop->pNext;

	free(pTemp);

	return returnData;
}

int isEmpty(Stack s)
{
	return (s.pTop == NULL);
}