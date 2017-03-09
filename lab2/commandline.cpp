//Wyatt Knickerbocker
// CS 120-01
//Lab assignment 2, ARG MANIPULATION

#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int main( int argc, char *argv[] ) {
	int n;
	float f;
	
	if (argc < 4) {
		cout << "NOT ENOUGH ARGS. ABORTING PROGRAM." << endl; //Takes no less than 3
		return 0;											  //arguments after program name
	}
	cout << "CHECKING AGAINST: " << argv[1][0] << endl;
	if ((argv[1][0] < 48) || (argv[1][0] > 57)) { //Checks if the first character is NOT a number.
			cout <<"INTEGER ERROR";
	}	
	else {		//If it is, then convert, print
		n = atoi(argv[1]);
		cout <<"INTEGER: " << n;
	}
		if ((argv[3][0] < 48) || (argv[3][0] > 57)) { //Checks if the first character is NOT a number.
			cout <<" | FLOAT ERROR" << endl;
	}	
	else {		//If it is, then convert, print.
		f = atof(argv[3]);
		cout <<" | FLOAT: " << f << endl;
	}
	
	cout << "END OF PROGRAM" << endl;
	
	return 0;
}