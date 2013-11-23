//============================================================================
// Name        : RAF.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Banking Program with Random Access File
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct RECORD {
	int ID;
	char name[20];
	float balance;
};

// Menu Option 1
void Display(const char fname[]) {
	RECORD st;
	fstream f;
	f.open(fname, ios::in|ios::binary);
	cout << fixed << showpoint << setprecision(2);
	for (int i = 1; i <= 10; i++) {
		//read a record file from the RAF
		f.read((char*)&st, sizeof(st));
		cout << st.ID << "\t" << st.name << "\t" << st.balance << endl;
	}
	f.close();
}

// Menu Option 6
void Exit(const char fname[]) {
	RECORD st;
	fstream f;
	ofstream outfile;
	outfile.open("../../Cplusplus_CMPS385/RAFMenu/data.txt");
	f.open(fname, ios::in|ios::binary);
	//cout << fixed << showpoint << setprecision(2);
	for (int i = 1; i <= 10; i++) {
		//read a record file from the RAF
		f.read((char*)&st, sizeof(st));
		outfile << st.ID << "\t" << st.name << "\t" << st.balance << endl;
	}
	f.close();
}

// Menu Option 2
// x for ID
void Display(const char fname[], int x) {
	RECORD st;
	fstream fraf;
	fraf.open(fname, ios::in|ios::binary);
	int	byteOfSet = (x / 10 - 1)*sizeof(RECORD);
	cout << fixed << showpoint << setprecision(2);
	fraf.seekg(byteOfSet, ios::beg);
	fraf.read((char*)&st, sizeof(st));
	cout << st.ID << "\t" << st.name << "\t" << st.balance << endl;
	fraf.close();
}

// Menu Option 3
// x for ID, y for amount deposit
void Deposit(const char fname[], int x, float y) {
	RECORD dummy;
	fstream fraf;
	fraf.open(fname, ios::in|ios::out|ios::binary);
	int	byteOfSet = (x / 10 - 1)*sizeof(RECORD);
	fraf.seekg(byteOfSet, ios::beg);
	fraf.read((char*)&dummy, sizeof(RECORD));
	dummy.balance += y;
	//put the updated record back into the same place
	fraf.seekp(byteOfSet, ios::beg);
	fraf.write((char*)&dummy, sizeof(RECORD));
	fraf.close();
}

// Menu Option 4
// x for ID, y for amount deposit
void Withdraw(const char fname[], int x, float y) {
	RECORD dummy;
	fstream fraf;
	fraf.open(fname, ios::in|ios::out|ios::binary);
	int	byteOfSet = (x / 10 - 1)*sizeof(RECORD);
	fraf.seekg(byteOfSet, ios::beg);
	fraf.read((char*)&dummy, sizeof(RECORD));
	dummy.balance -= y;
	//put the updated record back into the same place
	fraf.seekp(byteOfSet, ios::beg);
	fraf.write((char*)&dummy, sizeof(RECORD));
	fraf.close();
}

// Menu Option 5
// x for ID
void CloseAccount(const char fname[], int x) {
	RECORD dummy = {0, "bbbb", 0.0};
	fstream fraf;
	fraf.open(fname, ios::in|ios::out|ios::binary);
	int	byteOfSet = (x / 10 - 1)*sizeof(RECORD);
	//put the updated record back into the same place
	fraf.seekp(byteOfSet, ios::beg);
	fraf.write((char*)&dummy, sizeof(RECORD));
	fraf.close();
}

int main() {
	// Part A
	// Creating a random access file and initializing it with 10 records {0, "bbbb", 0.0}
	fstream g;
	g.open("data.raf", ios::out|ios::binary);
	RECORD dummy = {0, "bbbb", 0.0};
	for (int i = 1; i <= 10; i++) {
		g.write((char*)&dummy, sizeof(RECORD));
	}
	g.close();

	// Part B
	// Transferring data from text file into RAF. Using ID as key value
	fstream ftxt;
	fstream fraf;
	// Opening text file to read
	ftxt.open("../../Cplusplus_CMPS385/RAFMenu/data.txt", ios::in);
	// Opening RAF to write
	fraf.open("data.raf", ios::out|ios::binary);
	for (int i = 1; i <= 10; i++) {
		ftxt >> dummy.ID >> dummy.name >> dummy.balance;
		int byteOfSet = (dummy.ID / 10 - 1)*sizeof(RECORD);
		// seekp to put (write)
		// seekg to get (read)
		fraf.seekp(byteOfSet, ios::beg);
		// beg - from beginning of file
		fraf.write((char*)&dummy, sizeof(RECORD));
	}
	fraf.close();
	ftxt.close();

	// Part C
	// Displaying the banking menu
	cout << endl;
	cout << "========Bank of Americana========\n";
	cout << "1. Display all Records from RAF\n";
	cout << "2. Display record with ID\n";
	cout << "3. Deposit into account with ID\n";
	cout << "4. Withdraw from account with ID\n";
	cout << "5. Close account with ID\n";
	cout << "6. Exit\n";
	cout << "=================================\n";
	while (true) {
		char cont;
		int idNum, choice;
		float amount;
		cout << "\nPlease enter your choice (1-6): ";
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "\nDisplaying all records: \n";
				Display("data.raf");
				break;
			case 2:
				cout << "Please enter a valid ID number: "; cin >> idNum;
				cout << "\nDisplaying record with ID " << idNum << "\n";
				Display("data.raf", idNum);
				break;
			case 3:
				cout << "Please enter a valid ID number: "; cin >> idNum;
				cout << "Please enter your deposit amount: "; cin >> amount;
				Deposit("data.raf", idNum, amount);
				cout << fixed << showpoint << setprecision(2);
				cout << "\n" << amount << " has been deposited into account with ID " << idNum << "\n";
				break;
			case 4:
				cout << "Please enter a valid ID number: ";	cin >> idNum;
				cout << "Please enter your withdraw amount: "; cin >> amount;
				Withdraw("data.raf", idNum, amount);
				cout << fixed << showpoint << setprecision(2);
				cout << "\n" << amount << " has been withdrawn from account with ID " << idNum << "\n";
				break;
			case 5:
				cout << "Please enter a valid ID number: ";	cin >> idNum;
				CloseAccount("data.raf", idNum);
				cout << "\nAccount with ID " << idNum << " has been closed." << "\n";
				break;
			case 6:
				cout << "Displaying RAF...\n";
				Display("data.raf");
				cout << "\nWriting to text file...\n";
				Exit("data.raf");
				break;
			default:
				cout << "Invalid choice.";
				break;
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
	return 0;
}