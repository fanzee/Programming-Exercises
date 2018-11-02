#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct 
{
	int length;
	struct Node *next;
}Head,*pHead;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}List,*LinkList;

pHead InitLinkList();
int insert(pHead ph, int pos, ElemType x);
int size(pHead ph);
LinkList findByValue(pHead ph, ElemType x);
LinkList findByPlace(pHead ph, int k);
int delete(pHead ph, int i);
void showList(pHead ph);
int edit(pHead ph, int index, ElemType x);
int destroy(pHead ph);
int clean(pHead ph);