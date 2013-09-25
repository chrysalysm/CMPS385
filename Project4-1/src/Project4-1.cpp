//============================================================================
// Name        : Project4-1.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : STACKS and postfix expression calculation
//============================================================================

#include <iostream>
#include "STACK.h"
using namespace std;

int main() {
	// Declaring variables, creating STACK
	string expression, cont;
	char charexp[20], reader;
	int i = 0, x, y, r;
	STACK<int, 20> S;
	S.CreateStack();

	while(true) {
		// User input
		cout << endl;
		cout << "Enter a postfix expression: ";
		getline(cin, expression);
		strcpy(charexp, expression.c_str());
		i = 0;
		
		while(true) {
			// Reading user inputted postfix expression
			// Based on input, perform action required
			reader = charexp[i];
			if (reader == 'a') {
				S.PushStack(3); // Supposing a = 3
				i++;
			} else if (reader == 'b') {
				S.PushStack(11); // Supposing b = 11
				i++;
			} else if (reader == 'c') {
				S.PushStack(5); // Supposing c = 5
				i++;
			} else if (reader == 'd') {
				S.PushStack(8); // Supposing d = 8
				i++;
			} else if (reader == '+') {
				x = S.PopStack();
				y = S.PopStack();
				r = y + x;
				S.PushStack(r);
				i++;
			} else if (reader == '*') {
				x = S.PopStack();
				y = S.PopStack();
				r = y * x;
				S.PushStack(r);
				i++;
			} else if (reader == '-') {
				x = S.PopStack();
				y = S.PopStack();
				r = y - x;
				S.PushStack(r);
				i++;
			} else if (reader == '$') { // If '$' is found, end of postfix
				cout << "Value = " << S.PopStack() << endl;
				break;
			} else {
				cout << "Bad input detected!" << endl;
				break;
			}
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
	cout << endl;
	return 0;
}