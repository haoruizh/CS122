#include <iostream>

using namespace std;

int main()
{
	int numberarray[4] = { 0 };
	int target = 0;
	cout << "Enter the target number:   ";
	cin >> target;
	cout << "Enter 4 int: ";
	int count = 0;
	for (;count < 4;count++)
	{
		cin >> numberarray[count];
	}
	int i, j;
	for (i = 0;i < 4;i++)
	{
		for (j = 1;j < 4;j++)
		{
			if (numberarray[i] + numberarray[j] == target)
			{
				if (i != j)
				{
					cout << "index " << i << ", index " << j << '\n';
				}
			}
		}
	}
	return 0;
}

