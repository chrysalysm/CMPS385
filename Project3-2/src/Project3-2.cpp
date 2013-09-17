//============================================================================
// Name        : Project3-2.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Sorting EVEN and ODD integers with STACKS
//============================================================================

#include <iostream>
#include <time.h>
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
	// Declaring variables and STACKS
	srand(time(NULL));
	STACK<int, 10> S, EVEN, ODD, T;
	int number;

	// Creating Stacks
	S.CreateStack();
	T.CreateStack();
	EVEN.CreateStack();
	ODD.CreateStack();

	// Loop to fill STACK S with random integers < 100
	for (int i = 0; i < 10; i++) {
		S.PushStack(rand() % 100);
	}

	// Output All numbers and sort EVEN and ODD numbers to respective STACKS
	cout << endl << "All numbers: ";
	while (!S.EmptyStack()) {
		number = S.PopStack();
		if (number % 2 == 0) {
			EVEN.PushStack(number);
		} else {
			ODD.PushStack(number);
		}
		cout << number << " ";
	}

	// Output all EVEN numbers within STACK EVEN
	cout << endl << "EVEN numbers: ";
	while (!EVEN.EmptyStack()) {
		T.PushStack(EVEN.PopStack());
	}
	// Flip STACK with Temp STACK
	while (!T.EmptyStack()) {
		cout << T.PopStack() << " ";
	}

	// Output all ODD numbers within STACK ODD
	cout << endl << "ODD numbers: ";
	while (!ODD.EmptyStack()) {
		T.PushStack(ODD.PopStack());
	}
	// Flip STACK with Temp STACK
	while (!T.EmptyStack()) {
		cout << T.PopStack() << " ";
	}

	cout << endl;
	return 0;
}
