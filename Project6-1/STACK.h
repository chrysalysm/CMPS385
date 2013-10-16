/*
 * STACK.h
 *
 *  Created on: October 14th, 2013
 *      Author: Benjamin Chu
 */

#ifndef STACK_
#define STACK_

using namespace std;

template <class T>
 
// linked list implementation of STACK
class STACK {
	private:
 
	struct NODE {
		char info;
		NODE *next;
	};
 
	NODE *stack;
 
	public:
 
	void CreateStack() { stack = NULL; }
	
	void Push(char x) {
		NODE *r;
		r = new NODE;
		r -> info = x;
		r -> next = stack;
		stack = r;
	}
 
	char Pop() {
		NODE *p = stack;
		char x = stack -> info;
		stack = p -> next;
		delete(p);
		return x;
	}
 
	bool EmptyStack() {
		if (stack == NULL) { return true; }
		else { return false; }
	}
 
	void Display() {
		NODE *p = stack;
		while (p != NULL) {
			cout << p -> info << " ==> ";
			p = p -> next;
		}
		cout << "NULL\n";
	}
};

#endif /* STACK_ */
