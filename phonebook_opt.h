#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1

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

#define TABLE_SIZE 2017
//#define TABLE_SIZE 4013
//#define TABLE_SIZE 8191

entry *findName(char lastName[], entry *table[]);
entry *append(char lastName[], entry *table[]);
unsigned int hash(char str[], int mode);
void clear(entry *table[]);
entry *addData(entry *e);

#endif
