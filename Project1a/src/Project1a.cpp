//============================================================================
// Name        : Project1a.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Project 1a
//============================================================================

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// Declaring isVowel() User-Defined Function
bool isVowel(char);

int main() {
	// Declaring Variables
	string sentence;
	unsigned int i, upperCase = 0, lowerCase = 0, digits = 0, vowels = 0;
	char a;

	// Getting user-input
	cout << "Enter a sentence: " << endl;
	getline(cin, sentence);

	// Loop through sentence and check lowercase, uppercase, digit and vowel
	// if true, iterate counter
	for (i = 0; i < sentence.length(); i++) {
		a = sentence[i];

		if (islower(a)) {
			lowerCase++;
		} else if (isupper(a)) {
			upperCase++;
		} else if (isdigit(a)) {
			digits++;
		}

		if (isVowel(a)) {
			vowels++;
		}
	}

	// Output
	cout << setfill('.');
	cout << left << setw(25) << "No. of Uppercase" << right << setw(2) << upperCase << endl;
	cout << left << setw(25) << "No. of Lowercase" << right << setw(2) << lowerCase << endl;
	cout << left << setw(25) << "No. of Digits" << right << setw(2) << digits << endl;
	cout << left << setw(25) << "No. of Vowels" << right << setw(2) << vowels << endl;

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
