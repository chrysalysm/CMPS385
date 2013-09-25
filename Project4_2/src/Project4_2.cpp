//============================================================================
// Name        : Project4_2.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Finding Palindrome with STACKS
//============================================================================

#include <iostream>
#include "STACK.h"
using namespace std;

int main() {
	// Declaring variables, creating STACKS
	string sentence, cont;
	char charsent[50], c1, c2;
	STACK<int, 50> RL, LR, T;
	RL.CreateStack();
	LR.CreateStack();
	T.CreateStack();

	while(true) {
		cout << endl;
		cout << "Enter a sentence: ";
		getline(cin, sentence);
		strcpy(charsent, sentence.c_str());

		// Pushing user input to STACK
		for (int i = 0; i < (signed int)sentence.size(); i++) {
			RL.PushStack(charsent[i]); // STACK is Right-to-Left
		}

		// Pushing RL into LR and T
		while (!RL.EmptyStack()) {
			c1 = RL.PopStack();
			if ((c1 == ',') || (c1 == '.') || (c1 == ' ') || (c1 == '?')) {
				// truncating punctuation and spaces
			} else {
				c1 = toupper(c1);
				T.PushStack(c1); // STACK is Left-to-Right
				LR.PushStack(c1);  // STACK is Left-to-Right
			}
		}

		// Pushing T into RL for uppercase
		while (!T.EmptyStack()) {
			c1 = T.PopStack();
			RL.PushStack(c1);
		}

		// STACK comparison
		while (!LR.EmptyStack()) {
			c1 = LR.PopStack();
			c2 = RL.PopStack();
			if (c1 != c2) {
				break;
			}
		}

		// If LR STACK was emptied with no break, Palindrome found
		if (LR.EmptyStack()) {
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
			// do nothing
		}
		cin.ignore();
	}
	return 0;
}