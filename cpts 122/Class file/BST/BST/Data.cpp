#include "Data.h"
int Data::getItem() const
{
    return mitem;
}

void Data::setItem(int const &newItem)
{
    mitem = newItem;
}

Data::Data(int const &newItem = 0)
{
    mitem = newItem;
}
