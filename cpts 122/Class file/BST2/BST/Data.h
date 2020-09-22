#pragma once


#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

// added 10/8
class Data
{
public:

	Data(int const &newItem = 0);

	int getItem() const;

	void setItem(int const &newItem);

private:
	int mItem;
};