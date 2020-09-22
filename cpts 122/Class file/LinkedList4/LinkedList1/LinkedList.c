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

// Insert new data into the list in order. We'll
// insert in ascending (smallest to largest) order.
int insertInOrder(Node **pList, Data newItem)
{
	int success = 0;
	Node *pMem = makeNode(newItem), *pCur = *pList, *pPrev = NULL;

	if (pMem != NULL)
	{
		success = 1; // allocated space for a node successfully!

		// think state of data structure? Empty or not empty?

		if (*pList == NULL) // list empty?
		{
			// empty list
			*pList = pMem;
		}
		else // non empty list
		{
			// insert in order - ascending (smallest to largest)
			while ((pCur != NULL) && (pMem->item.id > pCur->item.id))
			{
				// find where to insert
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			//Found where to insert
			if (pPrev != NULL) // not inserting at front
			{
				// insert in middle or at end somewhere
				// code below added after lecture
				pMem->pNext = pCur; // connect new node to next node in sequence
				pPrev->pNext = pMem; // connect the previous node in sequence to the new node
			}
			else // inserting at front
			{
				pMem->pNext = pCur;// connect new node to next node in sequence
				*pList = pMem; // update the head pointer!
			}
		}
	}

	return success;
}
