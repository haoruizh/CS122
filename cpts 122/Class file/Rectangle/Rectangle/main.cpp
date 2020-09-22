// This example works with our first class. Class Rectangle.

// History: 9/19 - Declared data members for a Rectangle. Declared
//                 a computeArea () function, but have not implemented
//                 it. Discussed private/public. This example is not complete!

#include "Rectangle.h"

int main(void)
{
	Rectangle r1;
    Rectangle r2 = r1; //copy constructor
    

    r2 = r1; //overloaded operator

	// think about why the below statement will not work/compile
	// as is! 
	//std::cout << "length: " << r1.mLength << std::endl;
    
    r1.setLength(5);
    r1.setWidth(4);

    r2.setLength(3);
    r2.setWidth(6);

    std::cout<<"sum of rectangle "<<add(r1, r2) << std::endl;

    //adding strings
    std::string s1 = "Cat", s2 = "Dog";
    std::cout << "Sum of string " << add(r1, r2) << std::endl;


	return 0;
}