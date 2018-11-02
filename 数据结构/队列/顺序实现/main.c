#include "SeqQueue.h"

int main()
{
	SeqQueue sq = Create();
	for (int i = 0; i < 10; i++)
		Insert(sq, i);

	printf("队列长度为：%d\n", getLength(sq));
	printf("队头元素   出队元素\n");

	while (sq->front != sq->rear)
	{
		ElemType temp = getHead(sq);
		printf("    %d    ", temp);
		temp = Delete(sq);
		printf("    %d\n", temp);
	}

	printf("队列长度为：%d\n", getLength(sq));
	Destory(sq);
		
	system("pause");
	return 0;
}