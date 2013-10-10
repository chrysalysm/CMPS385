//============================================================================
// Name        : Project5-1.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Linked Lists behaving like a Stack
//============================================================================

#include <iostream>
using namespace std;

struct NODE {
	int info;
	NODE *next;
};

int main() {
	int nodecount = 0, total = 0, a[5] = {3, 9, 8, 5, 7};
	NODE *stack, *p;

	// FILO - First In Last Out
	// New nodes are inserted at the front of the linked list
	stack = NULL;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		p = new NODE;
		p -> info = a[i];
		p -> next = stack;
		stack = p;
	}

	// Traversing the Linked List and outputting each node
	p = stack;
	while (p != NULL) {
		// Computing the total of all nodes
		total = total + p -> info;
		// Counting how many nodes are in the linked list
		nodecount++;
		cout << p -> info << " ==> ";
		p = p -> next;
	}

	// Output total of nodes and total # of nodes
	cout << "NULL\n";
	cout << "Total: " << total;
	cout << "\nTotal # of Nodes: " << nodecount;
	
	cout << endl;
	
	return 0;
}