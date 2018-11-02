#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElemType;
#define MAXSIZE 50
typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue,*SeqQueue;

SeqQueue Create();
int getLength(SeqQueue sq);
int isEmpty(SeqQueue sq);
int Insert(SeqQueue sq, ElemType x);
ElemType Delete(SeqQueue sq);
int getHead(SeqQueue sq);
void Destory(SeqQueue sq);
