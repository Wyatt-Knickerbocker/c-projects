
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>

using namespace std;

#include"stack.h"

void printop(mathop m);

int main()
{
	Stack mathstack;
	mathop add, print;
	add.op = '+';
	add.precedence = 1;

	cout <<"PUSHING ONTO STACK:\n" << endl;
	for(int i = 0; i < 5; i++)
	{
		mathstack.Push(add);
		print = add;
		printop(print);
		add.op++;
		add.precedence++;
	}
	cout <<"POPPING FROM STACK:\n" << endl;
	while(!mathstack.IsEmpty())
	{
		print = mathstack.Pop();
		printop(print);
	}
	return 0;
}

void printop(mathop m)
{
	cout <<"OPERATOR: " << m.op << " | PRECEDENCE: " << m.precedence << endl;
}