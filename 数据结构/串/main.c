#include "String.h"

int main()
{
	String s;
	char arr[50];

	printf("������Ҫ��ֵ��s�Ĵ�\n");
	scanf_s("%s", arr, 50);
	strAssign(&s, arr);

	printf("sΪ��%s\n", s.str);
	printf("����Ϊ��%d\n", strLength(&s));
	printf("\n");
	String t;
	printf("������Ҫ��ֵ��t�Ĵ�\n");
	scanf_s("%s", arr, 50);
	strAssign(&t, arr);
	printf("tΪ��%s\n", t.str);
	printf("����Ϊ��%d\n", strLength(&t));

	printf("�ж������Ƿ���ȣ�");
	int res = strCompare(&s, &t);
	if(res < 0)
		printf("��t�Ƚϴ�\n");
	else if (res > 0)
		printf("��s�Ƚϴ�\n");
	else
		printf("������ȣ�\n");

	printf("��������������\n");
	strConnect(&s, &t);
	printf("�´�Ϊ��%s\n", s.str);
	printf("����Ϊ��%d\n", strLength(&s));

	strCopy(&s, &t);
	printf("����t���Ƶ���s�У���s��ֵΪ��%s\n",s.str);

	printf("������Ҫ����s���Ӵ���\n");
	scanf_s("%s", arr, 50);
	printf("������Ҫ�����λ�ã�\n");
	int pos;
	scanf_s("%d",&pos);
	Insert(&s, pos, arr);
	printf("�����Ϊ��%s\n", s.str);
	printf("����Ϊ��%d\n", strLength(&s));

	int len;
	printf("������Ҫɾ���Ӵ��ĳ��ȣ�\n");
	scanf_s("%d",&len);
	printf("������Ҫɾ����λ�ã�\n");
	scanf_s("%d", &pos);

	Delete(&s, pos, len);
	printf("ɾ����Ϊ��%s\n", s.str);
	printf("����Ϊ��%d\n", strLength(&s));

	system("pause");
	return 0;
}