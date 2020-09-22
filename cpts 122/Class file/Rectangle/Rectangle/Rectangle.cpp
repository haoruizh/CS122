#include "Rectangle.h"

double Rectangle::computeArea()
{
    return mLength*mWidth;
}

Rectangle::Rectangle()
{
    mLength = 0.0;
    mWidth = 0.0;

}

Rectangle::Rectangle(Rectangle &rhs)
{
    mLength = rhs.getLength();
    mWidth = rhs.getWidth();
}

//getters /accessors
double Rectangle::getLength() const
{
    return mLength;
}

double Rectangle::getWidth() const
{
    return mWidth;
}

//setters /mutators
void Rectangle::setLength(double newLength)
{
    //validate information
    if (newLength >= 0.0)
    {
        mLength = newLength;
    }
    else
    {
        mLength = 0;
    }
}
void Rectangle::setWidth(double newWidth)
{
    //validate information
    if (newWidth >= 0.0)
    {
        mWidth = newWidth;
    }
    else
    {
        mWidth = 0;
    }
}

Rectangle::~Rectangle()
{
    //implicity invoked when an object goes out of scope
    //dynamic memory (have to be careful), we want the destructor to be invoked, but it may not be - delete

    std::cout << "Inside Rectangle destructor!" << std::endl;
}

void Rectangle::printRectangle()
{
    //what format do we want display the rectangle
    std::cout << "Length:" << mLength << std::endl;
    std::cout << "Width:" << mWidth << std::endl;
}

std::ostream & operator<<(std::ostream &lhs, const Rectangle &rhs) //non member
{
    lhs << "Length:" << rhs.getLength() << std::endl;
    lhs << "Width:" << rhs.getWidth() << std::endl;
    return lhs;
}

Rectangle operator+(const Rectangle &rhs, const Rectangle &lhs)
{
    Rectangle result; 

    result.setLength(rhs.getLength() + lhs.getLength());
    result.setWidth(rhs.getWidth() + lhs.getWidth());

    return result;
}


double add(double n1, double n2)
{
    return n1 + n2;
}
Rectangle add(Rectangle &lhs, Rectangle &rhs)
{
    return lhs + rhs;
}