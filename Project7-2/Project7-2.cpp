//============================================================================
// Name        : Project7-2.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Queue Linked List - F(x) Calculation - Coef/Exponent
//============================================================================

#include <iostream>
#include <iomanip>
#include "QUEUE.h"

using namespace std;

int main() {
	// Defining Variables
	float coef_input = 1.0;
	int expo_input = 1;
	cout << endl;
	string cont;
	QUEUE F;
	F.CreateQueue();

	// Loop to get user input for coef and exponents
	while (true) {
		cout << "Enter the coefficient and power of a term (0,0 to stop): ";
		cin >> coef_input;
		cin >> expo_input;
		if (coef_input == 0.0 && expo_input == 0) {
			break;
		} else {
			F.Push(coef_input, expo_input);
		}
	}
	// Displaying the completed Function
	F.Display();
	
	// Obtaining user input for 'a' to compute F(a)
	cout << "To compute F(a), enter the 'a' value: ";
	cin >> coef_input;
	cout << "\tF(" << coef_input << ") = " << setprecision(4) << F.Compute(coef_input);		
	cout << endl;
	return 0;
}