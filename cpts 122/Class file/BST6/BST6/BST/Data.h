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

	// The rule of three states that if you define a copy constructor, you should define a copy assignment operator and destructor. I did!
	Data(Data const &copy);

	Data & operator= (Data const &rhs);

	//~Data();

	int getItem() const;

	void setItem(int const &newItem);

private:
	int mItem;
};

bool operator<(Data const &lhs, Data const &rhs);
bool operator>(Data const &lhs, Data const &rhs);