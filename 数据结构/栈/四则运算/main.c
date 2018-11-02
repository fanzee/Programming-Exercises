#include "linkstack.h"
extern char buffer[256];

int main()
{
	char str[50] = { 0 };
	printf("请输入四则运算表达式：\n");
	scanf_s("%s", str,50);

	if (Transform(str) == -1)
		printf("转换中出现错误！\n");
	else
		printf("转换后的表达式为：%s\n", buffer);

	int sum = calculate(buffer);
	printf("结果为：%d\n", sum);

	system("pause");
	return 0;
}