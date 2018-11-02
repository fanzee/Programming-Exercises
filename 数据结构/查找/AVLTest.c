#include "AVLTree.h"

int main(void)
{
	AVLTree t = NULL;
	AVLTree temp = NULL;
	char input;
	int type;
	printf("****************************************************************************\n");
	printf("*                               数据结构实验                                *\n");
	printf("*                        平衡二叉树的基本操作函数实现                       *\n");
	printf("*                                演示程序                                   *\n");
	printf("****************************************************************************\n");
	printf("\n");

	printf("请输入数据新建一棵平衡二叉树：\n");
	scanf_s("%c", &input, 1);
	t = insertAVL(t, input);

	showMessage();
	scanf_s("%d", &type);
	while (type == 1 || type == 2 || type == 3)
	{
		switch (type)
		{
		case (1):
			printf("请输入插入平衡二叉树的数据：\n");
			getchar();
			scanf_s("%c", &input, 1);
			t = insertAVL(t, input);
			printf("插入数据后，先序遍历平衡二叉树的结果是：\n");
			PreOrder(t);
			showMessage();
			scanf_s("%d", &type);
			break;
		case (2):
			printf("请输入删除平衡二叉树的数据：\n");
			getchar();
			scanf_s("%c", &input, 1);
			t = DeleteAVL(t, input);
			printf("删除数据后，先序遍历平衡二叉树的结果是：\n");
			if (t)
				PreOrder(t);
			else
				printf("平衡二叉树已经清空，无法删除！\n");
			printf("\n");
			showMessage();
			scanf_s("%d", &type);
			break;
		case (3):
			printf("请输入查找平衡二叉树的数据：\n");
			getchar();
			scanf_s("%c", &input, 1);
			temp = findAVL(t, input);
			if (temp)
				printf("平衡二叉树存在查找的数据，它是：%c\n", temp->data);
			else
				printf("平衡二叉树不存在查找的数据\n");
			printf("\n");
			showMessage();
			scanf_s("%d", &type);
			break;
		}
	}

	printf("\n");
	system("pause");
	return 0;
}