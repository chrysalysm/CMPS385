/*
 * QUEUE.h
 *
 *  Created on: October 14th, 2013
 *      Author: Benjamin Chu
 */

#ifndef QUEUE_
#define QUEUE_

using namespace std;

// linked list implementation of QUEUE
class QUEUE {
	private:
		
	struct NODE {
		string first, last;
		int age;
		NODE *next;
	};

	NODE *queue;
 
	public:

	void CreateQueue() { queue = NULL; }

	void Push(string x, string y, int z) {
		NODE *r, *rear;
		r = new NODE;
		r -> first = x;
		r -> last = y;
		r -> age = z;
		r -> next = NULL;
		// if there is nothing in the linked list
		if (queue == NULL) {
			// insert the first item
			queue = r;
		} 
		// queue exists
		// must be inserted at the rear
		else {
			rear = queue;
			while (rear -> next != NULL) {
				rear = rear -> next;
			}
			rear -> next = r;
		}
	}
 
	bool EmptyQueue() {
		if (queue == NULL) { return true; }
		else { return false; }
	}
 
	void Display() {
		NODE *p = queue;
		while (p != NULL) {
			cout << "[" << p -> first << "," << p -> last << " " << p -> age << "] -> ";
			p = p -> next;
		}
		cout << "NULL\n";
	}
};

#endif /* QUEUE_ */
