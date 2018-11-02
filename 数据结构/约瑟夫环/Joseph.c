#include "Joseph.h"

pHead createClist()
{
	pHead ph = (pHead)malloc(sizeof(Head));
	if (ph == NULL)
	{
		printf("节点为空！\n");
	}
	ph->length = 0;
	ph->next = NULL;
	return ph;
}

int isEmpty(pHead ph)
{
	if (ph == NULL)
		printf("节点为空！\n");
	if (ph->length == 0)
		return 1;
	return 0;
}

int insertClist(pHead ph, int pos, int val)
{
	if (ph == NULL || pos<0 || pos >ph->length)
	{
		printf("Error！\n");
		return 0;
	}
	pNode pval = (pNode)malloc(sizeof(Node));
	pval->data = val;

	if (isEmpty(ph))
	{
		ph->next = pval;
		pval->next = pval;
	}
	else
	{
		pNode pRear = ph->next;
		if (pos == 0)
		{
			while (pRear->next != ph->next)
			{
				pRear = pRear->next;
			}
			pval->next = ph->next;
			ph->next = pval;
			pRear->next = pval;
		}
		else
		{
			pNode pCur = ph->next;
			for (int i = 1; i < pos; i++)
			{
				pCur = pCur->next;
			}
			pval->next = pCur->next;
			pCur->next = pval;
		}
	}
	ph->length++;
	return 1;
}

void printClist(pHead ph)
{
	if (ph == NULL || ph->length == 0)
	{
		printf("Error！\n");
		return;
	}
	pNode temp = ph->next;
	for (int i = 0; i < ph->length; i++)
	{
		printf("%-4d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}