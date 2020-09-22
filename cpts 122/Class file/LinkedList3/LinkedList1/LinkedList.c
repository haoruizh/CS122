#include "LinkedList.h"

// implement a function that allocates space for a Node
// and initilizes the node with some Data; returns pointer
// to the Node
Node * makeNode(Data newItem)
{
	Node *pMem = NULL;

	pMem = (Node *) malloc(sizeof (Node));

	// we will not do error checking yet!

	//(*pMem).item = newItem; // struct assignment; be cautious,
	                          // especially if dealing with pointers and strings!

	pMem->item.id = newItem.id; // integer assignment
	pMem->pNext = NULL;

	return pMem;
}

int insertAtFront(Node **pList, Data newItem)
{
	int success = 0;
	Node *pMem = NULL;

	pMem = makeNode(newItem);

	if (pMem != NULL) // we allocated space on the heap successfully!
	{
		success = 1;

		pMem->pNext = *pList;
		*pList = pMem;

	}

	return success;

}

void printList(Node *pList)
{
	printf("--> ");

	while (pList != NULL)
	{
		printf("%d--> ", pList->item.id);
		pList = pList->pNext;
	}
	putchar('\n');
}