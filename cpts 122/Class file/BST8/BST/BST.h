#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class BST
{
public:
	BST();

	Node *getRootPtr() const;

	void insert(Data const &newData); // will complete definition 10/12
	void inorderTraversal();

private:
	Node *mpRoot;

	// helper
	void insert(Node *pTree, Data const &newData); // will complete definition 10/12
	void inorderTraversal(Node *pTree);

};






BST::BST()
{
    this->mpRoot = nullptr;
}

Node * BST::getRootPtr() const
{
    return this->mpRoot;
}

void BST::insert(Data const &newData)
{
    insert(this->mpRoot, newData);
}

void BST::insert(Node *pTree, Data const &newData)
{
    if (pTree != nullptr)
    {
        // right subtree
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
        // we should check to see if the left and/or right
        // pointers are nullptrs

        else if (newData < pTree->getData())
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
        else // duplicates
        {
            cout << "Duplicate" << endl;
        }
    }
    else // pTree == nullptr
    {
        this->mpRoot = new Node(newData);
    }
}

void BST::inorderTraversal()
{
    inorderTraversal(this->getRootPtr());
}

void BST::inorderTraversal(Node *pTree)
{
    if (pTree != nullptr)
    {
        // there are nodes to visit
        // 1. go left
        inorderTraversal(pTree->getLeftPtr());
        // 2. process the node
        cout << pTree->getData().getItem() << endl;
        // 3. go right
        inorderTraversal(pTree->getRightPtr());
    }
}