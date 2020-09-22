#include "Node.h"

Node::Node(Data const &newData)
{
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
	this->mData = newData; // using overloaded assignment?
}