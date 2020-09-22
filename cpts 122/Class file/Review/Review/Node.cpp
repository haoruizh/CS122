#include "Node.h"

string Node::getData() const
{
	cout << "this: " << this << endl;
	cout << "*this" << *this << endl;

	//cout << this->mData << endl;
	//cout << this->mpNext << endl;

	return this->mData;
}

Node *Node::getNextPtr() const
{
	return this->mpNext;
}

ostream & operator<< (ostream &lhs, Node const &rhs)
{
	lhs << rhs.getData() << endl;
	lhs << rhs.getNextPtr();

	return lhs;
}

Node::Node(Node &copy)
{
	// what is n?
	this->mData = copy.mData;
	this->mpNext = copy.mpNext;
}

void f(Node n)
{

}
Node::Node(string const &newString)
{
	this->mData = newString;
}

Node f2()
{
	Node n;

	return n;
}
void f3(const Node &n)
{
	n.getData();
}