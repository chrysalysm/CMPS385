//============================================================================
// Name        : Project2-2.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Project2-2 with Runtime
//============================================================================

#include <iostream>
#include <ctime>
using namespace std;

// Declaring user-defined functions
int sum(int, int);
int g(int);
int f(int);

int main() {
	cout << endl;
	int start, finish;
	cout << sum(3, 8) << endl;
	start = clock();
	cout << g(41) << endl;
	finish = clock();
	cout << "Runtime for g(n) is: " << (finish - start) / CLK_TCK << endl;
	cout << endl;
	return 0;
}

// Defining sum()
int sum(int n, int m) {
	if (n == m) return m;
	else return n + sum(n + 1, m);
}

// Defining g()
int g(int n) {
	if (n <= 3) return 2;
	else return n + g(n - 1) + g(n - 2);
}
