#pragma once


#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

// added 10/8

template<class T>
class Data
{
public:

	Data(T const &newItem = 0);

	// The rule of three states that if you define a copy constructor, you should define a copy assignment operator and destructor. I did!
	Data(Data<T> const &copy);

	Data<T>& operator= (Data<T> const &rhs);

	//~Data();

	T getItem() const;

	void setItem(T const &newItem);

private:
	T mItem;
};

//bool operator<(Data const &lhs, Data const &rhs);
//
//
//
//bool operator> (Data const &lhs, Data const &rhs);

template<class T>
Data<T>::Data(T const &newItem)
{
    mItem = newItem;
}

template<class T>
Data<T>::Data(Data<T> const &copy)
{
    this->mItem = copy.getItem();
}

template<class T>
Data<T> & Data<T>::operator= (Data<T> const &rhs)
{
    if (this != &rhs) // check for self-assignment
    {
        this->mItem = rhs.getItem(); //type T assignment
    }

    return (*this);
}

//Data::~Data()
//{
//	cout << "Inside of the destructor for a Data object. No resources to clean up!" << endl;
//}

template<class T>
T Data<T>::getItem() const
{
    return mItem;
}

template<class T>
void Data<T>::setItem(T const &newItem)
{
    mItem = newItem;
}
