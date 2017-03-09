/*  link.h
 */

// This is a class for a linked list of integers.

#ifndef LINK_H
#define LINK_H

//#include <bool.h>   //  Not on all compilers
#include <iostream>

using namespace std;


class LinkedList
{
private:

  struct node
  {
     char info;
     node * next;
  };

  typedef node * nodeptr;

  nodeptr start;

  int count;

//\end{verbatim}  \lecpb  \begin{verbatim}

public:

       // Constructor

   LinkedList()
   {
      start = NULL;
      count = 0;
   }

       // Destructor

   ~LinkedList()
   {
      nodeptr p = start, n;
 
      while (p != NULL)
      {
         n = p;
         p = p->next;
         delete n;
      }
   }
 
    // Add a node onto the front of the linked list.

   void AddNode(char x);

    // Delete the first node found with the value x, if one exists.

   void DeleteFirstNode();
   
   char PopNode();
   
    // Return the first node found in the list
    
   void DeleteLastNode();

    // Output the values in the nodes, one integer per line. 

   void PrintNodes();

    // Return true if there in a node in the list with the value x.

   int IsInList(char x);

    // Return a count of the number of nodes in the list.
 
   int Size();
};

#endif

