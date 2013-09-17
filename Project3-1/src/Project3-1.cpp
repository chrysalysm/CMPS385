//============================================================================
// Name        : Project3-1.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Converting Base10 to Base2, Base8 and Base16 with Stacks
//============================================================================

#include <iostream>
using namespace std;

// Creating Template for STACK class
template <class T, int n>

// Defining STACK class
class STACK {
private:
	T a[n];
	int counter;

public:
	void CreateStack() { counter = 0; }
	bool FullStack() { if (counter == n) return true; else return false; }
	bool EmptyStack() { if (counter == 0) return true; else return false; }
	void PushStack(int x) { a[counter] = x; counter++; }
	int PopStack() { counter--; return a[counter]; }
};

int main() {
	// Declaring STACK and variables
	STACK<int, 10> remainder;
	remainder.CreateStack();
	int input, basetwo, baseeight, basesixteen;
	cout << "Enter a positive integer number: ";
	cin >> input;
	basetwo = baseeight = basesixteen = input;

	// Base2 Calculation and Output
	cout << endl << input << " at base 2 is: ";
	while (basetwo != 0) {

		remainder.PushStack(basetwo % 2);
		basetwo = basetwo / 2;
	}
	while (!remainder.EmptyStack()) {
		cout << remainder.PopStack();
	}

	// Base8 Calculation and Output
	cout << endl << input << " at base 8 is: ";
	while (baseeight != 0) {

		remainder.PushStack(baseeight % 8);
		baseeight = baseeight / 8;
	}
	while (!remainder.EmptyStack()) {
		cout << remainder.PopStack();
	}

	// Base16 Calculation and Output
	cout << endl << input << " at base 16 is: ";
	while (basesixteen != 0) {

		remainder.PushStack(basesixteen % 16);
		basesixteen = basesixteen / 16;
	}
	while (!remainder.EmptyStack()) {
		basesixteen = remainder.PopStack();

		if (basesixteen == 10) {
			cout << "A";
		} else if (basesixteen == 11) {
			cout << "B";
		} else if (basesixteen == 12) {
			cout << "C";
		} else if (basesixteen == 13) {
			cout << "D";
		} else if (basesixteen == 14) {
			cout << "E";
		} else if (basesixteen == 15) {
			cout << "F";
		} else {
			cout << basesixteen;
		}
	}
	cout << endl;
	return 0;
}
