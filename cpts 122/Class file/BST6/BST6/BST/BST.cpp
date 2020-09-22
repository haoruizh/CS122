#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
}

void BST::insert(Data const &newData)
{
	insert(this->mpRoot, newData);
}

Node *BST::getRootPtr() const
{
    return this->mpRoot;
}


void BST::insert(Node *pTree, Data const &newData)
{
	if (pTree != nullptr)
	{
        //right subtree
        if (newData > pTree->getData())
        {

            if (pTree->getRightPtr() == nullptr)
            {
                pTree->setRightPtr(new Node(newData));
            }
            else //recursive step
            {
                insert(pTree->getRightPtr(), newData);
            }
        }
        else //duplicates
        {
            cout << "Duplicate" << endl;
        }
		// we should check to see if the left and/or right
		// pointers are nullptrs

		if (newData < pTree->getData())
		{
			// check left subtree
			if (pTree->getLeftPtr() != nullptr)
			{
				// have not found place to insert yet,
				// go futher down the left subtree
				insert(pTree->getLeftPtr(), newData);
			}
			else
			{
				// found place to insert in left subtree
				pTree->setLeftPtr(new Node(newData));
			}

		}
	}
	else // pTree == nullptr
	{
		this->mpRoot = new Node(newData);
	}
}