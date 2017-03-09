/* stack.h
 *
 * Definition of Stack class
 */
 
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>

using namespace std;

struct mathop
{
	char op;
	int precedence;
};

class Stack {
public:
   Stack();
   ~Stack();

   void Push(mathop m);     // push item onto stack
   mathop Pop();            // remove item from stack
   
   bool IsEmpty();       // is the stack empty?
   mathop Peek();			// check the top of the stack
   void Print();        // print the stack

private:
  struct node
  {
     mathop info;
     node * next;
  };
  
  typedef node * nodeptr;
  
  nodeptr topPtr;
  
  int count;
  
};


#endif
