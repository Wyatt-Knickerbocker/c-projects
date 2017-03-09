/*  stack.cpp
 *
 *  Definition of Stack class member functions.
 */

#include <iostream>
#include <assert.h>
#include "stack.h"

using namespace std;

Stack::Stack()
{
}


Stack::~Stack()
{
   //delete topPtr;
   while( !IsEmpty() ) {
       double  n = topPtr.FirstNode();
       topPtr.DeleteNode( n );
   }
}

//\end{verbatim}  \lecpb  \begin{verbatim}

void Stack::Push(double n)
{
   topPtr.AddNode( n );
}


double Stack::Pop()
{
   assert(!IsEmpty());

   double  n = topPtr.FirstNode();
   topPtr.DeleteNode( n );
   return n;
}

//\end{verbatim}  \lecpb  \begin{verbatim}

int Stack::IsEmpty()
{
    int n = topPtr.Size();
    return (n == 0);
}


void Stack::Print()
{
    topPtr.PrintNodes();
}

double Stack::Peek()
{
	return topPtr.FirstNode();
}
