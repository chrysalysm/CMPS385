/*
 * QUEUE.h
 *
 *  Created on: October 14th, 2013
 *      Author: Benjamin Chu
 */

#ifndef QUEUE_
#define QUEUE_

#include <math.h>

using namespace std;

// linked list implementation of QUEUE
class QUEUE {
	private:
		struct NODE {
			float coef;
			int expo;
			NODE *next;
		};

	NODE *queue;
 
	public:
		void CreateQueue() { queue = NULL; }

		void Push(float x, int y) {
			NODE *r, *rear;
			r = new NODE;
			r -> coef = x;
			r -> expo = y;
			r -> next = NULL;
			// if there is nothing in the linked list
			if (queue == NULL) {
				// insert the first item
				queue = r;
			} 
			// queue exists; x and y
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
			cout << "This is your function F(x)\n";
			cout << "\tF(x) = ";
			NODE *p = queue;
			while (p != NULL) {
				cout << p -> coef << "x^" << p -> expo << " + ";
				p = p -> next;
			}
			cout << "\b\b";
			cout << " \n";
		}

		float Compute(float x) {
			NODE *p = queue;
			float total = 0.0;
			while (p != NULL) {
				total = total + p -> coef * pow(x, p -> expo);
				p = p -> next;
				
			}
			return total;
		}
};

#endif /* QUEUE_ */
