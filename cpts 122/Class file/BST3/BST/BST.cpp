#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
}

void BST::insert(Data const &newData)// will complete definition 10/12
{
    insert(this->mpRoot, newData);
}

void BST::insert(Node *pTree, Data const &newData)
{
    if (pTree != nullptr)
    {
        //we should check to see if the left and/or right pointers are null
        if (newData < pTree->getData())
        {
            //check left subtree
            if (pTree->getLeftPtr() != nullptr)
            {
                insert(pTree->getLeftPtr(), newData);
            }
            else
            {
                //found place to insert in left subtree
                pTree->setLeftPtr(new Node(newData));
            }
        }
    }
    else//pTree == nullptr
    {
        this->mpRoot = new Node(newData);
    }
}