#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc (), free ()

typedef struct data
{
	int id; // 4 bytes
} Data;

typedef struct node
{
	Data item;
	struct node *pNext;
} Node; // ~8 bytes

// implement a function that allocates space for a Node
// and initilizes the node with some Data; returns pointer
// to the Node
Node * makeNode(Data newItem);
int insertAtFront(Node **pList, Data newItem);
void printList(Node *pList);
int insertInOrder(Node **pList, Data newItem);

#endif