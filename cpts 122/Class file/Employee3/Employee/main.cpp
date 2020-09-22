// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

#include <iostream>
#include <string>

// Inheritance starter code! Not yet complete!

#include "Employee.h"
#include "Manager.h"

void printPay(Employee &e); // we want to be able to program
                            // in the general. 

int main(void)
{
	Employee e1("Scott", 20.0, 5);
	Manager m1("Madeline", 4000, 20, true);

	printPay(e1); // how can we create a function that only has 1 version, but can be used with different objects in the same class hierarchy
	printPay(m1);

	//e1.getHours();

	//m1.getHours();

	//cout << "Pay: " << e1.calculatePay() << endl;
	//cout << "Pay: " << m1.calculatePay() << endl;


	return 0;
}

void printPay(Employee &e)
{
	cout << e.calculatePay() << endl; // as of 10/31 this function
									  // does not apply programming in the general
}