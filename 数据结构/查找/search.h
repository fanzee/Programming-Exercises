#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 10

typedef struct
{
	int *elem;
	int count;
}HashTable,*pHashTable;
/*
	��ϣ��Ļ�����������
*/
int InitHashTable(pHashTable h);
int Hash(int key);
int InsertHash(pHashTable h, int key);
int SearchHash(pHashTable h, int key, int address);