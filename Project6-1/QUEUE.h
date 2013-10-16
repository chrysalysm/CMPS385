/*
 * QUEUE.h
 *
 *  Created on: October 14th, 2013
 *      Author: Benjamin Chu
 */

#ifndef QUEUE_
#define QUEUE_

using namespace std;

template <class T>

// linked list implementation of QUEUE
class QUEUE {
	private:
		
	struct NODE {
		char info;
		NODE *next;
	};

	NODE *queue;
 
	public:

	void CreateQueue() { queue = NULL; }

	void Push(char x) {
		NODE *r, *rear;
		r = new NODE;
		r -> info = x;
		r -> next = NULL;
		// if there is nothing in the linked list
		if (queue == NULL) {
			// insert the first item
			queue = r;
		} 
		// queue exists and x
		// must be inserted at the rear
		else {
			rear = queue;
			while (rear -> next != NULL) {
				rear = rear -> next;
			}
			rear -> next = r;
		}
	}
 
	char Pop() {
		NODE *p = queue;
		char x = queue -> info;
		queue = p -> next;
		delete(p);
		return x;
	}
 
	bool EmptyQueue() {
		if (queue == NULL) { return true; }
		else { return false; }
	}
 
	void Display() {
		NODE *p = queue;
		while (p != NULL) {
			cout << p -> info << " ==> ";
			p = p -> next;
		}
		cout << "NULL\n";
	}
};

#endif /* QUEUE_ */
