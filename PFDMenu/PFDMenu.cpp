//============================================================================
// Name        : PFDMenu.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Perfect Fibonacci Distribution w/ Polyphase Merging
//============================================================================

#include <iostream>

using namespace std;

// structure NODE declaration for Linked Lists
struct NODE {
	int info;
	NODE *next;
};

// Function declaration for Displaying Polyphase Merging of Order 3
// Requires the initial Perfect Fibonacci Distribution and padded fileSize
void DisplayOrderThree(int a, int b, int c, int d, int fileSizeDistro) {
	// First Line Output
	cout << "\n" << fileSizeDistro << "\t--\t--\t--\n";
	// Node creation
	NODE *f1, *t1, *t2, *t3;
	f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE;
	// Filling Nodes with info and creating the linked list
	f1 -> info = a; t1 -> info = b; t2 -> info = c;	t3 -> info = d;
	f1 -> next = t1; t1 -> next = t2; t2 -> next = t3; t3 -> next = NULL;
	NODE *p, *q, *r;
	int min = fileSizeDistro;
	// Loop until Polyphase Merging is complete, sum of all Nodes = 1
	while ((f1 -> info + t1 -> info + t2 -> info + t3 -> info) > 1) {
		// Finding the Minimum node after each merge
		p = f1;
		while (p != NULL) {
			if (min > p -> info && p -> info != 0) {
				min = p -> info;
			}					
			p = p -> next;
		}
		// Output of current distribution
		q = f1;
		while (q != NULL) {
			if (q -> info == 0) {
				cout << "--\t";
				q = q -> next;
			} else {
				cout << q -> info << "\t";
				q = q -> next;
			}
		}
		cout << "\n";
		// Subtracting the min from each node of the linked list
		// Node that results in negative value is the empty node
		r = f1;
		while (r != NULL) {
			r -> info -= min;
			if (r -> info < 0) {
				r -> info = min;
			}
			r = r -> next;
		}
	}
	// Final last line output when the sum of all nodes = 1
	q = f1;
	while (q != NULL) {
		if (q -> info == 0) {
			cout << "--\t";
			q = q -> next;
		} else {
			cout << q -> info << "\t";
			q = q -> next;
		}
	}
}

// Function declaration for Displaying Polyphase Merging of Order 4
// Requires the initial Perfect Fibonacci Distribution and padded fileSize
void DisplayOrderFour(int a, int b, int c, int d, int e, int fileSizeDistro) {
	cout << "\n" << fileSizeDistro << "\t--\t--\t--\t--\n";
	NODE *f1, *t1, *t2, *t3, *t4;
	f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE; t4 = new NODE;
	f1 -> info = a; t1 -> info = b; t2 -> info = c;	t3 -> info = d; t4 -> info = e;
	f1 -> next = t1; t1 -> next = t2; t2 -> next = t3; t3 -> next = t4; t4 -> next = NULL;
	NODE *p, *q, *r;
	int min = fileSizeDistro;
	while ((f1 -> info + t1 -> info + t2 -> info + t3 -> info + t4 -> info) > 1) {
		p = f1;
		while (p != NULL) {
			if (min > p -> info && p -> info != 0) {
				min = p -> info;
			}					
			p = p -> next;
		}
		q = f1;
		while (q != NULL) {
			if (q -> info == 0) {
				cout << "--\t";
				q = q -> next;
			} else {
				cout << q -> info << "\t";
				q = q -> next;
			}
		}
		cout << "\n";
		r = f1;
		while (r != NULL) {
			r -> info -= min;
			if (r -> info < 0) {
				r -> info = min;
			}
			r = r -> next;
		}
	}
	q = f1;
	while (q != NULL) {
		if (q -> info == 0) {
			cout << "--\t";
			q = q -> next;
		} else {
			cout << q -> info << "\t";
			q = q -> next;
		}
	}
}

