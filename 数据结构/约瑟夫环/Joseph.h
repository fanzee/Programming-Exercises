#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*pNode;

typedef struct Head
{
	int length;
	pNode next;
}Head,*pHead;

pHead createClist();
int isEmpty(pHead ph);
int insertClist(pHead ph, int pos, int val);
void printClist(pHead ph);