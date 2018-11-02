#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*pNode;

typedef struct Queue
{
	pNode front;
	pNode rear;
	int length;
}Queue,*LinkQueue;

LinkQueue Create();
int getLength(LinkQueue lq);
int isEmpty(LinkQueue lq);
void Insert(LinkQueue lq, ElemType x);
ElemType getHead(LinkQueue lq);
pNode Delete(LinkQueue lq);
void Destroy(LinkQueue lq);