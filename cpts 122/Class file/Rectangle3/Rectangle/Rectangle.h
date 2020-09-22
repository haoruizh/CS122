#pragma once

#include <iostream>

// A class is a user-defined type. It's like a blueprint.
class Rectangle
{
public: // visible to the "outside" world
	Rectangle(); // default constructor - invoked when object is declared/instantiated
	Rectangle(Rectangle &rhs); // copy constructor
	~Rectangle(); // destructor - imlicitly invoked when object goest out of scope

	// getters / accessors
	double getLength() const; // constant function - can not modify data members
	double getWidth() const;

	// setters / mutators
	void setLength(double newLength);
	void setWidth(double newWidth);

	double computeArea(); // member function

	void printRectangle();

private: // only accessible by members of the class; not visible to anything outside of object
	double mLength; // data member
	double mWidth;
};

// non member functions
// operator overloading - overloaded operator -- functions that are overloaded
std::ostream & operator<< (std::ostream &lhs, const Rectangle &rhs);

// will overload the plus operator to peform addition of 
// lengths and widths of two Rectangles
Rectangle operator+ (const Rectangle &lhs, const Rectangle &rhs);

// overloaded functions
double add(double n1, double n2);
Rectangle add(Rectangle &lhs, Rectangle &rhs);

// what is a function template? how is one related to 
// overloaded functions?
// function template
template<class T>
T add(T &lhs, T &rhs)
{
	// will finish 9/26
}