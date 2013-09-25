/*
 * STACK.h
 *
 *  Created on: Sep 24, 2013
 *      Author: Benjamin Chu
 */

#ifndef STACK_
#define STACK_

template <class T, int n>

class STACK {
private:
	T a[n];
	int counter;

public:
	void CreateStack() { counter = 0; }
	bool FullStack() { if (counter == n) return true; else return false; }
	bool EmptyStack() { if (counter == 0) return true; else return false; }
	void PushStack(T x) { a[counter] = x; counter++; }
	T PopStack() { counter--; return a[counter]; }
};

#endif /* STACK_ */
