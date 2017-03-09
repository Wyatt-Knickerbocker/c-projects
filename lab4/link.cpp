/*  link.cpp
 *
 *  Class for a sorted linked list of integers.
 */

#include<iostream>

#include "link.h"

using namespace std;


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


void LinkedList::DeleteFirstNode()
{
	nodeptr temp = start;
	
	if(start == NULL)
	{
		cout << "Empty list.\n" << endl;
		return;
	}
	else
	{
		start = start->next;
		temp->next = NULL;
		delete temp;
	}
}


char LinkedList::DeleteLastNode()
{
	nodeptr prev, curr = start;
	
	if(start == NULL)
	{
		cout << "Empty list.\n" << endl;
		return;
	}
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
}


void LinkedList::PrintNodes()
{
    nodeptr p = start;
	cout << "CONTENTS: ";
    while( p != NULL )
    {
        cout << p->info << ' ';
        p = p->next;
    }
	cout << endl;
}


int LinkedList::IsInList(int x)
{
    nodeptr p = start;

    while( p != NULL && x > p->info )
        p = p->next;

    return (x == p->info);
}


int LinkedList::Size()
{
    return count;
}
