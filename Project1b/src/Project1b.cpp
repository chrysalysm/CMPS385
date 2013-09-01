//============================================================================
// Name        : Project1b.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Project 1b
//============================================================================

// time.h is necessary for random number generation
#include <iostream>
#include <time.h>

using namespace std;

int main() {

	// Declaring array and initializing random seed
	int a[15];
	srand(time(NULL));

	// Loop through array and assign random number between 20 and 40 inclusive
	for (int i = 0; i < 15; i++) {
		a[i] = rand() % 21 + 20;
	}

	// Loop through array to find even integers and then output
	cout << "EVEN integers in array a: ";
	for (int i = 0; i < 15; i++) {
		if (a[i] % 2 == 0) {
			cout << a[i] << " ";
		}
	}

	// Loop through array to find odd integers and then output
	cout << endl << "ODD integers in array a: ";
	for (int i = 0; i < 15; i++) {
		if (a[i] % 2 != 0) {
			cout << a[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
