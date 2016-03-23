#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "phonebook_opt1.h"

#define HASH_SIZE 0x7FFFF
entry* HASH_TABLE[HASH_SIZE];

//some kind of hash function 
unsigned int Hash (char *str){

        unsigned int seed = 131;
        unsigned int hash = 0;

        while (*str)
                hash = hash + seed + (*str++);

        return (hash & 0x7FFFFFFF);

}


/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
	entry * e = HASH_TABLE[Hash(lastname)];
		
    while (e != NULL) {
        if (strcasecmp(lastname, e->lastName) == 0)
            return e;
        e = e->pNext;
    }
    return NULL;

}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
	e->other = NULL;
	int key = Hash(lastName);
	
	if (HASH_TABLE[key] != NULL ){
		//e->pNext = HASH_TABLE[key];
		//HASH_TABLE[key] = e;				

	}else {
		HASH_TABLE[key] = e;	
	}	

    return e;
}

