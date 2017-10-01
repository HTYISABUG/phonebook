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

entry *append(char lastName[], entry *table[])
{
    int key = hash(lastName, HASH_MODE);

    entry *e = (entry *) malloc(sizeof(entry));

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

void clear(entry *table[])
{
    entry *e;

    for (int i = 0; i < TABLE_SIZE; ++i) {
        while (table[i]) {
            e = table[i]->pNext;
            free(table[i]);
            table[i] = e;
        }
    }
}
