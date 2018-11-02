#include "String.h"

void strAssign(String *s, char *c)
{
	int i = 0;
	while (c[i] != '\0')
		i++;
	s->str = (char *)malloc((i + 1)*sizeof(char));
	s->length = i;

	int j;
	for (j = 0; j <= i; j++)
		s->str[j] = c[j];
	s->str[j + 1] = '\0';
}

int strLength(String *s)
{
	return s->length;
}

void strCopy(String *s, String *t)//串t复制到串s中
{
	s->str = (char *)malloc((t->length) * sizeof(char));
	int i;
	for (i = 0; i <= t->length; i++)
		s->str[i] = t->str[i];

	s->str[i + 1] = '\0';
	s->length = t->length;
}

int strEqual(String *s, String *t)
{
	if (s->length == t->length)
	{
		while (*(s->str++) != *(t->str++))
		{
			printf("两串不相等！\n");
			return 0;
		}
		printf("两串相等！\n");
		return 1;
	}
	printf("两串不相等！\n");
	return 0;
}

void strConnect(String *s, String *t)
{
	int len = s->length + t->length;
	char *temp = (char *)malloc(len * sizeof(char));
	int i, j;
	for (i = 0; i < s->length; i++)
		temp[i] = s->str[i];
	for (j = 0; j < t->length; j++,i++)
		temp[i] = t->str[j];

	temp[i] = '\0';
	s->str = temp;
	s->length = len;
}

int strCompare(String *s, String *t)
{
	if (s && t)
	{
		int sl = s->length, tl = s->length;
		while (*(s->str) != '\0'&& *(t->str) != '\0')
		{
			if (*(s->str) < *(t->str))
				return -1;
			else if (*(s->str) > *(t->str))
				return 1;
			else
			{
				s->str++;
				t->str++;
			}
		}
		if (sl < tl)
			return -1;
		else if (sl > tl)
			return 1;
		else
			return 0;
	}
	return 10000;
}

void Insert(String *s, int pos, char *t)
{
	if (pos<0 || pos>s->length)
	{
		printf("插入位置错误！\n");
		return;
	}
	int tlen = 0;
	while (t[tlen] != '\0')
		tlen++;

	char *temp = (char *)malloc((tlen + s->length) * sizeof(char));
	int i;
	for (i = 0; i < pos; i++)
		temp[i] = s->str[i];

	int j = 0;
	while (t[j] != '\0')
	{
		temp[i] = t[j];
		i++;
		j++;
	}

	while (pos < s->length)
	{
		temp[i] = s->str[pos];
		i++;
		pos++;
	}
	temp[i] = '\0';
	s->str = temp;
	s->length += tlen;
}

void Delete(String *s, int pos, int len)
{
	if (pos<0 || pos>s->length || len > s->length - pos)
	{
		printf("删除位置错误！\n");
		return;
	}
	char *temp = (char *)malloc((s->length - len) * sizeof(char));
	int i;
	for (i = 0; i < pos; i++)
		temp[i] = s->str[i];

	int j;
	for (j = pos + len; j < s->length; j++)
	{
		temp[i] = s->str[j];
		i++;
	}
	temp[i] = '\0';
	s->str = temp;
	s->length -= len;
}