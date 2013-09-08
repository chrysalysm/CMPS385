//============================================================================
// Name        : Project2ii.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Project2ii
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

// Defining struct
struct Person {
	string name;
	float gpa;
	int age;
};

// Declare User functions
void Copy(string, Person[]);
void Display(Person[]);
void Display(float, int);
void DisplayTeens(Person[]);
float AverageGPA(Person[], float &);
int AverageAGE(Person[]);

int main() {

	// Project 2i
	fstream myFile;
	myFile.open("data.txt", ios::out);
	myFile << "Michael 33 3.3\n";
	myFile << "Joseph 44 3.7\n";
	myFile << "Rusian 19 2.9\n";
	myFile << "Joel 17 3\n";
	myFile << "Cristina 21 3.2\n";
	myFile.close();

	Person a[5];
	// Copy data from file data.txt into array a
	Copy("data.txt", a);
	// Display array a
	Display(a);
	// Display the names of teenager students
	DisplayTeens(a);
	// Compute the average GPA
	float gpaAvg;
	AverageGPA(a, gpaAvg);
	// Compute the average AGE
	float ageAvg;
	ageAvg = AverageAGE(a);
	// Display the average GPA and AGE by overloading the Display function
	Display(AverageGPA(a, gpaAvg), AverageAGE(a));
	return 0;
}

// Defining Copy function
void Copy(string fname, Person x[]) {
	fstream myfile;
	// g++ 4.2.1 does not support passing string into open(), must be const char *
	myfile.open(fname.c_str(), ios::in);
	for (int i = 0; i < 5; i++) {
		myfile >> x[i].name >> x[i].age >> x[i].gpa;
	}
	myfile.close();
}

// Defining Display function
void Display(Person x[]) {
	cout << left << setw(10) << "Name" << setw(4) << "Age" << right << setw(4) << "Gpa" << endl;
	cout << "------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << left << setw(10) << x[i].name << setw(4) << x[i].age
		<< right << setw(4) << setprecision(2) << setiosflags(ios::fixed) << x[i].gpa << endl;
	}
}

// Defining Display function
void Display(float gpa, int age) {
	cout << "The GPA average is: " << gpa << endl;
	cout << "The AGE average is: " << age << endl;
}

// Defining DisplayTeens function
void DisplayTeens(Person x[]) {
	cout << "This is the list of teenagers: " << endl;
	for (int i = 0; i < 5; i++) {
		if (x[i].age <= 19 && x[i].age >= 13) {
			cout << x[i].name << " ";
		}
	}
	cout << endl;
}

// Defining AverageGPA function
float AverageGPA(Person x[], float &gpa) {
	gpa = 0.0;
	for (int i = 0; i < 5; i++) {
		gpa = gpa + x[i].gpa;
	}
	gpa = gpa / 5.0;
	return gpa;
}

// Defining AverageAGE function
int AverageAGE(Person x[]) {
	int age = 0;
	for (int i = 0; i < 5; i++) {
		age = age + x[i].age;
	}
	return age / 5;
}
