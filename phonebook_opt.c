#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *table[])
{
    entry *e = table[hash(lastName)];

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
    int key = hash(lastName);

    entry *e = (entry *) malloc(sizeof(entry));

    if (e) {
        e->pNext = table[key];
        strcpy(e->lastName, lastName);
        table[key] = e;
        return e;
    }

    return NULL;
}

int hash(char str[])
{
    int h = 0;

    while (*str) {
        h += *str++;
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
