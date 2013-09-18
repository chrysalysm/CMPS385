//============================================================================
// Name        : Project3-3.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Using STACKS to sort Upper/Lower/Vowel
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
	void PushStack(char x) { a[counter] = x; counter++; }
	char PopStack() { counter--; return a[counter]; }
};

// User-defined Function
bool isVowel(char);

int main() {
	// Declaring Variables
	string sentence;
	char charsentence[100], character;
	STACK<int, 100> T, UPPER, LOWER, VOWEL;

	// Creating STACKS
	T.CreateStack();
	UPPER.CreateStack();
	LOWER.CreateStack();
	VOWEL.CreateStack();

	cout << endl;
	cout << "Enter a sentence: ";
	getline(cin, sentence);
	strcpy(charsentence, sentence.c_str());

	// Pushing User Input to STACK
	for (int i = 0; i < (signed int)sentence.size(); i++) {
		T.PushStack(charsentence[i]);
	}

	// Using Temp STACK to flip and sort upper/lower/vowel
	while (!T.EmptyStack()) {
		character = T.PopStack();
		if (isupper(character)) {
			UPPER.PushStack(character);
		} else if (islower(character)) {
			LOWER.PushStack(character);
		}
		if (isVowel(character)) {
			VOWEL.PushStack(character);
		}
	}

	// Displaying Uppercase Letters
	cout << "Uppercase Letters: ";
	while (!UPPER.EmptyStack()) {
		cout << UPPER.PopStack() << " ";
	}

	// Displaying Lowercase Letters
	cout << endl << "Lowercase Letters: ";
	while (!LOWER.EmptyStack()) {
		cout << LOWER.PopStack() << " ";
	}

	// Displaying Vowels
	cout << endl << "Vowels: ";
	while (!VOWEL.EmptyStack()) {
		cout << VOWEL.PopStack() << " ";
	}
	cout << endl;
	return 0;
}

// Defining isVowel() function
bool isVowel(char b) {
	// Convert to uppercase to limit || statements
	b = toupper(b);
	if ((b == 'A') || (b == 'E') || (b == 'I') || (b == 'O') || (b == 'U')) {
		return true;
	} else {
		return false;
	}
}
