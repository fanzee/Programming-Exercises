#include "Joseph.h"


int main(void)
{
	int total;
	int number;
	printf("请输入约瑟夫环的总人数:\n");
	scanf_s("%d", &total);
	if (total <= 0)
	{
		printf("请输入正确的数字！\n");
		return 0;
	}
	printf("请输入踢出环的数字:\n");
	scanf_s("%d", &number);
	if (number <= 0)
	{
		printf("请输入正确的数字！\n");
		return 0;
	}

	pHead ph = createClist();
	
	for (int i = total; i > 0; i--)
	{
		insertClist(ph, 0, i);
	}

	printf("初始约瑟夫环为：\n");
	printClist(ph);
	printf("被踢的顺序是：\n");
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
	printf("链表最后留下的是：");
	printClist(ph);

	system("pause");
	return 0;
}