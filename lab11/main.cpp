/*
Wyatt Knickerbocker

main.cpp for hashtables

g++ hash.cpp main.cpp
*/

//system includes and namespace def
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#include "hash.h"

int main()
{
	string tempdict;
	char *dict;
	
	ifstream infile("dict4.txt");
	
	while(infile.good())
	{
		getline(infile, tempdict);
		
		Insert(tempdict.c_str());

	}
	infile.close();
	
	infile.open("dict8.txt");
	
	while(infile.good())
	{
		getline(infile, tempdict);
		
		Insert(tempdict.c_str());

	}
	infile.close();
	
	MinMaxVal();
	
	CheckHashTableValues();
	
	FindWords();
}