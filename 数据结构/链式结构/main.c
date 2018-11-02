#include"List.h"

int main()
{
	pHead head = InitLinkList();
	LinkList temp;
	int length;
	length=size(head);
	printf("初始化后，链表的长度为%d\n",length);

	for (int i = 1; i <= 10; i++)
		insert(head, i, i);
	
	length = size(head);
	printf("插入数据后链表的长度为%d\n", length);
	showList(head);

	temp = findByPlace(head, 8);
	printf("根据位置查看链表的值，如第8个位置的值是：%d\n",temp->data );
	temp = findByValue(head, 5);
	printf("根据值返回链表的节点，如链表中值为5的节点值是是：%d\n", temp->data);
	printf("删除节点测试用例：第三个节点，删除后的链表为:\n");
	delete(head, 3);
	showList(head);

	printf("修改节点测试用例：第二个节点修改为0，修改后的链表为:\n");
	edit(head, 2, 0);
	showList(head);

	printf("清除链表：");
	clean(head);
	if (head->next == NULL)
		printf("clean");
	else
		printf("destroy");

	printf("\n");

	printf("销毁链表：");
	destroy(head);
	if (head->next == NULL)
		printf("clean");
	else
		printf("destroy");

	system("pause");
	return 0;
}