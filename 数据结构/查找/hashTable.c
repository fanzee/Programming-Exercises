#include "search.h"

int main(void)
{
	HashTable h;
	InitHashTable(&h);
	int arr[HASHSIZE] = { 14,97,28,67,48,44,71,13,84,6 };
	for (int i = 0; i < HASHSIZE; i++)
	{
		InsertHash(&h, arr[i]);
	}

	int num;
	printf("请输入要查找的数据：\n");
	scanf_s("%d", &num);
	int address = Hash(num);

	int result = SearchHash(&h, num, address);
	if (result)
	{
		printf("查找成功！\n");
	}
	else
	{
		printf("查找失败！\n");
	}

	system("pause");
	return 0;
}