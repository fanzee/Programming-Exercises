#include "LinkQueue.h"

LinkQueue Create()
{
	LinkQueue lq = (LinkQueue)malloc(sizeof(Queue));
	lq->front = lq->rear = NULL;
	lq->length = 0;
}

int getLength(LinkQueue lq)
{
	return lq->length;
}

int isEmpty(LinkQueue lq)
{
	if (lq->length == 0)
		return 1;
	else
		return 0;
}

void Insert(LinkQueue lq,ElemType x)
{
	pNode pn = (pNode)malloc(sizeof(Node));
	pn->data = x;
	pn->next = NULL;

	if (isEmpty(lq))
	{
		lq->front = pn;
		lq->rear = pn;
	}
	else
	{
		lq->rear->next = pn;
		lq->rear = pn;
	}
	lq->length++;
}

ElemType getHead(LinkQueue lq)
{
	if (isEmpty(lq))
	{
		printf("队列已空，无法获得队头元素！\n");
		return 10000;
	}
	return lq->front->data;
}

pNode Delete(LinkQueue lq)
{
	if (isEmpty(lq))
	{
		printf("队列已空，无法删除\n");
		return NULL;
	}
	else
	{
		pNode temp = lq->front;
		lq->front = temp->next;
		lq->length--;
		return temp;
	}
}

void Destroy(LinkQueue lq)
{
	free(lq);
}















