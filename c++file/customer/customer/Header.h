#include <iostream>
#include <cstdlib>
#include <ctime>

const int MIN_PER_HR = 60;

using namespace std;

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer():arrive(0), processtime(0)
	{
	}
	void set(long);
	long when() const
	{
		return arrive;
	}

	int ptime() const
	{
		return processtime;
	}
};

typedef Customer Item;

class Queue
{
private:
	struct Node
	{
		Item item;
		Node * next;
	};

	enum{Q_size = 10};

	Node * first;
	Node * rear;
	int items;
	const int qsize;

	Queue(const Queue &) :qsize(0)
	{
	}

	Queue & operator= (const Queue &)
	{
		return *this;
	}

public:
	Queue(int qs = Q_size);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &);
	bool dequeue(Item &);
};
