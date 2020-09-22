#include "Manager.h"

Manager::~Manager()
{
	cout << "Inside Manager destructor!" << endl;
}

double Manager::calculatePay()
{
	double pay = 0.0;

	if (this->mIsSalariedEmployee)
	{
		// accessing mPayRate directly works only
		// if it's a protected member of the Employee class;
		// otherwise need to use public functions
		pay = this->mPayRate; //this->getPayRate();
	}
	else // hourly pay
	{
		pay = Employee::calculatePay();
	}

	return pay;
}