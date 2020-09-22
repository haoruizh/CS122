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
				pPrev->pNext = pMem;
				pMem->pNext = pCur;
			}
			else
			{
				// insert at front
				pMem->pNext = *pList; // pMem->pNext = pCur;
				*pList = pMem;
			}
		}
	}

	return success;
}

// precondition: list must not be empty! #nodes = n > 0
int deleteItem(Node **pList, Data target)
{
	Node *pPrev = NULL, *pCur = *pList;
	int success = 0;

	while ((pCur != NULL) && (pCur->item.id != target.id))
	{
		pPrev = pCur;
		pCur = pCur->pNext;
	}

	// we have positioned ourself in hte list, to determine
	// if target is in list or not

	// target not in list
	/*if (pCur == NULL)
	{
		success = 0;
	}*/
	if (pCur != NULL) // target is in list
	{
		// not the first node
		if (pPrev != NULL)
		{
			pPrev->pNext = pCur->pNext;
		}
		else // deleting the first node
		{
			*pList = pCur->pNext;
		}
		success = 1;
		free(pCur);
	}

	return success;
}

// returns 1 if list is empty, 0 otherwise
int isEmpty(Node *pList)
{
	return (pList == NULL);
}

int deleteFront(Node **pList, Data *pData)
{
    Node *pTemp = *pList;
    int success = 0;
    *pList = (*pList)->pNext;
    if (*pList != NULL) //multiple nodes in list
    {
        *pData = pTemp->item;
        (*pList)->pPrev = NULL;
        free(pTemp);
        success = 1;
    }
    else
    {
        *pData = pTemp->item;
        free(pTemp);
    }
    return success;
}
