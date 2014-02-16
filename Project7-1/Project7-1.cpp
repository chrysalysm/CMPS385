//============================================================================
// Name        : Project7-1.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Ordered Linked List - Finding Odd/Even/Max/Min/Average
//============================================================================

#include <iostream>
#include <time.h>
#include "ORDERED.h"

using namespace std;

int main() {
	cout << endl;
	// Defining Variables and Creating OLL
	srand(time(NULL));
	float ave;
	OLL<int> Order;
	Order.CreateOrdered();
	
	// Loop to insert 10 random numbers <50
	for (int i = 0; i < 10; i++) {
		Order.Insert(rand() % 51);
	}

	// Output and Calculation
	Order.DisplayEven();
	Order.DisplayOdd();
	Order.DisplayMaxMin();
	ave = Order.ComputeAve();
	cout << "Average: " << ave << endl;
	cout << endl;
	Order.Display();
	return 0;
}