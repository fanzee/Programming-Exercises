#include <stdio.h>
#include <stdlib.h>

typedef struct string
{
	char *str;
	int length;
}String;
void strAssign(String *s, char *c);
int strLength(String *s);
void strCopy(String *s, String *t);
int strEqual(String *s, String *t);
void strConnect(String *s, String *t);
int strCompare(String *s, String *t);
void Insert(String *s, int pos, char *t);
void Delete(String *s, int pos, int len);