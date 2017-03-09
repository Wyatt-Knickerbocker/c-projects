/*  link.cpp
 *
 *  Class for a sorted linked list of integers.
 */

#include <iostream>

using namespace std;

#include "link.h"


//  Add an item to the FRONT of the list
void LinkedList::AddNode( char x )
{
    nodeptr n;

        //  allocate new node
    n = new node;
    n->info = x;
    count++;

    if( start == NULL )
    {
        start = n;
        n->next = NULL;
    }
    else
    {
        nodeptr tmp = start;
        n->next = tmp;
        start = n;
    }
}

//\end{verbatim}  \lecpb  \begin{verbatim}

void LinkedList::DeleteFirstNode()
{
	nodeptr temp = start;
	
	if(start == NULL)
	{
		return;
	}
	if(start->next == NULL)
	{
		delete start;
		count--;
		return;
	}
	else
	{
		count--;
		start = start->next;
		temp->next = NULL;
		delete temp;
	}

}

char LinkedList::PopNode()
{
	if(count > 0)
	{
	char m = start->info;
	DeleteFirstNode();
	return m;
	}
}

//\end{verbatim}  \lecpb  \begin{verbatim}

void LinkedList::DeleteLastNode()
{
    nodeptr prev, curr;

    curr = start;
	prev = start;
	
	if(start == NULL)
		return;
	else
	{
		while(curr->next != NULL)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = NULL;
		
		delete curr;
	}
	count--;
}


void LinkedList::PrintNodes()
{
    nodeptr p = start;

	cout << "{ ";
	
    while( p != NULL )
    {
        cout << p->info << ' ';
        p = p->next;
    }

	cout << '}';
}

//\end{verbatim}  \lecpb  \begin{verbatim}

int LinkedList::IsInList(char x)
{
    nodeptr p = start;
    while( p->next != NULL && x != p->info )
		{
        p = p->next;
		}
    return(x == p->info);
}


int LinkedList::Size()
{
    return count;
}