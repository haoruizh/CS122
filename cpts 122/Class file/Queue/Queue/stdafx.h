// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class Node
{
public:
    void setNextPtr(Node * newNextPtr);
    Node(string const &newString = "");
    string getPrintJob() const;
    Node *getNextPtr() const;
    ~Node()
    {
        cout << "Inside of node destructor!" << endl;
    }

private:
    //data members
    Node *mpNext;
    string mPrintJob;
};

class Queue
{
public:
    Queue(Node *newpHead = nullptr, Node *newpTail= nullptr);
    
    
    bool enqueue(const string &newString);
    string dequeue();

    void setHeadPtr(Node * const newHeadPtr);
    void setTailPtr(Node * const newTailPtr);
    bool listempty();


    ~Queue();
private:
    Node * mpHead;
    Node * mpTail;

    void destoryqueue();
};

// TODO: reference additional headers your program requires here
