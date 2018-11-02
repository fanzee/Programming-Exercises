#include"List.h"

int main()
{
	pHead head = InitLinkList();
	LinkList temp;
	int length;
	length=size(head);
	printf("��ʼ��������ĳ���Ϊ%d\n",length);

	for (int i = 1; i <= 10; i++)
		insert(head, i, i);
	
	length = size(head);
	printf("�������ݺ�����ĳ���Ϊ%d\n", length);
	showList(head);

	temp = findByPlace(head, 8);
	printf("����λ�ò鿴�����ֵ�����8��λ�õ�ֵ�ǣ�%d\n",temp->data );
	temp = findByValue(head, 5);
	printf("����ֵ��������Ľڵ㣬��������ֵΪ5�Ľڵ�ֵ���ǣ�%d\n", temp->data);
	printf("ɾ���ڵ�����������������ڵ㣬ɾ���������Ϊ:\n");
	delete(head, 3);
	showList(head);

	printf("�޸Ľڵ�����������ڶ����ڵ��޸�Ϊ0���޸ĺ������Ϊ:\n");
	edit(head, 2, 0);
	showList(head);

	printf("�������");
	clean(head);
	if (head->next == NULL)
		printf("clean");
	else
		printf("destroy");

	printf("\n");

	printf("��������");
	destroy(head);
	if (head->next == NULL)
		printf("clean");
	else
		printf("destroy");

	system("pause");
	return 0;
}