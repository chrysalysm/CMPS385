//============================================================================
// Name        : Project3-3.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

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
	string sentence;
	cout << endl;
	cout << "Enter a sentence: ";
	getline(cin, sentence);
	cout << endl << "Your Input was: " << sentence;
	return 0;
}
