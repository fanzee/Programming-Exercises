#include "linkstack.h"
extern char buffer[256];

int main()
{
	char str[50] = { 0 };
	printf("����������������ʽ��\n");
	scanf_s("%s", str,50);

	if (Transform(str) == -1)
		printf("ת���г��ִ���\n");
	else
		printf("ת����ı��ʽΪ��%s\n", buffer);

	int sum = calculate(buffer);
	printf("���Ϊ��%d\n", sum);

	system("pause");
	return 0;
}