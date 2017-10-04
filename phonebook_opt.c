#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

enum {MOD, BKDR};
/*#define HASH_MODE MOD*/
#define HASH_MODE BKDR

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *table[])
{
    entry *e = table[hash(lastName, HASH_MODE)];

    while (e != NULL) {
        if (strcasecmp(lastName, e->lastName) == 0) {
            return e;
        }

        e = e->pNext;
    }

    return NULL;
}

entry *append(char lastName[], entry *table[], MemPool *pool)
{
    int key = hash(lastName, HASH_MODE);

    entry *e = (entry *) poolloc(sizeof(entry), pool);

    if (e) {
        e->pNext = table[key];
        strcpy(e->lastName, lastName);
        table[key] = e;
        return e;
    }

    return NULL;
}

unsigned int hash(char str[], int mode)
{
    const unsigned int seed = 13131;
    unsigned int h = 0;

    switch (mode) {
    case MOD:
        while (*str) {
            h += *str++;
        }
        break;
    case BKDR:
        while (*str) {
            h = h * seed + (*str++);
        }
        h &= 0x7FFFFFFF;
        break;
    }

    return (h % TABLE_SIZE);
}

void clear(entry *table[], MemPool *pool)
{
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = NULL;
    }

    free(pool);
}

entry *addData(entry *e)
{
    e->data = (Data *) malloc(sizeof(Data));

    return e;
}

void *poolloc(size_t size, MemPool *pool)
{
    if (pool->cnt + size <= pool->size) {
        void *p = pool->ptr + pool->cnt;
        pool->cnt += size;
        return p;
    }

    return NULL;
}

MemPool *memPool(size_t size)
{
    MemPool *pool = (MemPool *) malloc(sizeof(MemPool));

    if (pool) {
        pool->ptr = (void *) malloc(size);
        pool->size = size;
        pool->cnt = 0;
        return pool;
    }

    return NULL;
}
