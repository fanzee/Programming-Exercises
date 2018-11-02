#include "seqstack.h"

int main(void)
{
	SeqStack stack = InitStack();
	int i;
	for (i = 0; i < 10; i++)
	{
		Push(stack, i);
	}
	printf("ջ�ĳ���Ϊ��%d\n", StackLength(stack));
	printf("ջ��Ԫ��Ϊ��%d\n", GetTop(stack));

	printf("ջ�е�Ԫ��Ϊ��\n");
	for (i = 0; i < 5; i++)
	{
		printf("%-5d", Pop(stack));
	}
	printf("\n");
	printf("ջ�ĳ���Ϊ��%d���������������\n", StackLength(stack));
	ClearStack(stack);
	printf("��պ��Ƿ�Ϊ�գ�0Ϊ�ǣ�-1Ϊ�񣩣�%d\n", IsEmpty(stack));
	printf("ջ�ĳ���Ϊ��%d\n", StackLength(stack));
	DestroyStack(stack);

	system("pause");
	return 0;
}