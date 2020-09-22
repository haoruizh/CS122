#include "Data.h"

Data::Data(int const &newItem)
{
	mItem = newItem;
}

Data::Data(Data const &copy)
{
	this->mItem = copy.getItem();
}

Data & Data::operator= (Data const &rhs)
{
	if (this != &rhs) // check for self-assignment
	{
		this->mItem = rhs.getItem();
	}

	return (*this);
}

//Data::~Data()
//{
//	cout << "Inside of the destructor for a Data object. No resources to clean up!" << endl;
//}

int Data::getItem() const
{
	return mItem;
}

void Data::setItem(int const &newItem)
{
	mItem = newItem;
}

bool operator<(Data const &lhs, Data const &rhs)
{
	return lhs.getItem() < rhs.getItem();
}

bool operator>(Data const &lhs, Data const &rhs)
{
    return lhs.getItem() > rhs.getItem();
}