/* memerror.c -- try to find (and fix!) all the memory-related errors
                 in this program that

   Takes a string from the command line.  
   Makes a linked-list out of it in reverse order.  
   Traverse it to construct a string in reverse.  
   Clean up (release memory).
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct st_CharNode 
{
    char theChar;
    struct st_CharNode *next;
} CharNode;


void reverseIt( char *stringbuffer );


int main( int argv, char **argc )
{
    char *stringBuffer;

    //  Check number of user supplied arguments.  
    if( argv != 2 )
    {
        printf("usage: %%s string.  This reverses the string "
                 "given on the command line\n");
        exit( -1 );
    }

    // Copy the argument so we can make changes to it
    stringBuffer = malloc( strlen(argc[1]) );
	
    strcpy( stringBuffer, argc[1] );
	
    // Reverse the string
    reverseIt( stringBuffer );

    // Print the reversed string
    printf( "the reversed string is '%s'\n", stringBuffer );

    return 0;
}


// Build a linked list backwards, then traverse it.

void reverseIt( char *stringbuffer )
{
    CharNode *head, *node;
    char *scan, *stop;
    
    // initialize local vars
    head = node = NULL;

    // find the start and end of the string so we can walk it
    scan = stringbuffer;
    stop = stringbuffer + strlen(stringbuffer);

    // walk the string
    while (scan < stop)
    {
        if (head == NULL)
        {
            head = malloc( sizeof(CharNode*) );
            head->theChar = *scan;
            head->next = NULL;
        }
        else
        {
            node = malloc( sizeof(CharNode*) );
            node->theChar = *scan;
            node->next = head;
            head = node;
        }
        scan++;
    }

    // Re-point to the buffer so we can drop the characters
    scan = stringbuffer;

    //  Traverse the nodes and add them to the string
    while( head != NULL )
    {
        *scan = head->theChar;
        node = head->next;
        free( head );
        head = node;
        scan++;
    }

    // Release head
    free( head );   
}

