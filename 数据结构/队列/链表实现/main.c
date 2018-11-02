#include "LinkQueue.h"

int main()
{
	LinkQueue lq = Create();
	for (int i = 0; i < 10; i++)
		Insert(lq, i);

	printf("队列长度为：%d\n", getLength(lq));
	printf("队头元素   出队元素\n");

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