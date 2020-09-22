// History: 10/10 - Defined attributes of class Node. Created
//                  a constructor for class Node. Defined
//                  attributes of class BST. Declared both
//                  private and public insert () functions
//          10/8 - Worked on parts of the class Node and class Data.

#include "Node.h"
#include "BST.h"

int main(void)
{
    Data d1(20), d2;
    Node n1(d1);
    BST tree; //empty tree

    tree.insert(d1);
    if(tree!=nullptr)
	return 0;
}