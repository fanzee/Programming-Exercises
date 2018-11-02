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
	printf("������Ҫ���ҵ����ݣ�\n");
	scanf_s("%d", &num);
	int address = Hash(num);

	int result = SearchHash(&h, num, address);
	if (result)
	{
		printf("���ҳɹ���\n");
	}
	else
	{
		printf("����ʧ�ܣ�\n");
	}

	system("pause");
	return 0;
}