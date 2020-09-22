// This example works with our first class. Class Rectangle.

// History: 9/24 - Implemented a destructor for Rectangle (~Rectangle),
//                 printRectangle (), overloaded the stream insertion
//                 operator (<<) and the addition operator (+)
//                 to work with Rectangle objects. Discussed
//                 constant functions: getters are generally
//                 constant functions. Started
//                 discussing function templates.
//          9/21 - Implemented computeArea (). Implemented getters
//                 and setters. Implemented a default constructor
//                 to initialize the private data of a Rectangle
//                 object. Implemented a copy constructor for
//                 copying the data members of one Rectangle object
//                 into another Rectangle object.
//          9/19 - Declared data members for a Rectangle. Declared
//                 a computeArea () function, but have not implemented
//                 it. Discussed private/public. This example is not complete!

#include "Rectangle.h"

int main(void)
{
	Rectangle r1; // default constructor is implicitly invoked here
	Rectangle r2 = r1; // copy constructor is invoked here, not assignment operator

	// r2 = r1; // overloaded assignment operator

	// think about why the below statement will not work/compile
	// as is! 
	//std::cout << "length: " << r1.mLength << std::endl;
	r1.setLength(5);
	r1.setWidth(4);

	r2.setLength(3);
	r2.setWidth(6);

	//r1.printRectangle();

	//std::cout << r1 << std::endl;

	// In the below statement both are overloaded << and + are invoked!!!
	std::cout << "Result: " << r1 + r2 << std::endl;

	std::cout << "Area: " << r1.computeArea() << std::endl;

	return 0;
}