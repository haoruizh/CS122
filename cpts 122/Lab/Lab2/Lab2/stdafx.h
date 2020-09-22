// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

typedef enum boolean
{
    FALSE, TRUE
} Boolean;



typedef struct contact
{

    char name[50];

    char phone[12]; // 18005557577

    char email[50];

    char title[20];

} Contact;



typedef struct node
{
    Contact data;

    struct node *pNext;

} Node;


Boolean insertContactinOrder(Node **pList, Contact newData);

Node *makeNode(Contact newData);

void printlist(Node *pList);

Boolean deleteContact(Node **pList, Contact searchContact);

Boolean editContact(Node *pList, Contact searchContact);

Boolean loadContacts(FILE *infile, Node **pList);
// TODO: reference additional headers your program requires here
