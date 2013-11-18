//============================================================================
// Name        : Project11-BSTBank.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Banking Program with Binary Search Tree
//============================================================================

#include <iostream>
#include <fstream>
#include "BST.h"
 
using namespace std;

struct Record {
	int ID, balance;
	string name;
};
 
int main() {
	fstream myFile;
	myFile.open("../../Cplusplus_CMPS385/Project11-BSTBank/data.txt", ios::out);
	myFile << "33 Maria 1333\n";
	myFile << "44 Andre 1444\n";
	myFile << "55 Carlo 1555\n";
	myFile << "22 Laura 1222\n";
	myFile << "11 Tory 1111\n";
	myFile << "66 Alison 1666\n";
	myFile.close();

	Record r[6];
	myFile.open("../../Cplusplus_CMPS385/Project11-BSTBank/data.txt", ios::in);
	for (int i = 0; i < 6; i++) {
		myFile >> r[i].ID >> r[i].name >> r[i].balance;
	}
	myFile.close();

	BST bank;
	for (int i = 0; i < 6; i++) {
		bank.Insert(r[i].ID, r[i].name, r[i].balance);
	}
	
	cout << endl;
	cout << "=======Bank of California=======\n";
	cout << "a. Display all accounts\n";
	cout << "b. Show my balance\n";
	cout << "c. Deposit\n";
	cout << "d. Withdraw\n";
	cout << "e. Close account\n";
	cout << "f. Open a new account\n";
	cout << "================================\n";
	while (true) {
		cout << "Please enter your choice (a-f): ";
		char choice, cont;
		int idNum, amount, initBal;
		string acctName;
		cin >> choice;
		if (choice == 'a') {
			bank.DisplayInorder();
		} else if (choice == 'b') {
			cout << "\tEnter your ID number: ";
			cin >> idNum;
			bank.DisplayAccount(idNum);
		} else if (choice == 'c') {
			cout << "\tEnter your ID number: "; cin >> idNum;
			cout << "\tEnter the amount: ";
			cin >> amount;
			bank.DepositAccount(idNum, amount);
		} else if (choice == 'd') {
			cout << "\tEnter your ID number: "; cin >> idNum;
			cout << "\tEnter the amount: ";
			cin >> amount;
			bank.WithdrawAccount(idNum, amount);
		} else if (choice == 'e') {
			cout << "\tEnter the ID of account you wanna close: "; cin >> idNum;
			bank.DeleteNode(idNum);
			cout << "Account with ID " << idNum << " is now closed.";
		} else if (choice == 'f') {
			cout << "\tEnter the ID number you want: "; cin >> idNum;
			cout << "\tEnter the name on the account: "; cin >> acctName;
			cout << "\tEnter your initial balance: "; cin >> initBal;
			bank.Insert(idNum, acctName, initBal);
		} else {
			cout << "Not a valid choice.\n";
		}

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