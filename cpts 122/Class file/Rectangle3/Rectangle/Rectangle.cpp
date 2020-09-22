#include "Rectangle.h"

Rectangle::Rectangle() // default constructor
{
	mLength = 0.0;
	mWidth = 0.0;
}

Rectangle::Rectangle(Rectangle &rhs) // copy constructor
{
	mLength = rhs.getLength();
	mWidth = rhs.getWidth();
}

Rectangle::~Rectangle()
{
	// implicity invoked when an object goes out of scope;
	// dynamic memory (we have to be careful), we want the destructor
	// to be invoked, but it may not be - operator "delete" will force
	// the destructor to be invoked
	std::cout << "Inside Rectangle destructor!" << std::endl;
}

// getters / accessors
double Rectangle::getLength() const
{
	return mLength;
}

double Rectangle::getWidth() const
{
	return mWidth;
}

// setters / mutators
void Rectangle::setLength(double newLength)
{
	// validate information
	if (newLength >= 0.0)
	{
		mLength = newLength;
	}
	else
	{
		mLength = 0.0;
	}
}

void Rectangle::setWidth(double newWidth)
{
	// validate information
	if (newWidth >= 0.0)
	{
		mWidth = newWidth;
	}
	else
	{
		mWidth = 0.0;
	}

}

double Rectangle::computeArea()
{
	return mLength * mWidth;
}

void Rectangle::printRectangle()
{
	// what format do we want display the rectangle
	std::cout << "Length: " << mLength << std::endl;
	std::cout << "Width: " << mWidth << std::endl;
}


// non member
std::ostream & operator<< (std::ostream &lhs, const Rectangle &rhs)
{
	lhs << "Length: " << rhs.getLength() << std::endl;
	lhs << "Width: " << rhs.getWidth();

	return lhs;
}

// Adds the lengths and widths of two Rectangles together
Rectangle operator+ (const Rectangle &lhs, const Rectangle &rhs)
{
	Rectangle result;

	//result = ?
	result.setLength(lhs.getLength() + rhs.getLength());
	result.setWidth(lhs.getWidth() + rhs.getWidth());

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