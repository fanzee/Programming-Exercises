#include "linkstack.h"

LinkStack create()
{
	LinkStack stack = (LinkStack)malloc(sizeof(Stack));
	if (stack == NULL)
		return NULL;
	else
	{
		stack->top = NULL;
		stack->size = 0;
		return stack;
	}
}

int isEmpty(LinkStack stack)
{
	if (stack->top == NULL || stack->size == 0)
		return 1;
	else
		return 0;
}

int getSize(LinkStack stack)
{
	return stack->size;
}

pNode getTop(LinkStack stack)
{
	if (stack->size == 0)
		return NULL;
	else
		return stack->top;
}

int push(LinkStack stack, ElemType x)
{
	pNode node = (pNode)malloc(sizeof(Node));
	if (node == NULL)
		return 0;
	else
	{
		node->data = x; 
		node->next = getTop(stack);
		stack->top = node;
		stack->size++;
	}
	return 1;
}

pNode pop(LinkStack stack)
{
	if (isEmpty(stack) == 1)
		return NULL;
	else
	{
		pNode node = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		return node;
	}
}

void destory(LinkStack stack)
{
	if (isEmpty(stack) == 1)
		free(stack);
	else
	{
		pNode node;
		while (stack->size)
		{
			node = pop(stack);
			free(node);
		}
	}
}