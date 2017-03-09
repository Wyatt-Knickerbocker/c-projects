/* stack.h
 *
 * Definition of Stack class
 */
 
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>
#include "link.h"


class Stack {
public:
   Stack();
   ~Stack();

   void Push(double n);     // push item onto stack
   double Pop();            // remove item from stack
   int IsEmpty();        // is the stack empty?
   void Print();         // print the stack
   double Peek();		//Checks top item

private:
   LinkedList topPtr;    // pointer to list
};


#endif
