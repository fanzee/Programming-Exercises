#include "SeqQueue.h"

SeqQueue Create()
{
	SeqQueue sq = (SeqQueue)malloc(sizeof(Queue));
	sq->front = sq->rear = 0;
	memset(sq->data, 0, MAXSIZE * sizeof(ElemType));
	return sq;
}

int getLength(SeqQueue sq)
{
	return (sq->rear - sq->front);
}

int isEmpty(SeqQueue sq)
{
	if (sq->front == sq->rear)
		return 1;
	else
		return 0;
}

int Insert(SeqQueue sq, ElemType x)
{
	if (sq->rear==MAXSIZE-1)
	{
		printf("队列已满，无法插入元素!\n");
		return 0;
	}
	else 
	{
		sq->data[sq->rear++] = x;
		return 1;
	}
}

ElemType Delete(SeqQueue sq)
{
	if (isEmpty(sq))
	{
		printf("队列为空，无法删除!\n");
		return 10000;
	}
	ElemType temp = sq->data[sq->front++];
	return temp;
}

int getHead(SeqQueue sq)
{
	if (isEmpty(sq))
	{
		printf("队列为空，无法获取队头元素！\n");
		return -1;
	}
	else
		return sq->data[sq->front];
}

void Destory(SeqQueue sq)
{
	free(sq);
	printf("队列已销毁!\n");
}