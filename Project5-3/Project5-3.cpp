//============================================================================
// Name        : Project5-3.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Linked Lists behaving like a Stack - Program Segment
//============================================================================

#include <iostream>
using namespace std;

struct NODE {
	int info;
	NODE *next;
};

int main() {

	int nodecount = 0, total = 0, odd = 0, average = 0,
	a[] = {1, 8, 3, 9, 8, 5, 7};
	NODE *stack, *p;

	stack = NULL;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		p = new NODE;
		p -> info = a[i];
		p -> next = stack;
		stack = p;
	}

	p = stack;
	while (p != NULL) {
		// Part iii
		// Finding the total to compute the average
		total = total + p -> info;

		// Part i
		// Determining how many nodes are in the new linked list
		nodecount++;

		// Part ii
		// Determining how many Odd numbers are in the linked list
		if (p -> info % 2 != 0) {
			odd++;
		}
		p = p -> next;
	}
	// Part iii - Computing the average of all numbers in LL
	average = total / nodecount;

	// Displaying results
	cout << "Number of Nodes in Linked List: " << nodecount;
	cout << "\nNumber of Odd numbers in Linked List: " << odd;
	cout << "\nAverage of all numbers in Linked list: " << average;
	cout << endl;

	return 0;
}
