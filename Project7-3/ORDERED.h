#ifndef ORDERED_
#define ORDERED_

using namespace std;

class OLL {

private: 
	struct NODE {
		string first, last;
		int age;
		NODE *next;
	};

	NODE* ordered;

public: 
	void CreateOrdered() { ordered = NULL; }

	void Insert(string x, string y, int z) {
		// insert x in an ordered linked list
		NODE *t, *q, *r;
		r = new (NODE);
		r -> first = x;
		r -> last = y;
		r -> age = z;
	
		// If r is the first item in the Ordered Linked List
		if (ordered == NULL) {
			ordered = r;
	  		r -> next = NULL;
		} else { 
			// find insertion place
			t = q = ordered;
			while (t != NULL && r -> age < t -> age) {
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

	bool EmptyOrdered() {
		if (ordered == NULL) { return true; }
		else { return false; }
	}

	void Display() {
		NODE *p = ordered;
		while (p != NULL) {
			cout << "[" << p -> first << "," << p -> last << " " << p -> age << "] -> ";
			p = p -> next;
		}
		cout << "NULL\n";
	}

	string PopFirst() {
		NODE *p = ordered;
		string x = p -> first;
		return x;
	}

	string PopLast() {
		NODE *p = ordered;
		string y = p -> last;
		return y;
	}

	int PopAge() {
		NODE *p = ordered;
		int z = p -> age;
		ordered = p -> next;
		delete(p);
		return z;
	}
};

#endif
