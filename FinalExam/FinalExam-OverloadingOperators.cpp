//============================================================================
// Name        : FinalExam-OverloadingOperators.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Part G - Overloading Operators
//============================================================================

#include <iostream>
 
using namespace std;

class point {

	private: int x, y;

	public: 
		void read() {
			cin >> x;
			cin.ignore();
			cin >> y;
		}

		friend point operator+(point p, point q) {
			point s;
			s.x = p.x + q.x;
			s.y = p.y + q.y;
			return s;
		}

		friend point operator-(point p, point q) {
			point s;
			s.x = p.x - q.x;
			s.y = p.y - q.y;
			return s;
		}

		friend void operator++(point & p) {
			p.x++;
			p.y++;
		}

		friend void operator--(point & p) {
			p.x--;
			p.y--;
		}

		void show() {
			cout << "(" << x << ", " << y << ")";
		}
};

int main() {
	point p1, p2, res;
	// read two fractions
	cout << "\nEnter the x and y coordinates of Point A: ";
	p1.read();
	cout << "Enter the x and y coordinates of Point B: ";
	p2.read();

	// comp and display p1 + p2
	cout << "A"; p1.show(); cout << " + ";
	cout << "B"; p2.show(); cout << " = ";
	res = p1 + p2;
	res.show();

	cout << endl;
	// comp and display p1 - p2
	cout << "A"; p1.show(); cout << " - ";
	cout << "B"; p2.show(); cout << " = ";
	res = p1 - p2;
	res.show();

	// comp and display p1++
	cout << "\nA"; p1.show();
	cout << "++ = ";
	++p1;
	p1.show();

	cout << endl;
	// comp and display p2++
	cout << "B"; p2.show();
	cout << "++ = ";
	++p2;
	p2.show();

	// comp and display p1--
	cout << "\nA"; p1.show();
	cout << "-- = ";
	--p1;
	p1.show();

	cout << endl;
	// comp and display p2++
	cout << "B"; p2.show();
	cout << "-- = ";
	--p2;
	p2.show();
	cout << "\n\n";

	return 0;
}