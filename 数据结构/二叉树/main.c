#include "BiTree.h"

int main(void)
{
	printf("请输入树的节点的元素值！\n");
	BiTree t = CreateBiTree();
	printf("叶子的数目是：%d\n", GetLeafNum(t));
	printf("树的深度是：%d\n", GetDepth(t));

	printf("t层次遍历为：");
	LevelOrder(t);
	printf("\n");

	//printf("t先序遍历为：");
	//PreOrder(t);
	//printf("\n");

	//printf("t先序遍历为：(非递归)");
	//preOrder(t);
	//printf("\n");

	//printf("t中序遍历为(递归)：");
	//InOrder(t);
	//printf("\n");

	//printf("t中序遍历为(非递归)：");
	//inOrder(t);
	//printf("\n");

	//printf("t后序遍历为：");
	//LastOrder(t);
	//printf("\n");

	//printf("t层序遍历为：");
	//LevelOrder(t);
	//printf("\n");

	//BiTree q = CopyTree(t);
	//printf("由t复制过来的q先序遍历为：");
	//PreOrder(q);
	//printf("\n");

	//FreeBiTree(t);
	//FreeBiTree(q);
	//printf("二叉树已释放！\n");

	system("pause");
	return 0;
}
