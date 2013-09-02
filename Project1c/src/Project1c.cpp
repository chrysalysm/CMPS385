//============================================================================
// Name        : Project1c.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Project1c
//============================================================================

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main() {
	// Declaring array Days
	char Days[7][15] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Sat", "Sunday"};

	// Loop through the array and print each character
	for (int a = 0; a < 7; a++) {
		for (int b = 0; b < 15; b++) {
			cout << Days[a][b];
		}
		// Printing the length of each day
		cout << " - Length: " << strnlen(Days[a], sizeof(Days[a])) << endl;
	}
	cout << endl;

	// Replacing "Sat" with "Saturday"
	strncpy(Days[5], "Saturday", sizeof(Days[5]));

	// Only loop if string was copied over correctly
	if (strncmp(Days[5], "Saturday", 8) == 0) {
		// Loop through the array and print each character
		for (int c = 0; c < 7; c++) {
			for (int d = 0; d < 15; d++) {
				// Converting array Days to uppercase
				Days[c][d] = toupper(Days[c][d]);
				cout << Days[c][d];
			}
			cout << endl;
		}
	}
	return 0;
}
