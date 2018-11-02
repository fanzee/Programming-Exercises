#include "String.h"

int main()
{
	String s;
	char arr[50];

	printf("请输入要赋值给s的串\n");
	scanf_s("%s", arr, 50);
	strAssign(&s, arr);

	printf("s为：%s\n", s.str);
	printf("长度为：%d\n", strLength(&s));
	printf("\n");
	String t;
	printf("请输入要赋值给t的串\n");
	scanf_s("%s", arr, 50);
	strAssign(&t, arr);
	printf("t为：%s\n", t.str);
	printf("长度为：%d\n", strLength(&t));

	printf("判断两串是否相等：");
	int res = strCompare(&s, &t);
	if(res < 0)
		printf("串t比较大！\n");
	else if (res > 0)
		printf("串s比较大！\n");
	else
		printf("两串相等！\n");

	printf("将两串连接起来\n");
	strConnect(&s, &t);
	printf("新串为：%s\n", s.str);
	printf("长度为：%d\n", strLength(&s));

	strCopy(&s, &t);
	printf("将串t复制到串s中，则串s的值为：%s\n",s.str);

	printf("请输入要插入s的子串：\n");
	scanf_s("%s", arr, 50);
	printf("请输入要插入的位置：\n");
	int pos;
	scanf_s("%d",&pos);
	Insert(&s, pos, arr);
	printf("插入后为：%s\n", s.str);
	printf("长度为：%d\n", strLength(&s));

	int len;
	printf("请输入要删除子串的长度：\n");
	scanf_s("%d",&len);
	printf("请输入要删除的位置：\n");
	scanf_s("%d", &pos);

	Delete(&s, pos, len);
	printf("删除后为：%s\n", s.str);
	printf("长度为：%d\n", strLength(&s));

	system("pause");
	return 0;
}