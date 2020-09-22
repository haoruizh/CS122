#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

using std::string;

//void runApp();

template <class T>
class ListNode
{
public:
	ListNode();
	ListNode(const T &newData);

	void setNextPtr(ListNode<T> *pNewNext);
	void setPrevPtr(ListNode<T> *pNewPrev);

private:
	T mData;
	ListNode<T> *mpPrev;
	ListNode<T> *mpNext;
};

template <class T>
class List
{
public:
	List(ListNode<T> *pNewHead = nullptr);

	bool insertAtFront(ListNode<T> *pNewNode);

	void setHeadPtr(ListNode<T> *pNewHead);

private:
	ListNode<T> *mpHead;
};

template <class T>
ListNode<T>::ListNode(const T &newData)
{
	this->mData = newData;
	this->mpNext = nullptr;
	this->mpPrev = nullptr;
}

template <class T>
List<T>::List(ListNode<T> *pNewHead)
{
	this->mpHead = pNewHead;
}

// parameters: pNewNode is a pointer to a node on the heap
template <class T>
bool List<T>::insertAtFront(ListNode<T> *pNewNode)
{
	bool success = false;

//	 ListNode<T> *pMem = new ListNode<T>(data);

	/*if (this->mpHead == nullptr)
	{
	pNewNode->setNextPtr(this->mpHead);
	this->setHeadPtr(pNewNode);
	}*/

	if (pNewNode != nullptr)
	{
		success = true;

		if (this->mpHead != nullptr)//else // not empty
		{
			this->mpHead->setPrevPtr(pNewNode);
			pNewNode->setNextPtr(this->mpHead);
			this->setHeadPtr(pNewNode);

			// this->mpHead = this->mpTail = nullptr;
		}

		this->setHeadPtr(pNewNode);
	}

	return success;

}

template <class T>
void ListNode<T>::setNextPtr(ListNode<T> *pNewNext)
{
	this->mpNext = pNewNext;
}

template <class T>
void List<T>::setHeadPtr(ListNode<T> *pNewHead)
{
	this->mpHead = pNewHead;
}

template <class T>
void ListNode<T>::setPrevPtr(ListNode<T> *pNewPrev)
{
	this->mpPrev = pNewPrev;
}