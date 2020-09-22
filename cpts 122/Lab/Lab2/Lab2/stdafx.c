// stdafx.cpp : source file that includes just the standard includes
// Lab2.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

Boolean deleteContact(Node **pList, Contact searchContact)
{
    Boolean bool = FALSE;
    Node *pCur = *pList, *pPrev = NULL;
    while (*pList != NULL && strcmp(*pCur->data.name, searchContact.name) != 0)
    {
        pPrev = pCur;
        pCur = pCur->pNext;
        if (strcmp(*pCur->data.name, searchContact.name) == 0)
        {
            bool = TRUE;
            break;
        }
    }
    if (pPrev == NULL)
    {
        *pList = pCur->pNext;
    }
    pPrev->pNext = pCur->pNext;
    free(pCur);
    return bool;
}

void printlist(Node *pList)
{
    while (pList != NULL)
    {
        printf("%s, %s, %s, %s\n", pList->data.name, pList->data.phone, pList->data.email, pList->data.title);
        pList = pList->pNext;
    }
}
Boolean editContact(Node *pList, Contact searchContact)
{
    Boolean bool = FALSE;
    Node *pCur = pList, *pPrev = NULL;
    while (pList != NULL && strcmp(*pCur->data.name, searchContact.name) != 0)
    {
        pPrev = pCur;
        pCur = pCur->pNext;
        if (strcmp(*pCur->data.name, searchContact.name) == 0)
        {
            bool = TRUE;
            break;
        }
    }
    printf("Changed name:");
    scanf("%s", pCur->data.name);
    return bool;
}
Boolean insertContactinOrder(Node **pList, Contact newData)
{
    Boolean bool = FALSE;
    Node *pmem = NULL, *pCur = *pList, *pPrev = NULL;
    pmem = makeNode(newData);
    if (pmem != NULL)
    {
        if (*pList == NULL)
        {
            *pList = pmem;
        }
        else
        {
            while (pCur != NULL && strcmp(pmem->data.name, pCur->data.name) < 0)
            {
                pPrev = pCur;
                pCur = pCur->pNext;
            }
            if (pPrev == NULL)//insert front
            {
                pmem->pNext = pCur;
                *pList = pmem;
            }
            else
            {
                pmem->pNext = pCur;
                pPrev->pNext = pmem;
            }
            bool = TRUE;
        }
    }
    return bool;
}


Node *makeNode(Contact newData)
{
    Node *pMem = (Node *)malloc(sizeof(Node));
    pMem->data = newData;
    pMem->pNext = NULL;
    return pMem;
}

Boolean loadContacts(FILE *infile, Node **pList)
{

}
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
