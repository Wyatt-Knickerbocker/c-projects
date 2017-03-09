/* Wyatt Knickerbocker		CS121-01

  1-D Cellular Automata	   2/16/14*/
 
 #include<iostream>
 #include<cstdlib>
 #include<ctime>
 
 using namespace std;
 
void printGen(bool [], int len);
void iterate(bool now[], bool next[], int len);
void flip(bool next[], int position);
 
int main() {
	
	int length, cont;
	
	cout << "How many? " << endl;
	cin >> length;
	cout << "LENGTH: " << length << endl;
	
	bool* currentgen = new bool[length];
	bool* nextgen = new bool[length];
	
	for(int i = 0; i < length; i++) {
		currentgen[i] = (rand()%2);
	}
	
	printGen(currentgen, length);
	
	while(cont != 0) {
	iterate(currentgen, nextgen, length);
	
	printGen(currentgen, length);
	
	cin.ignore();
	}
	
	delete [] currentgen;
	return 0;
}

void printGen(bool gen[], int len) {

		cout << '|';
	for(int i = 0; i < len; i++) {
		cout << gen[i] << '|';
	}
	cout << endl;
	
	return;

}

void iterate(bool now[], bool next[],int len){

	int ahead, last, check;

	for(int i = 0; i < len; i++){
	
		ahead = i+1;
		last = i-1;
	
		if (now[i] == 1) {
		
			next[i] == 0;

			if (now[ahead] == 0) {
				next[ahead] = 1;
			}
			if (now[last] == 0) {
				flip(next, last);
			}
		}
	}
	for(int i = 0; i < len; i++) {
	
	now[i] = next[i];
	next[i] = 0;
	}
}

void flip(bool next[], int position) {

	if( next[position] == 1) {
		next[position] = 0;
	}
	else next[position] = 1;

}