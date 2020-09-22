#include <iostream>;
#include <new.h>
#include <string.h>
using namespace std;

struct chaff
{
	char dross[20];
	int slag;
};

int main()
{
	chaff buffer1;

	char first[20];
	cin >> first;
	
	int slag;
	cin >> slag;

	strcpy(buffer1.dross, first);
	buffer1.slag = slag;

	chaff *newbuffer = new chaff;
	strcpy(newbuffer->dross, first);
	newbuffer->slag = slag;

	cout << buffer1.dross << ',' << buffer1.slag<<'\n';
	cout << newbuffer->dross << ',' << newbuffer->slag << '\n';

	delete newbuffer;
	
	return 0;
}

