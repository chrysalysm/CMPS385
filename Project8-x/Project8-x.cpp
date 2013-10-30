//============================================================================
// Name        : Project8-x.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Program Segments for Project No.8
//============================================================================

#include <iostream>
#include <fstream>


using namespace std;

struct NODE {
	string name;
	NODE *left;
	NODE *right;
};

int main() {
	cout << endl;
	cout << endl;
	// Project8-4
	NODE *root, *p, *r;
	// Inserting root "Tom"
	r = new NODE;
	r -> name = "Tom";
	r -> left = NULL;
	r -> right = NULL;
	// Inserting "John"
	p = new NODE;
	p -> name = "John";
	p -> left = NULL;
	p -> right = NULL;
	r -> left = p;
	// Inserting "Bill"
	p = new NODE;
	p -> name = "Bill";
	p -> left = NULL;
	p -> right = NULL;
	r -> right = p;
	// Inserting "Anna"
	p = new NODE;
	p -> name = "Anna";
	p -> left = NULL;
	p -> right = NULL;
	r -> right -> left = p;

	// Project 8-9
	int a[5] = {3,6,9,2,1};
	cout << *a + 3 << "\n";
	cout << *(a+3) << "\n";
	cout << *(&a[3]) << "\n";

	return 0;

}
