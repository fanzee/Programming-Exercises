#include "SeqQueue.h"

int main()
{
	SeqQueue sq = Create();
	for (int i = 0; i < 10; i++)
		Insert(sq, i);

	printf("���г���Ϊ��%d\n", getLength(sq));
	printf("��ͷԪ��   ����Ԫ��\n");

	while (sq->front != sq->rear)
	{
		ElemType temp = getHead(sq);
		printf("    %d    ", temp);
		temp = Delete(sq);
		printf("    %d\n", temp);
	}

	printf("���г���Ϊ��%d\n", getLength(sq));
	Destory(sq);
		
	system("pause");
	return 0;
}