#ifndef header_h_
#define header_h_

typedef unsigned long Item;

class Stack
{
private:
	enum {Max=10};
	Item items[Max];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item &item);
};
#endif
