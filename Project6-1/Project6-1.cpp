//============================================================================
// Name        : Project6-1.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Finding Palindrome with Linked Lists
//============================================================================

#include <iostream>
#include "STACK.h"
#include "QUEUE.h"

using namespace std;

int main() {
	// Declaration of variabless
	string sentence, cont;
	char charsent[50], c1, c2;
	// Creation of STACK and QUEUE
	STACK<char> S;
	QUEUE<char> Q;
	S.CreateStack();
	Q.CreateQueue();
	
	// While-loop for continue
	while(true) {
		cout << endl;
		cout << "Enter a sentence: ";
		getline(cin, sentence);
		strcpy(charsent, sentence.c_str());

		// Pushing user input into STACK and QUEUE
		for (int i = 0; i < sentence.size(); i++) {
			c1 = charsent[i];
			// Checking for alphanumeric
			if (isalnum(c1)) {
				S.Push(c1);
				Q.Push(c1);
			} else {
				// do nothing
			}
		}

		// STACK and QUEUE comparision
		while (!S.EmptyStack()) {
			c1 = S.Pop();
			c2 = Q.Pop();
			c1 = toupper(c1);
			c2 = toupper(c2);
			if (c1 != c2) {
				break;
			}
		}

		// If STACK and QUEUE was emptied with no break, Palindrome found
		if (S.EmptyStack() && Q.EmptyQueue()) {
			cout << "[" << sentence << "] is a Palindrome!" << endl;
		} else {
			cout << "[" << sentence << "] is NOT Palindrome." << endl;
		}

		// While-loop continue check
		cout << endl << "CONTINUE (y/n)? ";
		cin >> cont;
		if (cont != "y") {
			break;
		} else {
			// Clearing the STACK and QUEUE for new user input
			while(!S.EmptyStack() || !Q.EmptyQueue()) {
				S.Pop();
				Q.Pop();
			}
		}
		cin.ignore();
	}
	return 0;
}