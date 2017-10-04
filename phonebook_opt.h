#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1

#include <stdlib.h>

typedef struct {
    char firstName[16];
    char email[16];
    char addr1[16];
    char addr2[16];
    char city[16];
    char phone[10];
    char state[2];
    char cell[10];
    char zip[5];
} Data;

typedef struct __PHONE_BOOK_ENTRY {
    Data *data;
    struct __PHONE_BOOK_ENTRY *pNext;
    char lastName[MAX_LAST_NAME_SIZE];
} entry;

typedef struct {
    void *ptr;
    size_t size;
    size_t cnt;
} MemPool;

#define TABLE_SIZE 2017
//#define TABLE_SIZE 4013
//#define TABLE_SIZE 8191

entry *findName(char lastName[], entry *table[]);
entry *append(char lastName[], entry *table[], MemPool *pool);
unsigned int hash(char str[], int mode);
void clear(entry *table[], MemPool *pool);
entry *addData(entry *e);
void *poolloc(size_t size, MemPool *pool);
MemPool *memPool(size_t size);

#endif
