//============================================================================
// Name        : Project12-FractionOverload.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Fractions and Overloading
//============================================================================

#include <iostream>
 
using namespace std;

class fract {

	private: int n, d;

	public: 
		void read() {
			cin >> n;
			cin.ignore();
			cin >> d;
		}

		fract operator*(fract g) {
			fract r;
			r.n = n * g.n;
			r.d = d * g.d;
			return r;
		}

		fract operator/(fract g) {
			fract r;

			r.n = n * g.d;
			r.d = d * g.n;
			return r;
		}

		friend fract operator+(fract p, fract q) {
			fract s;
			s.n = p.n * q.d + p.d * q.n;
			s.d = p.d * q.d;
			return s;
		}

		friend fract operator-(fract p, fract q) {
			fract s;
			s.n = p.n * q.d - p.d * q.n;
			s.d = p.d * q.d;
			return s;
		}

		friend bool operator<(fract p, fract q) {
			if (p.n * q.d < p.d * q.n) return true;
			else return false;
		}

		friend void operator++(fract & p) {
			p.n++;
			p.d++;
		}

		friend void operator--(fract & p) {
			p.n--;
			p.d--;
		}


		void show() {
			cout << n << "/" << d;
		}
};

int main() {
	fract f1, f2, res;
	// read two fractions
	cout << "\nEnter a fraction: ";
	f1.read();
	cout << "Enter another fraction: ";
	f2.read();

	// comp and display f1 + f2
	res = f1 + f2; cout << endl;
	f1.show(); cout << " + ";
	f2.show(); cout << " = ";
	res.show();

	// comp and display f1 - f2
	res = f1 - f2; cout << endl;
	f1.show(); cout << " - ";
	f2.show(); cout << " = ";
	res.show();
	cout << endl;

	// comp and display f1 * f2;
	res = f1 * f2;
	f1.show(); cout << " * ";
	f2.show(); cout << " = ";
	res.show();
	cout << endl;

	// comp and display f1 / f2
	res = f1 / f2;
	f1.show(); cout << " / ";
	f2.show(); cout << " = ";
	res.show();

	cout << endl;

	// compare f1 with f2
	if (f1 < f2) cout << "f1 < f2 \n";
	else cout << "f2 < f1 \n";

	// comp and display f2++
	f2.show();
	cout << "++ = ";
	++f2;
	f2.show();
	cout << endl;

	// comp and display f1--
	f1.show();
	cout << "-- = ";
	--f1;
	f1.show();
	cout << endl << endl;

	return 0;
}