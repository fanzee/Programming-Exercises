#include "AVLTree.h"

int Max(int a, int b)
{
	return a > b ? a : b;
}

int getHeight(AVLTree t)
{
	if (t == NULL)
		return -1;
	else
		return t->height;
}

AVLTree insertAVL(AVLTree t, AVLData x)
{
	if (!t)
	{
		t = malloc(sizeof(AVLNode));
		t->data = x;
		t->height = 0;
		t->lchild = t->rchild = NULL;
	}
	else if (x < t->data)
	{
		t->lchild = insertAVL(t->lchild, x);
		if (getHeight(t->lchild) - getHeight(t->rchild) == 2)
		{
			if (x < t->lchild->data)
				t = rightRotation(t);
			else
				t = leftRightRotation(t);
		}
	}
	else if (x > t->data)
	{
		t->rchild = insertAVL(t->rchild, x);
		if (getHeight(t->lchild) - getHeight(t->rchild) == -2)
		{
			if (x > t->rchild->data)
				t = leftRotation(t);
			else
				t = rightleftRotation(t);
		}
	}
	else
	{
		printf("插入的值已经在平衡二叉树中，无法插入！\n");
		return NULL;
	}
	t->height = Max(getHeight(t->lchild), getHeight(t->rchild)) + 1;
	return t;
}

AVLTree leftRotation(AVLTree t)
{
	AVLTree temp = t->rchild;
	t->rchild = temp->lchild;
	temp->lchild = t;
	t->height = Max(getHeight(t->lchild), getHeight(t->rchild)) + 1;
	temp->height = Max(getHeight(temp->rchild), t->height) + 1;
	return temp;
}

AVLTree rightRotation(AVLTree t)
{
	AVLTree temp = t->lchild;
	t->lchild = temp->rchild;
	temp->rchild = t;
	t->height = Max(getHeight(t->lchild), getHeight(t->rchild)) + 1;
	temp->height = Max(getHeight(temp->lchild), t->height) + 1;
	return temp;
}

AVLTree leftRightRotation(AVLTree t)
{
	t->lchild = leftRotation(t->lchild);
	return rightRotation(t);
}

AVLTree rightleftRotation(AVLTree t)
{
	t->rchild = rightRotation(t->rchild);
	return leftRotation(t);
}

AVLTree DeleteAVL(AVLTree t, AVLData x)
{
	if (!t)
	{
		return NULL;
	}
	if (x < t->data)
		t->lchild = DeleteAVL(t->lchild, x);
	else if (x > t->data)
		t->rchild = DeleteAVL(t->rchild, x);
	else
	{
		if (t->lchild&&t->rchild)
		{
			AVLTree temp = t->rchild;
			while (temp->lchild != NULL)
				temp = temp->lchild;
			t->data = temp->data;
			t->rchild = DeleteAVL(t->rchild, temp->data);
			if (getHeight(t->lchild) - getHeight(t->rchild) == 2)
			{
				if (t->lchild->rchild != NULL && getHeight(t->lchild->rchild) > getHeight(t->lchild->lchild))
					leftRightRotation(t);
				else
					rightRotation(t);
			}
			t->height = Max(getHeight(t->lchild), getHeight(t->rchild));
		}
		else
		{
			AVLTree tmp = t;
			if (!t->lchild)
				t = t->rchild;
			else if (!t->rchild)
				t = t->lchild;
		}
	}
	return t;
}

AVLTree findAVL(AVLTree t, AVLData x)
{
	while (t)
	{
		if (x > t->data)
			t = t->rchild;
		else if (x < t->data)
			t = t->lchild;
		else
			return t;
	}
	return NULL;
}

void PreOrder(AVLTree t)
{
	if (t)
	{
		printf("%c", t->data);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

void showMessage()
{
	printf("\n");
	printf("---------------------------------------------\n");
	printf("|        请输入数字对应您将要执行的操作     |\n");
	printf("|           1 -> 插入二叉树节点             |\n");
	printf("|           2 -> 删除二叉树节点             |\n");
	printf("|           3 -> 查找二叉树节点             |\n");
	printf("|           0 -> 退出程序                   |\n");
	printf("---------------------------------------------\n");
	printf("\n");
}


