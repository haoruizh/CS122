#include <iostream>

#include "Queue.h"
#include "List.h"

int main(void)
{
	int num1 = 35;
	ListNode<int> n1(35);


	List<int> l1;
	ListNode<int> *pMem = new ListNode<int>(35);

	l1.insertAtFront(pMem);//(new ListNode<int>(35));//(pMem);//;
	
	//delete pMem;
	l1.insertAtFront(new ListNode<int>(10));

	

	//runApp(l1);

	//Queue q;
	//const Node n1;
	//Node n2;// = n1;

	//f3(n1);

	//f2();

	//f(n1);

	//cout << "size of q: " << sizeof(Queue) << endl;

	//n1.getData();
	////n2.getData();
//	cout << "Address n1: " << &n1 << endl;


	return 0;
}