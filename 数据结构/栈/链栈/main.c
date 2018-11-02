#include "linkstack.h"

int main()
{
	LinkStack stack = create();
	printf("链栈是否为空：%d\n", isEmpty(stack));

	for (int i = 0; i < 10; i++)
		push(stack, i);

	printf("链栈是否为空：%d\n", isEmpty(stack));
	printf("链栈长度为：%d\n", getSize(stack));

	pNode temp = getTop(stack);
	printf("链栈栈顶元素为：%d\n", getTop(stack)->data);

	while(stack->size)
		printf("%-4d", pop(stack)->data);

	printf("\n");

	destory(stack);

	system("pause");
	return 0;
}