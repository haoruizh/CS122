#include <iostream>

using namespace std;

class Queue
{
private:
	//Node is a nested strucutre definition local to this class
	struct Node
	{
		int item;
		Node *next;
	};
	enum {Q_size = 10};

	Node *first;
	Node *rear;
	int items; //current number of items in Queue
	const int qsize; //maximum number of items in Queue

public:
	Queue(int qs = Q_size);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool endqueue(const int &); //add item to end
	bool dequeue(int &); //remove item from front
};
