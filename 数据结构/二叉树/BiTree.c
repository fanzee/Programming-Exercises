#include "BiTree.h"

//递归实现二叉树遍历
void PreOrder(BiTree t)
{
	if (t)
	{
		printf("%c", t->data);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

void InOrder(BiTree t)
{
	if (t)
	{
		InOrder(t->lchild);
		printf("%c", t->data);
		InOrder(t->rchild);
	}
}

void LastOrder(BiTree t)
{
	if (t)
	{
		LastOrder(t->lchild);
		LastOrder(t->rchild);
		printf("%c", t->data);
	}
}

//二叉树基本操作
BiTree CreateBiTree()
{
	char ch;
	scanf_s("%c", &ch,1);
	BiTree temp;
	if (ch == '#')
		temp = NULL;
	else
	{
		temp = (BiTree)malloc(sizeof(BiNode));
		temp->data = ch;
		temp->lchild = CreateBiTree();
		temp->rchild = CreateBiTree();
	}
	return temp;
}

void FreeBiTree(BiTree t)
{
	if (t == NULL)
		return;
	if (t->lchild != NULL)
	{
		FreeBiTree(t->lchild);
		t->lchild = NULL;
	}
	if (t->rchild != NULL)
	{
		FreeBiTree(t->rchild);
		t->lchild = NULL;
	}
	free(t);
}

int GetLeafNum(BiTree t)
{
	if (t == NULL)
		return 0;

	if (t->lchild == NULL && t->rchild == NULL)
		return 1;

	return 	GetLeafNum(t->lchild) + GetLeafNum(t->rchild);
}

int GetDepth(BiTree t)
{
	int lDepth = 0;
	int rDepth = 0;
	if (t != NULL)
	{
		lDepth = GetDepth(t->lchild);
		rDepth = GetDepth(t->rchild);
		return 1 + (lDepth > rDepth ? lDepth : rDepth);
	}
	return 0;
}

BiTree CopyTree(BiTree t)
{
	BiTree temp = (BiTree)malloc(sizeof(BiNode));
	temp->lchild = NULL;
	temp->rchild = NULL;

	if (t == NULL || temp == NULL)
		return NULL;

	temp->lchild = CopyTree(t->lchild);
	temp->rchild = CopyTree(t->rchild);
	temp->data = t->data;

	return temp;
}

//非递归实现二叉树遍历(链栈)
LinkStack createStack()
{
	LinkStack stack = (LinkStack)malloc(sizeof(Stack));
	if (stack != NULL)
	{
		stack->top = NULL;
		stack->size = 0;
	}
	return stack;
}

int isStackEmpty(LinkStack stack)
{
	if (stack->top == NULL || stack->size == 0)
		return 1;
	else
		return 0;
}

pStackNode getTop(LinkStack stack)
{
	if (stack->size == 0)
		return NULL;
	else
		return stack->top;
}

int push(LinkStack stack, StackType x)
{
	pStackNode node = (pStackNode)malloc(sizeof(StackNode));
	if (node != NULL)
	{
		node->data = x;
		node->next = getTop(stack);
		stack->top = node;
		stack->size++;
	}
	return 1;
}

pStackNode pop(LinkStack stack)
{
	if (isStackEmpty(stack) == 1)
		return NULL;
	else
	{
		pStackNode node = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		return node;
	}
}

BiTree Search(BiTree t, LinkStack stack)
{
	if (t == NULL)
		return NULL;

	while (t->lchild != NULL)
	{
		push(stack, t);
		t = t->lchild;
	}
	return t;
}

void inOrder(BiTree t)
{
	if (t == NULL)
		return;
	BiTree temp = t;
	LinkStack stack = createStack();
	while (temp != NULL || isStackEmpty(stack) == 0)
	{
		while (temp != NULL)
		{
			push(stack, temp);
			temp = temp->lchild;
		}
		if (isStackEmpty(stack) == 0)
		{
			temp = pop(stack)->data;
			printf("%c", temp->data);
			temp = temp->rchild;
		}
	}
}

void preOrder(BiTree t)
{
	if (t == NULL)
		return;
	BiTree temp = t;
	LinkStack stack = createStack();
	while (temp!=NULL || isStackEmpty(stack) == 0)
	{
		while (temp != NULL)
		{
			printf("%c", temp->data);
			push(stack, temp);
			temp = temp->lchild;
		}
		if (isStackEmpty(stack) == 0)
		{
			temp = pop(stack)->data;
			temp = temp->rchild;
		}
	}
}

LinkQueue createQueue()
{
	LinkQueue lq = (LinkQueue)malloc(sizeof(Queue));
	lq->front = lq->rear = NULL;
	lq->length = 0;
	return lq;
}

int isQueueEmpty(LinkQueue lq)
{
	if (lq->length == 0)
		return 1;
	else
		return 0;
}

void insertQueue(LinkQueue lq, QueueType x)
{
	pQueueNode pn = (pQueueNode)malloc(sizeof(QueueNode));
	pn->data = x;
	pn->next = NULL;

	if (isQueueEmpty(lq))
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

pQueueNode deleteQueue(LinkQueue lq)
{
	if (isQueueEmpty(lq))
	{
		printf("队列已空，无法删除\n");
		return NULL;
	}
	else
	{
		pQueueNode temp = lq->front;
		lq->front = temp->next;
		lq->length--;
		return temp;
	}
}

void LevelOrder(BiTree t)
{
	if (!t)
		return;

	LinkQueue queue = createQueue();
	BiTree temp;
	insertQueue(queue, t);
	while (!isQueueEmpty(queue))
	{
		temp = deleteQueue(queue);
		printf("%c", temp->data);
		if(temp->lchild)
			insertQueue(queue, temp->lchild);
		if (temp->rchild)
			insertQueue(queue, temp->rchild);
	}
}




