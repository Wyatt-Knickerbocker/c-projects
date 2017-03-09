/*  hash.h
 */

#ifndef HASH_H
#define HASH_H

struct nList     /*  table entry:  */
{
   char *name;          /*  defined name         */
   struct nList *next;  /*  next entry in chain  */
};

typedef struct nList *NListPtr;

unsigned Hash(const char *s );
NListPtr Lookup(const char *s );
NListPtr Insert(const char *name);

void FindWords();
void MinMaxVal();
void CheckHashTableValues();

void PrintHashTable();


#endif  /*  HASH_H  */