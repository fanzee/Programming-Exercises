#include "LinkQueue.h"

int main()
{
	LinkQueue lq = Create();
	for (int i = 0; i < 10; i++)
		Insert(lq, i);

	printf("���г���Ϊ��%d\n", getLength(lq));
	printf("��ͷԪ��   ����Ԫ��\n");

	while (getLength(lq))
	{
		ElemType temp = getHead(lq);
		printf("    %d    ", temp);
		temp = Delete(lq)->data;
		printf("    %d\n", temp);
	}

	Destroy(lq);
	system("pause");
	return 0;
}