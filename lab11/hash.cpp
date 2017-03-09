/* Hash.cpp
 *
 *  Hash table implementation from:
 *  Kernighan & Ritchie, The C Programming Language,
 *     Second Edition, Prentice-Hall, 1988.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "hash.h"


const int HASH_TABLE_SIZE = 50023;
static NListPtr hashTable[HASH_TABLE_SIZE];

    //  Prototypes
static char *Strdup( const char * );  //  in cstring, but....



/*  Hash
 *  Generate hash value for string s
 */

unsigned Hash(const char *s )
{
    unsigned hashVal;
    
    for( hashVal = 0 ; *s != '\0' ; s++ )
        hashVal = *s + 31 * hashVal;
        
    return  hashVal % HASH_TABLE_SIZE;
}


/*  Lookup
 *  Look for s in hashTable
 */

NListPtr Lookup(const char *s )
{
    NListPtr np;

    for( np = hashTable[Hash(s)] ; np != NULL ; np = np->next )
    {
        if( strcmp(s, np->name) == 0 )
            return np;    //  found
    }
    
    return NULL;          //  not found
}

/*  Insert
 *  Put (name, defn) in hash table
 */
 
NListPtr Insert(const char *name)
{
    unsigned hashVal;
    NListPtr np;
    
    if( (np = Lookup(name)) == NULL )  // not found
    {
        np = (NListPtr) malloc(sizeof(*np));
        if( np == NULL || (np->name = Strdup(name)) == NULL )
            return NULL;
        hashVal = Hash(name);
        np->next = hashTable[hashVal];
        hashTable[hashVal] = np;
    }
    else
    {      //  remove previous definition
        free( (void *)np->name );
    }
}


/*  PrintHashTable
 *  Print the hash table contents
 */

void PrintHashTable()
{
    NListPtr np;

    cout << "Hash table contents:" << endl;
    cout << "--------------------\n" << endl;

    for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ )
    {
        np = hashTable[i];
		if(np != NULL)
			cout << setw(4) << i << ":    ";
        while( np != NULL )
        {
             cout << np->name << ", ";
             np = np->next;
        }
		cout << endl;
    }
}

void FindWords()
{
	NListPtr np;
	string lookfor[256];
	unsigned count = 0;
	char * pch, *parse;
	string unparsed;
	
	cin.ignore();
	cout << "Enter up to 10 words to search for: ";
	getline(cin, unparsed);
	strcpy(parse, unparsed.c_str());
		
	pch = strtok(parse, " \n");
	while (pch != NULL)
	{
		lookfor[count] = pch;
		count++;
		pch = strtok (NULL, " ");
	}
	lookfor[count+1] = "stop";
	cout << count << endl;
	for(int i = 0; i < (count); i++)
	{
		cout << lookfor[i] << endl;
		
		np = Lookup(lookfor[i].c_str());
		if(np != NULL)
			cout << np->name << " found." << endl;
	}
	cout << "Here?";
	return;
}

void MinMaxVal()
{
    NListPtr np;
	int max = 0, min = 0, count = 0, maxi = 0, mini = 0;

    for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ )
    {
        np = hashTable[i];
        while( np != NULL )
        {
            count++;
            np = np->next;
        }
		if(i == 0)
		{
			max = count;
			min = count;
		}
		else
		{
			if(max < count)
			{
				max = count;
				maxi = i;
			}
			if(min > count)
			{
				min = count;
				mini = i;
			}
		}
		count = 0;
    }
	cout << "MIN AT "<< mini <<": " << min << endl << "MAX AT " << maxi << ": " << max <<endl;
}

void CheckHashTableValues()
{
    NListPtr np;
	int num_bucket = 0, checknum;
	while(true)
	{
		cout <<"Enter a value up to " << HASH_TABLE_SIZE << " to check contents\nOr enter -1 to exit: ";
		cin >> checknum;
		
		if(checknum == -1)
			return;
		else
		{
			np = hashTable[checknum];
			cout << setw(4) << checknum << ":    ";
			while( np != NULL )
			{
				num_bucket++;
				 np = np->next;
			}
			cout << num_bucket << endl;
		}
	}
}

/*  Strdup
 *  Make a duplicate copy of s
 */

static char *Strdup( const char *s )
{
    char *p;
    
    p = (char *) malloc(strlen(s)+1);  /*  +1 for '\0'  */
    if( p != NULL )
        strcpy(p,s);

    return p;
}
