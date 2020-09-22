// We will place the definitions for only
// Rational's operations in this file

#include "Rational.h"

//Rational::Rational()
//{
//	mNumerator = 0;
//	mDenominator = 1;
//}
//
//Rational::Rational(int newNumerator, int newDenominator)
//{
//	mNumerator = newNumerator;
//	mDenominator = newDenominator;
//}

Rational::Rational(int newNumerator, int newDenominator)
{
    this->mpDenominator = new int;
    *(this->mpDenominator) = newDenominator;

    this->mpNumerator = new int;
    *(this->mpNumerator) = newNumerator;


	//mNumerator = newNumerator;

	//// validate the denominator
	//if (newDenominator != 0)
	//{
	//	mDenominator = newDenominator;
	//}
	//else
	//{
	//	mDenominator = 1;
	//}
}

int Rational::getNumerator() const
{
	return *mpNumerator;
}

int Rational::getDenominator() const
{
	return *mpDenominator;
}


void Rational::setNumerator(int const newNumerator)
{
	*mpNumerator = newNumerator;
}

void Rational::setDenominator(int const newDenominator)
{
	// validate the denominator
	if (newDenominator != 0)
	{
		*mpDenominator = newDenominator;
	}
}

// implicitly called when passing-by-value
Rational::Rational(const Rational &copy)
{
	//mNumerator = copy.mNumerator; // could also work
	//setNumerator(copy.getNumerator());
	//setDenominator(copy.getDenominator());

    //shallow copy: copy the value
    setNumerator(copy.getNumerator());
    setDenominator(copy.getDenominator());
}

Rational Rational::add(const Rational &rhs)
{
	Rational result;

	result.setDenominator(rhs.getDenominator() *
		getDenominator());
	result.setNumerator(rhs.getNumerator() * getDenominator() +
		getNumerator()*rhs.getDenominator());

	return result;
}

Rational::~Rational()
{
   cout << "Inside destructor for Rational" << std::endl;
   delete this->mpDenominator;
   delete this->mpNumerator;
}

Rational & Rational::operator= (const Rational &rhs)
{
	setNumerator(rhs.getNumerator());
	setDenominator(rhs.getDenominator());

	return (*this);
}

Rational & Rational::operator=  (const Rational & rhs)
{
    if (this != &rhs) //self assignment check
    {
        this->setNumerator(rhs.getNumerator());
        this->setDenominator(rhs.getDenominator());
    }

    return *this;
}
