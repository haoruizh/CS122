#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class Node
{
public:
	Node(Data const &newData);

private:
	Data mData;
	Node *mpLeft;
	Node *mpRight;
};