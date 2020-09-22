#include "Sort.h"

int main(void)
{
	int nums[4] = { 7, 3, 10, 2 };
	Sorts<int> s; // Sorts is a class template!

	s.bubbleSort(nums, 4); // bubbleSort () is a function template!
	for (int i = 0; i < 4; ++i)
	{
		cout << nums[i] << endl;
	}

	return 0;
}