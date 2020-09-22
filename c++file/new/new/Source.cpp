#include <iostream>
#include <string>
#include <new>

using namespace std;

const int BUF = 512;

class JustTesting
{
private:
	string words;
	int number;
public:
	JustTesting(const string &s = "Just Testing", int n=0)
	{
		words = s;
		number = n;
		cout << words << " constructed\n";
	}

	~JustTesting()
	{
		cout << words << " destroyed\n";
	}
	void Show() const
	{
		cout << words << ", " << number << endl;
	}
};

int main()
{
	char * buffer = new char[BUF];

	JustTesting *pc1, *pc2;
	pc1 = new (buffer) JustTesting; //place object in buffer (default)
	pc2 = new JustTesting("Heap 1", 20);

	cout << "Memory block address:\n" << "buffer: " << (void *)buffer << " heap:" << pc2 << endl;
	cout << "Memory contents:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting *pc3, *pc4;
	//fix placement new location
	pc3 = new (buffer + sizeof(JustTesting))JustTesting("Better idea", 6);
	pc4 = new JustTesting("Heap2", 10);


}