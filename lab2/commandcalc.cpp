//Wyatt Knickerbocker
// CS 120-01
//Lab assignment 2, ARG MANIPULATION

#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cmath>

using namespace std;

float add(float, float);
float sub(float, float);
float mult(float, float);
float div(float, float);

int main( int argc, char *argv[] ) {
	float f1, f2;
	
	if (argc < 4) {
		cout << "NOT ENOUGH ARGS. ABORTING PROGRAM." << endl; //Takes no less than 3
		return 0;											  //arguments after program name
	}
	
	if ((argv[1][0] < 48) || (argv[1][0] > 57)) {	//Checks if the first character is NOT a number.
			cout <<"INVALID FIRST NUMBER. ABORTING PROGRAM." << endl;			//Then ends program if is.
			
			return 0;
	}
	else
		f1 = atof(argv[1]);
		
		if ((argv[3][0] < 48) || (argv[3][0] > 57)) { //Checks if the first character is NOT a number.
			cout <<"INVALID SECOND NUMBER. ABORTING PROGRAM." << endl;
			
			return 0;
	}
	else
		f2 = atof(argv[3]);
	
	switch(argv[2][0]) {
		case '+':
			cout << f1 << " + " << f2 << " = " << add(f1, f2) << endl;
			break;
		case '-':
			cout << f1 << " - " << f2 << " = " << sub(f1, f2) << endl;
			break;
		case '/':
			cout << f1 << " / " << f2 << " = " << div(f1, f2) << endl;
			break;
		case '\\':
			cout << f1 << " \\ " << f2 << " = " << div(f1, f2) << endl;
			break;
		case 'x':
			cout << f1 << " x " << f2 << " = " << mult(f1, f2) << endl;
			break;
		default:
			cout << "INVALID OPERATOR. ABORTING PROGRAM." << endl;
			return 0;
	}
	cout << "END OF PROGRAM" << endl;
	
	return 0;
}

float add(float x, float y) {
	return (x + y);
}
float sub(float x, float y) {
	return (x - y);
}
float mult(float x, float y) {
	return (x * y);
}
float div(float x, float y) {
	return ( x / y);
}