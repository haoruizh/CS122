#include "Manager.h"


Manager::~Manager()
{
    cout << "Inside Manager destructor" << endl;
}

double Manager::calculatePay()
{
    double pay = 0.0;

    if (this->mIsSalariedEmpolyee)
    {
        pay = this->mPayRate; //this->getPayRate()
    }
    else //hourly pay
    {
        pay = Employee::calculatePay();
    }
}
