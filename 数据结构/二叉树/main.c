#include "BiTree.h"

int main(void)
{
	printf("���������Ľڵ��Ԫ��ֵ��\n");
	BiTree t = CreateBiTree();
	printf("Ҷ�ӵ���Ŀ�ǣ�%d\n", GetLeafNum(t));
	printf("��������ǣ�%d\n", GetDepth(t));

	printf("t��α���Ϊ��");
	LevelOrder(t);
	printf("\n");

	//printf("t�������Ϊ��");
	//PreOrder(t);
	//printf("\n");

	//printf("t�������Ϊ��(�ǵݹ�)");
	//preOrder(t);
	//printf("\n");

	//printf("t�������Ϊ(�ݹ�)��");
	//InOrder(t);
	//printf("\n");

	//printf("t�������Ϊ(�ǵݹ�)��");
	//inOrder(t);
	//printf("\n");

	//printf("t�������Ϊ��");
	//LastOrder(t);
	//printf("\n");

	//printf("t�������Ϊ��");
	//LevelOrder(t);
	//printf("\n");

	//BiTree q = CopyTree(t);
	//printf("��t���ƹ�����q�������Ϊ��");
	//PreOrder(q);
	//printf("\n");

	//FreeBiTree(t);
	//FreeBiTree(q);
	//printf("���������ͷţ�\n");

	system("pause");
	return 0;
}
