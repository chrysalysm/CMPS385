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
	char c[5] = {'o', 'c', 't', 'o', 'b', 'e', 'r'};



	return 0;
}
