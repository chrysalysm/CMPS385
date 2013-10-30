//============================================================================
// Name        : Project7-3.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Ordered Linked Lists, Queues and fstream data
//============================================================================

#include <iostream>
#include <fstream>
#include "QUEUE.h"
#include "ORDERED.h"

using namespace std;

struct Person {
	string first, last;
	int age;
};

int main() {
	cout << endl;
	QUEUE Q, QQ;
	OLL Order;
	Q.CreateQueue();
	Order.CreateOrdered();
	Person p[5];
	
	// Creating the Data.txt file
	fstream myFile;
	myFile.open("data.txt", ios::out);
	myFile << "Smith John 25\n";
	myFile << "Jackson Adam 22\n";
	myFile << "Jones Jay 55\n";
	myFile << "Miller Ana 17\n";
	myFile << "Obama Barack 34\n";
	myFile.close();

	// Extracting data from text file
	myFile.open("data.txt", ios::in);
	for (int i = 0; i < 5; i++) {
		myFile >> p[i].first >> p[i].last >> p[i].age;
	}
	myFile.close();

	// Inserting each record into the queue
	for (int i = 0; i < 5; i++) {
		Q.Push(p[i].first, p[i].last, p[i].age);
	}

	// Putting the records in an ordered linked list
	// Arranged by their age, from oldest to youngest
	for (int i = 0; i < 5; i++) {
		Order.Insert(p[i].first, p[i].last, p[i].age);
	}
	// Pushing from OLL to new Queue
	while (!Order.EmptyOrdered()) {
		QQ.Push(Order.PopFirst(), Order.PopLast(), Order.PopAge());
	}

	// Part (c) - Displaying both Lists
	Q.Display();
	QQ.Display();

	cout << endl;
	return 0;
}