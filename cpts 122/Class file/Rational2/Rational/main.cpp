// This example will allow us to explore
// classes, data members, member functions,
// constructor, destructors, function overloading,
// operator overloading, etc. We are building
// these ideas around a Rational object

// History: 10/3 - Changed the private data members of 
//                 the Rational object to pointers to integers.
//                 The constructor allocated space for two 
//                 integers on the heap and set the addresses
//                 to the corresponding member pointers. The destructor
//                 for the object is responsible for deallocating
//                 the integers that are on the heap. Implemented
//                 an overloaded assignment operator.

#include "Rational.h"

int main(void)
{
	// The numerators and denominators for the 
	// Rational objects are placed in the heap!!!
	Rational r1(0, 1), r2(5, 2), r3, r4(7); 

    ifstream input;
    input.open("RNumbers.txt", std::ios::in);

    input >> r1;

    cout << r1.getNumerator() << "/" << r1.getDenominator() << endl;

	cout << r3.getNumerator() << " / " << r3.getDenominator() << endl;

	r3 = r2; // overloaded assignment is invoked

	cout << r3.getNumerator() << " / " << r3.getDenominator() << endl;


	//r1 = r2.add(r4);

	return 0;
}