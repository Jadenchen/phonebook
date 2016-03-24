#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "phonebook_opt1.h"

#define HASH_SIZE 5381
entry* HASH_TABLE[HASH_SIZE];

//some kind of hash function
int  Hash (char *str)
{
    unsigned long hash = 5381;
    while (*str++)
        hash = ((hash << 5) + hash) + (int) *str++; // hash *33 + c
    return(int) (hash % HASH_SIZE);
}


/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry* findName(char lastname[], entry *pHead)
{
    entry *val = HASH_TABLE[Hash(lastname)];
    while (val != NULL) {
        if (strcasecmp(lastname, val->lastName) == 0) {
            printf ("find name \n");
            return val;
        }
        val = val->pNext;
    }

    return NULL;
}

entry *append(char lastName[], entry *e)
{

    int key = Hash(lastName);
    e->pNext = (entry *) malloc (sizeof (entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    if (HASH_TABLE[key] == NULL)
        HASH_TABLE[key] = e;
    else { //means collision
        HASH_TABLE[key]->pNext = e;
    }
    e->pNext = NULL;

    return e;
}
