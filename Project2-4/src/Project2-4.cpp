//============================================================================
// Name        : Project2-4.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Project 2-4 with <string>
//============================================================================

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int main() {
	// Declaring Variables
	int i = 1, n, m, length;
	string name, cont, initial1, initial2, initial3;
	// While loop for continue
	while (i == 1) {
		cout << endl << "Enter a name: ";
		getline(cin, name);
		length = name.length();

		// Finding initials
		initial1 = name.substr(0, 1);
		n = name.find(' ');
		initial2 = name.substr(n + 1, 1);
		m = name.find(' ', n + 1);
		initial3 = name.substr(m + 1, 1);
		// Outputting initials
		if (n == -1) { cout << "The initial of " << name << " is " << initial1 << endl; }
		else if (m == -1) { cout << "The initial of " << name << " is " << initial1 << " " << initial2 << endl; }
		else cout << "The initial of " << name << " is " << initial1 << " " << initial2 << " " << initial3 << endl;

		// Continue?
		cout << endl << "CONTINUE (y/n) ?";
		cin >> cont;
		cin.ignore();
		if (cont == "y") i = 1;
		else i = 0;
	}
	return 0;
}
