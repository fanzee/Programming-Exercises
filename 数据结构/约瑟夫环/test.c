#include "Joseph.h"


int main(void)
{
	int total;
	int number;
	printf("������Լɪ�򻷵�������:\n");
	scanf_s("%d", &total);
	if (total <= 0)
	{
		printf("��������ȷ�����֣�\n");
		return 0;
	}
	printf("�������߳���������:\n");
	scanf_s("%d", &number);
	if (number <= 0)
	{
		printf("��������ȷ�����֣�\n");
		return 0;
	}

	pHead ph = createClist();
	
	for (int i = total; i > 0; i--)
	{
		insertClist(ph, 0, i);
	}

	printf("��ʼԼɪ��Ϊ��\n");
	printClist(ph);
	printf("���ߵ�˳���ǣ�\n");
	pNode node = ph->next;
	while (node->next != node)
	{
		for (int i = 1; i < number - 1; i++)
		{
			node = node->next;
		}
		pNode temp = node->next;
		if (temp == ph->next)
		{
			ph->next = temp->next;
			node->next = temp->next;
			printf("%-4d", temp->data);
			free(temp);
			ph->length--;
		}
		else
		{
			node->next = temp->next;
			node->next = temp->next;
			printf("%-4d", temp->data);
			free(temp);
			ph->length--;
		}
		node = node->next;
	}

	node = node->next;
	printf("\n");
	printf("����������µ��ǣ�");
	printClist(ph);

	system("pause");
	return 0;
}