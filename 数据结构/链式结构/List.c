#include "List.h"

pHead InitLinkList()
{
	pHead  ph = (pHead)malloc(sizeof(Head));
	ph->length = 0;
	ph->next = NULL;
	return ph;
}

int size(pHead ph)
{
	if (ph == NULL)
	{
		printf("Empty List!\n");
		return 0;
	}
	return ph->length;
}

int insert(pHead ph, int pos, ElemType x)
{
	if (ph == NULL || pos<1 || pos>ph->length+1)
	{
		printf("Error!\n");
		return 0;
	}
	LinkList pval = (LinkList)malloc(sizeof(List));
	pval->data = x;

	LinkList pCur = ph->next;
	if (pos == 1)
	{
		pval->next = pCur;
		ph->next = pval;
	}
	else
	{
		for (int i = 2; i < pos; i++)
		{
			pCur = pCur->next;
		}
		pval->next = pCur->next;
		pCur->next = pval;
	}
	ph->length++;
	return 1;
}

LinkList findByValue(pHead ph, ElemType x)
{
	if (ph == NULL)
	{
		printf("Empty List!\n");
		return NULL;
	}
	LinkList temp = ph->next;
	while (temp->data != x && temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->next == NULL && temp->data != x)
	{
		printf("Can't find this value!\n");
		return NULL;
	}
	else
		return temp;
}

LinkList findByPlace(pHead ph, int k)
{
	if (ph == NULL)
	{
		printf("Empty List!\n");
		return NULL;
	}
	LinkList temp = ph->next;
	int i = 1;
	while (temp!=NULL && i<k)
	{
		temp = temp->next;
		i++;
	}
	if (k == i)
		return temp;
	else
		return NULL;
}

int delete(pHead ph, int i)
{
	if (ph == NULL)
	{
		printf("Empty List!\n");
		return 0;
	}
	LinkList p = (LinkList)malloc(sizeof(List));
	LinkList s = (LinkList)malloc(sizeof(List));
	if (p == NULL ||s == NULL)
	{
		printf("ERROR!\n");
		return 0;
	} 
	if (i == 1)
	{
		s = ph->next;
		ph->next = s->next;
		free(s);
		return 1;
	}
	else
	{
		p = findByPlace(ph, i - 1);
		s = p->next;
		p->next = s->next;
		free(s);
		return 1;
	}
}

void showList(pHead ph)
{
	if (ph == NULL)
	{
		printf("Empty List!\n");
	}
	else
	{
		LinkList temp = ph->next;
		while (temp)
		{
			printf("%-5d", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int edit(pHead ph, int index, ElemType x)
{
	if (ph == NULL || ph->next == NULL || index > ph->length)
	{
		printf("ERROR!\n");
		return 0;
	}
	else
	{
		LinkList temp = findByPlace(ph, index);
		temp->data = x;
		return 1;
	}
}

int clean(pHead ph)
{
	if (ph == NULL || ph->next == NULL)
	{
		printf("Empty List!\n");
		return 0;
	}
	LinkList p = ph->next;
	LinkList q;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	ph->next = NULL;
	return 1;
}

int destroy(pHead ph)
{
	if(ph == NULL)
	{
		free(ph);
		return 1;
	}
	else
	{
		clean(ph);
		free(ph);
		return 1;
	}
}
