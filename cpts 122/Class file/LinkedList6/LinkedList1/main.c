// This example will explore designing and implementing
// a singly linked list from the ground up!

// History: 9/7 - Implemented deleteFront () w/ doubly linked list implementation
//          9/5 - Implemented deleteItem () and isEmpty ().
//          8/31 - Implemented insertInOrder ().
//          8/29 - Implemented insertAtFront () and printList ().
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

	//success = insertAtFront(&pHead, d1);
	//d1.id = 222222222;
	//success = insertAtFront(&pHead, d1);
	//d1.id = 333333333;
	//success = insertAtFront(&pHead, d1);

	//printList(pHead);

	// added after lecture 8/31
	d1.id = 888888888;
	success = insertInOrder(&pHead, d1);
	d1.id = 1;
	success = insertInOrder(&pHead, d1);
	d1.id = 999999999;
	success = insertInOrder(&pHead, d1);
	d1.id = 3;
	success = insertInOrder(&pHead, d1);

	printList(pHead);



	return 0;
}