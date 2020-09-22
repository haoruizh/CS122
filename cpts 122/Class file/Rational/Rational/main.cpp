// This example will allow us to explore
// classes, data members, member functions,
// constructor, destructors, function overloading,
// operator overloading, etc. We are building
// these ideas around a Rational object

// History: 

#include "Rational.h"

int main(void)
{
	Rational r1(0, 1), r2(5, 2), r3, r4(7);

    cout << r3.getNumerator() << "/" << r3.getDenominator() << endl;

    r3 = r2;

    cout << r3.getNumerator() << "/" << r3.getDenominator() << endl;



	//r1 = r2.add(r4);

	return 0;
}