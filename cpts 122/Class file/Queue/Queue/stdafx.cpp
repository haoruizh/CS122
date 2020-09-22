// stdafx.cpp : source file that includes just the standard includes
// Queue.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file


Node::Node(string const &newString = "")
{
    mPrintJob = newString;
    mpNext = nullptr;
}

Queue::Queue(Node *newpHead = nullptr, Node *newpTail = nullptr)
{
    this->mpHead = newpHead;
    this->mpTail = newpTail;
}

bool Queue::enqueue(const string &newString)
{
    bool success = false;

    Node *pMem = new Node(newString);

    if (pMem != nullptr)
    {
        success = true;

        //work if queue is empty
        if (this->mpHead == nullptr)
        {
            this->setHeadPtr(pMem);
            this->setTailPtr(pMem);
            this->mpHead = this->mpTail = pMem;
        }
        else
        {
            //not empty - insert at the tail
            this->mpTail->setNextPtr(pMem);
            this->setTailPtr(pMem);
        }
    }
}


void Queue::setHeadPtr(Node * const newHeadPtr)
{
    this->mpHead = newHeadPtr;
}

void Queue::setTailPtr(Node * const newTailPtr)
{
    this->mpTail = newTailPtr;
}

void Node::setNextPtr(Node * newNextPtr)
{
    this->mpNext = newNextPtr;
}

string Queue::dequeue()
{
    string returndata = "";
    Node *pTemp = nullptr;

    pTemp = this->mpHead;
    returndata = this->mpHead->getPrintJob();

    //think state of queue
    if (this->mpHead == this->mpTail)
    {
        //single node in queue
        this->mpHead = this->mpTail = nullptr;
    }
    else
    {
        //more than one node in queue
        this->setHeadPtr(this->mpHead->setNextPtr);
    }
}


string Node::getPrintJob() const
{
    return this->mPrintJob;
}

Node *Node::getNextPtr() const
{
    
}


bool Queue::listempty()
{
    return this->mpHead == nullptr;
}

Queue::~Queue()
{
    this->destoryqueue();
}

void Queue::destoryqueue()
{
    //check empty queue
    while (!this->listempty())//this->mpHead != nullptr
    {
        this->dequeue();
    }
}