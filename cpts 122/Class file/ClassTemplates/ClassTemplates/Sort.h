#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

template <class T> // <typename T> 
class Sorts // generic class
{
public:
	void bubbleSort(T list[], int size);
};

template<class T>
void Sorts<T>::bubbleSort(T list[], int size)
{
	int index = 0, passes = 0;
	T temp;

	for (passes = 1; passes < size; ++passes)
	{
		for (index = 0; index < size - passes; ++index)
		{
			// > better be overloaded for the objects of type T!
			if (list[index] > list[index + 1]) //swap
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
		}
	}
}