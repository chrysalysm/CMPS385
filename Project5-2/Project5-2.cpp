//============================================================================
// Name        : Project5-2.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Linked Lists behaving like a Queue
//============================================================================

#include <iostream>
using namespace std;

struct NODE {
	int info;
	NODE *next;
};

int main() {
	int b[4] = {3, 9, 8, 1}, max = 0, min = 0;
	NODE *queue, *q, *p;

	// FIFO - First In First Out
	queue = new NODE;
	q = queue;
	// Filling the first Node with data
	q -> info = b[0];
	for (int i = 1; i < sizeof(b)/sizeof(b[0]); i++) {
		p = new NODE; // Creating a new Node and filling it with data
		p -> info = b[i];
		// New Node is placed at the rear of the queue, so next must be NULL
		p -> next = NULL;
		q -> next = p; // Inserting it at the rear of the queue
		q = p;
	}
	
	// Display the content of all Nodes
	p = queue;
	max = p -> info;
	while (p != NULL) {
		min = p -> info;
		cout << p -> info << " ==> ";
		p = p -> next;
		// Finding the Max and the Min
		if (min > max) {
			max = min;
		}
		else if (max < min) {
			min = max;
		}
	}
	cout << "NULL\n";
	// Outputting Max/Min
	cout << "Max data in the queue: " << max << endl;
	cout << "Min data in the queue: " << min << endl;
	
	return 0;
}