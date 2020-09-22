#include "Header.h"
#include <cstdlib>

Queue::Queue(int qs) :qsize(qs)
{
	first = rear = NULL;
	items = 0;
}

Queue::~Queue()
{
	Node *temp;
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const Item &item)
{
	if (isfull())
	{
		return false;
	}

	Node *add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (first == NULL)
	{
		first = add;
	}
	else
	{
		rear->next = add;
	}

	rear = add;
	return true;
}

bool Queue::dequeue(Item &item)
{
	if (first == NULL)
	{
		return false;
	}

	item = first->item;
	items--;
	Node *temp = first;
	first = first->next;
	delete temp;

	if (items == 0)
	{
		rear = NULL;
	}

	return true;
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}