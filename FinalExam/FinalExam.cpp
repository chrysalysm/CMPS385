//============================================================================
// Name        : FinalExam.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : FinalExam Work
//============================================================================

#include <iostream>

using namespace std;
/*
template <class T, class U, class V>

void Show(T x, U y, V z) {
	cout << x << " " << y << " " << z;
}*/

class WISH {
	private: int x, y;
	public: 
		WISH() { cout << "Happy "; }
		~WISH() { cout << "Holidays "; }
};

int main() {
	cout << endl;
	Summer Is, Long, Vacation;	
	//Show("Happy", "New", 2006);
	
	cout << endl;
	int a[5] = {1,7,3,9,2}, *p;
	p = a;
	cout << *(a+3) << *p;
	cout << endl;
	cout << *(a+*p);
	cout << endl;
	cout << *&a[2];
	cout << endl;
	p = &a[3]; p++; cout << *p;
	cout << endl;
	p = &a[4]; p--; cout << *p;
	cout << endl;

	int b[4] = {9,8,4,2}, *q;
	for (q=&b[3]; q>b; --q) {
		cout << *q << " ";
	}
	cout << endl;
	p = &b[2];
	*p = *(b+2) + 1;
	*b = b[3];
	p++;
	b[1] = *p;

	for (int i = 0; i<4;++i) {
		cout << *(b+i) << " ";
	}
	cout << endl;


	cout << endl;
	return 0;
}