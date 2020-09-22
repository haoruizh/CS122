#include "Header.h"

Queue::Queue(int qs):qsize(qs) //initialize qsize to qs
{
	first = rear = NULL;
	items = 0;
}

bool Queue::endqueue(const int &item) //add item to end
{
	if (isfull())
	{
		return false;
	}

	Node *add = new Node; //create node

	add->item = item;
	add->next = nullptr;
	items++;

	if (first == NULL)
	{
		first = add; //if queue is empty, place item at front
	}
	else
	{
		rear->next = add; //else place at rear
	}

	rear = add; //have rear point to new node
	return true;
}

bool Queue::dequeue(int &item)
{
	if (first == NULL)
	{
		return false;
	}

	item = first->item;
	items--;
	Node *temp = first; //save location of first item
	first = first->next;//reset front to next item
	delete temp;//delete former first item
	if (items == 0)
	{
		rear = NULL;
	}

	return true;
}

Queue::~Queue()
{
	Node *temp;
	while (first!=NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}