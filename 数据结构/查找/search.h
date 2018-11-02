#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 10

typedef struct
{
	int *elem;
	int count;
}HashTable,*pHashTable;
/*
	哈希表的基本操作函数
*/
int InitHashTable(pHashTable h);
int Hash(int key);
int InsertHash(pHashTable h, int key);
int SearchHash(pHashTable h, int key, int address);