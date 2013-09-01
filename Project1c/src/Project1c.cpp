//============================================================================
// Name        : Project1c.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char Days[7][15] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Sat", "Sunday"};

	for (int a = 0; a < 7; a++) {
		for (int b = 0; b < 15; b++) {
			cout << Days[a][b];
		}
		cout << " ";
	}
	cout << endl;
	return 0;
}
