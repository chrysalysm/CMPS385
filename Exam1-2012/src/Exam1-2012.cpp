//============================================================================
// Name        : Exam1-2012.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Exam 1 - Fall 2012 - Practice
//============================================================================

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

template <class T>

void Display(T x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

int main() {
	// 1 - i
	// Display array Class followed by the length of each
	char Class[4][15] = {"Freshman", "Sophomore", "Junior", "Senior"};
	for (int i = 0; i < 4; i++) {
		cout << Class[i] << " " << strlen(Class[i]) << endl;
	}

	// 1 - ii
	// Change the "a" in Freshman to letter "e"
	strcpy(&Class[0][6], "e"); // no known conversion from 'char' to 'char *' if I don't use &
	cout << Class[0][6] << endl;
	strcpy(Class[1], "Sofmore");
	cout << Class[1] << endl;
	// I have no idea why strcpy works well on 1d char array, but using 2d array I need &


	// 1 - iii
	// Display array Class in uppercase
	for (int i = 0; i < 4; i++) {
		for (int x = 0; x < 15; x++) {
			Class[i][x] = toupper(Class[i][x]);
			// strupr(Class[i]);  this doesn't work for my compiler
		}
		cout << Class[i] << endl;
	}

	// 2 - Write Display Function
	int a[5] = {3, 8, 1, 9, 2};
	string day[4] = {"Tuesday", "Wednesday", "Fri", "Mon"};
	char c[7] = {'o', 'c', 't', 'o', 'b', 'e', 'r'};
	/*
	 *	template <class T>
	 *	void Display(T x[], int n) {
	 *		for (int i = 0; i < n; i++) {
	 *			cout << x[i] << " ";
	 *		}
	 *	cout << endl;
	 *	}
	 */
	Display(a, 5);
	Display(day, 4);
	Display(c, 7);

	// 3 - Recursive definition to function
	/*
	int sum(int n, int m) {
		if (n == m) return m;
		else n + sum(n+1, m);
	}
	*/

	// 4 - Use <string> lib to display initial of country names with 1-3 words.
	cout << "\nEnter name of country: ";
	string name, i1, i2, i3;
	int n1, n2;
	getline(cin, name);
	i1 = name.substr(0, 1);
	n1 = name.find(' ');
	i2 = name.substr(n1 + 1, 1);
	n2 = name.find(' ', n1 + 1);
	i3 = name.substr(n2 + 1, 1);
	cout << i1 << " " << i2 << " " << i3 << endl;

	return 0;
}
