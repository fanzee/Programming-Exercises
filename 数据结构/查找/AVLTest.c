#include "AVLTree.h"

int main(void)
{
	AVLTree t = NULL;
	AVLTree temp = NULL;
	char input;
	int type;
	printf("****************************************************************************\n");
	printf("*                               ���ݽṹʵ��                                *\n");
	printf("*                        ƽ��������Ļ�����������ʵ��                       *\n");
	printf("*                                ��ʾ����                                   *\n");
	printf("****************************************************************************\n");
	printf("\n");

	printf("�����������½�һ��ƽ���������\n");
	scanf_s("%c", &input, 1);
	t = insertAVL(t, input);

	showMessage();
	scanf_s("%d", &type);
	while (type == 1 || type == 2 || type == 3)
	{
		switch (type)
		{
		case (1):
			printf("���������ƽ������������ݣ�\n");
			getchar();
			scanf_s("%c", &input, 1);
			t = insertAVL(t, input);
			printf("�������ݺ��������ƽ��������Ľ���ǣ�\n");
			PreOrder(t);
			showMessage();
			scanf_s("%d", &type);
			break;
		case (2):
			printf("������ɾ��ƽ������������ݣ�\n");
			getchar();
			scanf_s("%c", &input, 1);
			t = DeleteAVL(t, input);
			printf("ɾ�����ݺ��������ƽ��������Ľ���ǣ�\n");
			if (t)
				PreOrder(t);
			else
				printf("ƽ��������Ѿ���գ��޷�ɾ����\n");
			printf("\n");
			showMessage();
			scanf_s("%d", &type);
			break;
		case (3):
			printf("���������ƽ������������ݣ�\n");
			getchar();
			scanf_s("%c", &input, 1);
			temp = findAVL(t, input);
			if (temp)
				printf("ƽ����������ڲ��ҵ����ݣ����ǣ�%c\n", temp->data);
			else
				printf("ƽ������������ڲ��ҵ�����\n");
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