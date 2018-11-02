#include "seqstack.h"

SeqStack InitStack()
{
	SeqStack stack = (SeqStack)malloc(sizeof(seqstack));
	stack->top = -1;
	return stack;
}

int IsEmpty(SeqStack stack)
{
	if (stack->top == -1)
		return 0;
	else
		return -1;
}

int IsFull(SeqStack stack)
{
	if (stack->top == MAXSIZE-1)
		return 0;
	else
		return -1;
}

int StackLength(SeqStack stack)
{
	return (stack->top + 1);
}

int Push(SeqStack stack, ElemType x)
{
	if (0==IsFull(stack))
		return -1;
	else
	{
		stack->data[++stack->top] = x;
		return 0;
	}
}

ElemType Pop(SeqStack stack)
{
	if (0==IsEmpty(stack))
		return INFINITY;
	else
		return stack->data[stack->top--];
}

ElemType GetTop(SeqStack stack)
{
	if(0==IsEmpty(stack))
		return INFINITY;
	else
		return stack->data[stack->top];
}

void ClearStack(SeqStack stack)
{
	stack->top = -1;
}
void DestroyStack(SeqStack stack)
{
	free(stack);
	stack = NULL;
}