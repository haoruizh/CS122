// This example will explore designing and implementing
// a singly linked list from the ground up!

// History: 8/29 - Implemented insertAtFront () and printList ().
//          8/27 - Defined Data and a Node for our linked list.
//                 Implemented makeNode () without error checking.

#include "LinkedList.h"

int main(int argc, char *argv[])
{
	Node *pHead = NULL; // empty list
	Data d1 = { 11111111 };
	// known input for our test case
	// expected result? after insert at front?
	int success = 0;

	success = insertAtFront(&pHead, d1);
	d1.id = 222222222;
	success = insertAtFront(&pHead, d1);
	d1.id = 333333333;
	success = insertAtFront(&pHead, d1);

	printList(pHead);


	return 0;
}