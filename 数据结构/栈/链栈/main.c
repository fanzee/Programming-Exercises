#include "linkstack.h"

int main()
{
	LinkStack stack = create();
	printf("��ջ�Ƿ�Ϊ�գ�%d\n", isEmpty(stack));

	for (int i = 0; i < 10; i++)
		push(stack, i);

	printf("��ջ�Ƿ�Ϊ�գ�%d\n", isEmpty(stack));
	printf("��ջ����Ϊ��%d\n", getSize(stack));

	pNode temp = getTop(stack);
	printf("��ջջ��Ԫ��Ϊ��%d\n", getTop(stack)->data);

	while(stack->size)
		printf("%-4d", pop(stack)->data);

	printf("\n");

	destory(stack);

	system("pause");
	return 0;
}