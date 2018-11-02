#include "seqstack.h"

int main(void)
{
	SeqStack stack = InitStack();
	int i;
	for (i = 0; i < 10; i++)
	{
		Push(stack, i);
	}
	printf("栈的长度为：%d\n", StackLength(stack));
	printf("栈顶元素为：%d\n", GetTop(stack));

	printf("栈中的元素为：\n");
	for (i = 0; i < 5; i++)
	{
		printf("%-5d", Pop(stack));
	}
	printf("\n");
	printf("栈的长度为：%d，接下来进行清空\n", StackLength(stack));
	ClearStack(stack);
	printf("清空后是否为空（0为是，-1为否）：%d\n", IsEmpty(stack));
	printf("栈的长度为：%d\n", StackLength(stack));
	DestroyStack(stack);

	system("pause");
	return 0;
}