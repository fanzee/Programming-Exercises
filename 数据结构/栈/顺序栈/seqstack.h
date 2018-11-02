#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define INFINITY 65535

typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}seqstack,*SeqStack;

SeqStack InitStack();
int IsEmpty(SeqStack stack);
int IsFull(SeqStack stack);
int StackLength(SeqStack stack);

int Push(SeqStack stack, ElemType x);
ElemType Pop(SeqStack stack);
ElemType GetTop(SeqStack stack);

void ClearStack(SeqStack stack);
void DestroyStack(SeqStack stack);

