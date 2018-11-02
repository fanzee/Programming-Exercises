#include <stdio.h>
#include <stdlib.h>

/*树的定义和基本操作*/
typedef char TreeType;
typedef struct BiNode
{
	TreeType data;
	struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

BiTree CreateBiTree();
void FreeBiTree(BiTree t);
int GetLeafNum(BiTree t);
int GetDepth(BiTree t);
BiTree CopyTree(BiTree t);

/*递归实现先序，中序，后序遍历*/
void PreOrder(BiTree t);
void InOrder(BiTree t);
void LastOrder(BiTree t);

/*栈的定义与基本操作*/
typedef BiTree StackType;
typedef struct StackNode
{
	StackType data;
	struct StackNode *next;
}StackNode, *pStackNode;

typedef struct Stack
{
	pStackNode top;
	int size;
}Stack, *LinkStack;

LinkStack createStack();
int isStackEmpty(LinkStack stack);
pStackNode getTop(LinkStack stack);
int push(LinkStack stack,StackType x);
pStackNode pop(LinkStack stack);
BiTree Search(BiTree t, LinkStack stack);
void inOrder(BiTree t);
void preOrder(BiTree t);

/*队列的定义与基本操作*/
typedef BiTree QueueType;
typedef struct QueueNode
{
	QueueType data;
	struct QueueNode *next;
}QueueNode, *pQueueNode;

typedef struct Queue
{
	pQueueNode front;
	pQueueNode rear;
	int length;
}Queue, *LinkQueue;

LinkQueue createQueue();
int isQueueEmpty(LinkQueue lq);
void insertQueue(LinkQueue lq, QueueType x);
pQueueNode deleteQueue(LinkQueue lq);
void LevelOrder(BiTree t);





