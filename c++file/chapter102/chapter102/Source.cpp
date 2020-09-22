#include "Header.h"

Bank::Bank(const char *name1[MAX], const string &accountnum1, const double balance1)
{
	strcpy(name, *name1);
	accountnum = accountnum1;
	balance = balance1;
}
void Bank::display()const
{
	cout << "Name: " << name << endl
		<< "Account number: " << accountnum << endl
		<< "Money: " << balance << endl;
}
void Bank::deposit(const double depositmoney)
{
	balance += depositmoney;
	cout << "Now: balance is $" << balance<<'\n';
}
void Bank::withdraw(const double withdrawmoney)
{
	balance -= withdrawmoney;
	cout << "Now: balance is $" << balance << '\n';
}