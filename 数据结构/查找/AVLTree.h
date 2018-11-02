#include <stdio.h>
#include <stdlib.h>

typedef char AVLData;
typedef struct AVLNode {
	AVLData data;    // ������� 
	int height;          //�ڵ�߶�
	struct AVLNode *lchild;  //����
	struct AVLNode *rchild;  //�Һ���
}AVLNode, *AVLTree;

int Max(int a, int b);
int getHeight(AVLTree t);
AVLTree leftRotation(AVLTree t);
AVLTree rightRotation(AVLTree t);
AVLTree leftRightRotation(AVLTree t);
AVLTree rightleftRotation(AVLTree t);
AVLTree insertAVL(AVLTree t, AVLData x);
AVLTree DeleteAVL(AVLTree t, AVLData x);
AVLTree findAVL(AVLTree t, AVLData x);

/*�ݹ�ʵ���������򣬺������*/
void PreOrder(AVLTree t);
void showMessage();