int main() {
	cout << endl;
	// Declaring variables to be used
	int fileSize, fileSizeDistro;
	char choice, cont;
	// Setting the accepted filesizes for Order 3 and Order 4
	int fileSizeArrayOrderThree[7] = {1, 3, 5, 9, 17, 31, 57};
	int fileSizeArrayOrderFour[7] = {1, 4, 7, 13, 25, 49, 94};

	while (true) {
		cout << endl;
		// Getting user input
		cout << "=========PFD Menu=========\n";
		cout << "a. PFD of order 3\n";
		cout << "b. PFD of order 4\n";
		cout << "   Enter a file size (< 55): ";
		cin >> fileSize;
		cout << "   Enter your choice (a/b): ";
		cin >> choice;
		cout << endl;

		// Order 3 - Distribution and Output
		if (choice == 'a' && fileSize < 57) {
			cout << "F1\tT1\tT2\tT3\n";
			cout << "==========================";
			// Rounding the user input up to match the proper filesize
			// for Perfect Fibonacci Distribution
			for (int i = 0; i < 7; i++) {
				if (fileSize > fileSizeArrayOrderThree[i]) {
					fileSizeDistro = fileSizeArrayOrderThree[i+1];
				} else if (fileSize == fileSizeArrayOrderThree[i]) {
					fileSizeDistro = fileSizeArrayOrderThree[i];
				} else {
					break;
				}
			}
			// Passing Perfect Fibonacci Distribution to Display function
			// for final output
			switch (fileSizeDistro) {
				case 1:
					DisplayOrderThree(0, 1, 0, 0, fileSizeDistro);
					break;
				case 3:
					DisplayOrderThree(0, 1, 1, 1, fileSizeDistro);			
					break;
				case 5:
					DisplayOrderThree(0, 2, 2, 1, fileSizeDistro);
					break;
				case 9:
					DisplayOrderThree(0, 4, 3, 2, fileSizeDistro);
					break;
				case 17:
					DisplayOrderThree(0, 7, 6, 4, fileSizeDistro);
					break;
				case 31:
					DisplayOrderThree(0, 13, 11, 7, fileSizeDistro);
					break;
				case 57:
					DisplayOrderThree(0, 24, 20, 13, fileSizeDistro);
					break;
				default:
					break;
			}

		// Order 4 - Distribution and Output
		} else if (choice == 'b' && fileSize < 94) {
			cout << "F1\tT1\tT2\tT3\tT4\n";
			cout << "==================================";
			for (int i = 0; i < 7; i++) {
				if (fileSize > fileSizeArrayOrderFour[i]) {
					fileSizeDistro = fileSizeArrayOrderFour[i+1];
				} else if (fileSize == fileSizeArrayOrderFour[i]) {
					fileSizeDistro = fileSizeArrayOrderFour[i];
				} else {
					break;
				}
			}

			switch (fileSizeDistro) {
				case 1:
					DisplayOrderFour(0, 1, 0, 0, 0, fileSizeDistro);
					break;
				case 4:
					DisplayOrderFour(0, 1, 1, 1, 1, fileSizeDistro);			
					break;
				case 7:
					DisplayOrderFour(0, 2, 2, 2, 1, fileSizeDistro);
					break;
				case 13:
					DisplayOrderFour(0, 4, 4, 3, 2, fileSizeDistro);
					break;
				case 25:
					DisplayOrderFour(0, 8, 7, 6, 4, fileSizeDistro);
					break;
				case 49:
					DisplayOrderFour(0, 15, 14, 12, 8, fileSizeDistro);
					break;
				case 94:
					DisplayOrderFour(0, 29, 27, 23, 15, fileSizeDistro);
					break;
				default:
					break;
			}
		// If user entered an invalid choice, program stops
		} else {
			cout << "\nThat is an invalid choice and/or filesize.\n";
			break;
		}
		// Looping program to continue based on user input
		cout << endl;
		cin.ignore();
		cout << "\nContinue (y/n)?: ";
		cin >> cont;
		if (cont == 'y') {
			// do nothing
		} else {
			break;
		}
	}
	cout << endl;
	return 0;
}