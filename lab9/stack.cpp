#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<assert.h>

using namespace std;

#include "stack.h"

Stack::Stack()
{
	count = 0;
}

Stack::~Stack()
{
	while(!IsEmpty())
	{
		nodeptr tmp = topPtr;
		topPtr = topPtr->next;
		tmp->next = NULL;
		delete tmp;
	}
}

void Stack::Push(mathop m)
{
	nodeptr n;
	
	n = new node;
	n->info = m;
	n->next = NULL;
	
	count++;
	
	if(topPtr == NULL)
	{
		topPtr = n;
	}
	else
	{
		nodeptr temp = topPtr;
		n->next = temp;
		topPtr = n;
	}
}
   
mathop Stack::Pop()
{
	assert(count > 0);
	mathop m = topPtr->info;
	nodeptr tmp = topPtr;
	topPtr = topPtr->next;
	tmp->next = NULL;
	delete tmp;
	count--;
	return m;
}

bool Stack::IsEmpty()
{
	int n = count;
	
	return (n == 0);
}

mathop Stack::Peek()
{
	mathop m = topPtr->info;
	return m;
}

void Stack::Print()
{
	cout << "This should print the operator and precedence before a newline!!" << endl;
}