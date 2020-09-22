#pragma once

#include <iostream>
#include <string.h>

// A class is a user-defined type. It's like a blueprint.
class Rectangle
{
public: // visible to the "outside" world
	double computeArea(); // member function
    Rectangle(); //default constructor
    Rectangle(Rectangle &rhs); //copy constructor (always accept a Rectangle variable)
    ~Rectangle(); //destructor
    
    //getters /accessors
    double getLength() const;//constant function
    double getWidth() const;//constant function

    //setters /mutators
    void setLength(double newLength);
    void setWidth(double newWidth);


    void printRectangle();


private: // only accessible by members of the class; not visible to anything outside of object
	double mLength; // data member
	double mWidth;
};

//non member functions
//operator overloading - overloaded operator - like functions that are overloaded

std::ostream & operator<<(std::ostream &lhs, const Rectangle &rhs);


//function template
//double add(double n1, double n2);
//Rectangle add(Rectangle &lhs, Rectangle &rhs);

template<class T, class R>
T add(T &lhs, R &rhs)
{
    return lhs + rhs;
}