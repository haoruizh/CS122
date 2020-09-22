#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

using std::string;

class Node
{
public:
	Node(string const &newString = "string");

	string getData() const;
	Node *getNextPtr() const;

	Node(Node &copy);

private:
	string mData;
	Node *mpNext;
};

ostream & operator<< (ostream &lhs, Node const &rhs);

void f(Node n);
Node f2();

void f3(const Node &n);