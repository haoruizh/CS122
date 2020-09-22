#include <iostream>
#include "Header.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : AcctABC(ba)
{
	maxLoan = ml;

}