#include <iostream>
#include <string>


using namespace std;

class Bank {
private:
	static const int MAX = 40;
	char name[MAX];
	string accountnum;
	double balance;
public:
	Bank() { name[0] = '\n';accountnum = "";balance = 0; };
	Bank(const char *name1[MAX],const string &accountnum, const double balance);
	void display() const;
	void deposit(const double depositmoney);
	void withdraw(const double withdrawmoney);
};

