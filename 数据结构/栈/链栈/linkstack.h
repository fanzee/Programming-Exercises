#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*pNode;

typedef struct Stack
{
	pNode top;
	int size;
}Stack,*LinkStack;

LinkStack create();
int isEmpty(LinkStack stack);
int getSize(LinkStack stack);
pNode getTop(LinkStack stack);
int push(LinkStack stack, ElemType x);
pNode pop(LinkStack stack);
void destory(LinkStack stack);