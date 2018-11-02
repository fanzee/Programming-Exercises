#include "search.h"

int InitHashTable(pHashTable h)
{
	h->elem = (int *)malloc(HASHSIZE * sizeof(int));
	if (h->elem == NULL)
	{
		return 0;
	}
	h->count = HASHSIZE;
	for (int i = 0; i < HASHSIZE; i++)
	{
		h->elem[i] = NULL;
	}
	return 1;
}

int Hash(int key)
{
	return key % HASHSIZE;
}

int InsertHash(pHashTable h, int key)
{
	if (h == NULL || h->elem == NULL)
	{
		return 0;
	}
	int address = Hash(key);
	while (h->elem[address] != NULL)
	{
		address = (address + 1) % HASHSIZE;
	}
	h->elem[address] = key;
	return 1;
}

int SearchHash(pHashTable h, int key, int address)
{
	if (h == NULL || h->elem == NULL)
	{
		return 0;
	}
	address = Hash(key);
	while (h->elem[address] != key)
	{
		address = (address + 1) % HASHSIZE;
		if (h->elem[address] == NULL || address == Hash(key))
		{
			return 0;
		}
	}
	return 1;
}