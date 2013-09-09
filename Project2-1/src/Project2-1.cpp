//============================================================================
// Name        : Project2-1.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Project2-1 - <algorithm> sort()
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

// Template class to handle Display function without overloading
template <class T>

void Display(T x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

int main() {

	// Declaring variables
	int a[5] = {3, 8, 1, 9, 2};
	string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	char c[9] = {'s', 'e', 'p', 't', 'e', 'm', 'b', 'e', 'r'};

	cout << endl << "Array a[] before being sorted: ";
	Display(a, 5);  // sizeof(a)/sizeof(a[0])
	// Sorting Array a[]
	sort(a, a + 5);
	cout << "Array a[] after being sorted: ";
	Display(a, 5);

	cout << "Array day[] before being sorted: ";
	Display(day, 7);  // sizeof(day)/sizeof(day[0])
	// Sorting Array day[]
	sort(day, day + 7);
	cout << "Array day[] after being sorted: ";
	Display(day, 7);

	cout << "Array c[] before being sorted: ";
	Display(c, 9);  // sizeof(c)/sizeof(c[0])
	// Sorting Array c[]
	sort(c, c + 9);
	cout << "Array c[] after being sorted: ";
	Display(c, 9);

	cout << endl;
	return 0;
}
