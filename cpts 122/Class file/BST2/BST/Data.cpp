#include "Data.h"

Data::Data(int const &newItem)
{
	mItem = newItem;
}

int Data::getItem() const
{
	return mItem;
}

void Data::setItem(int const &newItem)
{
	mItem = newItem;
}