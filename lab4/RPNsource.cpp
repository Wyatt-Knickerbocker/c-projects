/* RPN calculator
 * Calculates things in Reverse Polish Notation
 * 
 * Wyatt Knickerbocker, CS 121-01
 */

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include "stack.h"

using namespace std;



int main() {

	double putNum, getNumX, getNumY, printme;
	string strInput;
	char * token, *splitString;
	
	Stack calcStack;

	cout << "RPN Calculator v 0.1 by Wyatt Knickerbocker" << endl;

	while(true) {
	
		if (calcStack.IsEmpty())
		{
			cout << "RPN (empty) > ";
		}
		else
		{
			cout << "RPN " << calcStack.Peek() << " > ";
		}
		
		getline (cin, strInput);
		
		splitString = new char[strInput.length()+1];
		
		strcpy(splitString, strInput.c_str()); 

		token = strtok(splitString, " ,");
		
		while(token != NULL)
		{
		
			if(strcmp (token, "quit") == 0)
			{
				cout << "QUIT TRUE. PROGRAM END." << endl;
				return 0;
			}
			else if((token[0] > 47 && token[0] < 58) || token[0] == 46)
			{
				putNum = atof(token);
				
				calcStack.Push(putNum);
			}
			
			else if(strcmp (token, "+") == 0)
			{
				getNumX = calcStack.Pop();
				getNumY = calcStack.Pop();
				putNum = (getNumX + getNumY);
				calcStack.Push(putNum);
				
			}
			
			else if(strcmp (token, "-") == 0)
			{
				getNumX = calcStack.Pop();
				getNumY = calcStack.Pop();
				putNum = (getNumY - getNumX);
				calcStack.Push(putNum);
			}
			
			else if(strcmp (token, "/") == 0)
			{
				getNumX = calcStack.Pop();
				getNumY = calcStack.Pop();
				putNum = (getNumY / getNumX);
				calcStack.Push(putNum);
			}
			
			else if(strcmp (token, "*") == 0)
			{
				getNumX = calcStack.Pop();
				getNumY = calcStack.Pop();
				putNum = (getNumX * getNumY);
				calcStack.Push(putNum);
			}
			
			else if(strcmp (token, "sq") == 0)
			{
				getNumX = calcStack.Pop();
				putNum = (getNumX * getNumX);
				calcStack.Push(putNum);
			}
			
			else if(strcmp (token, "sqrt") == 0)
			{
				getNumX = calcStack.Pop();
				putNum = sqrt(getNumX);
				calcStack.Push(putNum);
			}
			
			else if(strcmp (token, "swap") == 0)
			{
				getNumX = calcStack.Pop();
				getNumY = calcStack.Pop();
				calcStack.Push(getNumX);
				calcStack.Push(getNumY);
			}
			
			else if(strcmp (token, "ps") == 0)
			{
				calcStack.Print();
			}
			
			else if(strcmp (token, "dup") == 0)
			{
				putNum = calcStack.Peek();
				calcStack.Push(putNum);
			}
			token = strtok(NULL, " ,");
		}
		delete [] splitString;
	}
	return 0;
}
