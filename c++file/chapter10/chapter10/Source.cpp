#include "Header.h"

Person::Person(const string &ln, const char *fn)
{
	lname = ln;
	strcpy(fname,fn);
	show();
	formalshow();
}

void Person::show() const
{
	cout << fname << lname<<endl;
}

void Person::formalshow() const
{
	cout << lname << fname << endl;
}