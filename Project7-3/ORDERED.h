#ifndef ORDERED_
#define ORDERED_

using namespace std;

template <class T>

class OLL {

private: 
	struct NODE {
		T info;
		NODE *next;
	};

	NODE* ordered;


public: 
	void CreateOrdered() { ordered = NULL; }

	void Insert(T x) {
		// insert x in an ordered linked list
		NODE* t, *q, *r;
		r = new (NODE);
		r -> info = x;
	
		// If r is the first item in the Ordered Linked List
		if (ordered == NULL) {
			ordered = r;
	  		r -> next = NULL;
		} else { 
			// find insertion place
			t = q = ordered;
			while (t != NULL && r -> info > t -> info) {
			q = t;
			t = t -> next;
			}
			// If r needs to be inserted at the front of the link list then do this
			if (t == ordered) {
				r -> next = t;
				ordered = r;
			} else { // This is for everything else inbetween and at the end of the Ordered link list
				r -> next = t;
				q -> next = r;
			}
		}	
	}

	void Display() {
		NODE *t = ordered;
		while (t != NULL) {
			cout << t -> info << " --> ";
			t = t -> next;
		}
		cout << "NULL\n";
	}

	void DisplayEven() {
		NODE *t = ordered;
		cout << "Even Numbers in the List: ";
		while (t != NULL) {
			if (t -> info % 2 == 0) {
				cout << t -> info << " ";
			}
			t = t -> next;
		}
		cout << "\n";
	}

	void DisplayOdd() {
		NODE *t = ordered;
		cout << "Odd Numbers in the List: ";
		while (t != NULL) {
			if (t -> info % 2 != 0) {
				cout << t -> info << " ";
			}
			t = t -> next;
		}
		cout << "\n";
	}

	void DisplayMaxMin() {
		NODE *t = ordered;
		int max = 0, min = 0;
		min = t -> info;
		while (t != NULL) {
			max = t -> info;
			t = t -> next;
			if (min > max) {
				max = min;
			}
			else if (max < min) {
				min = max;
			}
		}
		cout << "Max: " << max;
		cout << "\nMin: " << min;
		cout << "\n";
	}

	float ComputeAve() {
		NODE *t = ordered;
		float average = 0.0, counter;
		while (t != NULL) {
			counter++;
			average = average + t -> info;
			t = t -> next;
		}
		return average = average / counter;
	}

};

#endif
