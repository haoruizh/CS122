#include "Node.h"

Node::Node(Data const &newData)
{
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
	this->mData = newData; // using overloaded assignment operator for Data? did we define it?
}

Data Node::getData() const
{
	return this->mData; // what happens here with the mData object? the copy constructor for a Data object is invoked to return it!
}

Node * Node::getLeftPtr() const
{
	return this->mpLeft;
}

Node * Node::getRightPtr() const
{
	return this->mpRight;
}

void Node::setData(Data const &newData)
{
	this->mData = newData; // using overloaded assignment operator for Data? did we define it?
}

void Node::setLeftPtr(Node * const &newLeftPtr)
{
	this->mpLeft = newLeftPtr;
}

void Node::setRightPtr(Node * const &newRightPtr)
{
	this->mpRight = newRightPtr;
}