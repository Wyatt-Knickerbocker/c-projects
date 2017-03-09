#include <iostream>

#include "link.h"
using namespace std;



LinkedList Union(LinkedList a, LinkedList b);

int main(){
	LinkedList L1;
	LinkedList L2;
	LinkedList L3;
	
	for(int i = 41; i < 46; i++)
	{
		L1.AddNode(i);
	}
	cout << "L1 = ";
	L1.PrintNodes();
	cout << endl;
	
	for(int i = 43; i < 48; i++)
	{
		L2.AddNode(i);
	}
	cout << "L2 = ";
	L2.PrintNodes();
	cout << endl;
	
	cout<< "Deleting last node from L2:" << endl;
	
	L2.DeleteLastNode();
	
	cout << "L2 = ";
	L2.PrintNodes();
	cout << endl;
	
	Union(L1, L2);
}

LinkedList Union(LinkedList a, LinkedList b)
{
	char ch;
	LinkedList Union = a;
	
	while(b.Size() != 0)
	{
		ch = b.PopNode();
		
		if(!Union.IsInList(ch))
		{
			Union.AddNode(ch);
		}

	}
	cout << "After Union = ";
	Union.PrintNodes();
	cout << endl;
	
	return Union;
}