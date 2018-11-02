#include <stdio.h>
#include <stdlib.h>

typedef char AVLData;
typedef struct AVLNode {
	AVLData data;    // 结点数据 
	int height;          //节点高度
	struct AVLNode *lchild;  //左孩子
	struct AVLNode *rchild;  //右孩子
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

/*递归实现先序，中序，后序遍历*/
void PreOrder(AVLTree t);
void showMessage();


