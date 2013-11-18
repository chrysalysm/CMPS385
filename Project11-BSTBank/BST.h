#ifndef BST_
#define BST_

using namespace std;

class BST {

private:
	struct NODE {
		int ID;
		string name;
		int balance;
		NODE *left;
		NODE *right;
	};
	
	NODE *root;
 
public:

	BST() { root = NULL; }

	// x for ID, y for name, z for balance
	void Insert(NODE* & p, int x, string y, int z) {
		NODE* q;
		if (p == NULL) {
			q = new NODE;
			q -> ID = x;
			q -> name = y;
			q -> balance = z;
			q -> left = NULL;
			q -> right = NULL;
			p = q;
		} else {
			if (x < p -> ID) {
				Insert(p -> left, x, y, z);
			} else {
				Insert(p -> right, x, y, z);
			}
		}
	}
 
	void Insert(int x, string y, int z) {
		Insert(root, x, y, z);
	}


 
 	// Inorder Display
	void DisplayInorder(NODE *n) {
		if (n != NULL) {
			DisplayInorder(n -> left); // LC
			cout << n -> ID << "\t" << n -> name << "\t" << n -> balance << "\n"; // P
			DisplayInorder(n -> right); // RC
		}
	}
	void DisplayInorder() {
		DisplayInorder(root);
	}

	// Preorder Display
	void DisplayPreorder(NODE *p) {
		if (p != NULL) {
			cout << p -> ID << "\t" << p -> name << "\t" << p -> balance << "\n"; // P
			DisplayPreorder(p -> left); // LC
			DisplayPreorder(p -> right); // RC
		}
	}
	void DisplayPreorder() {
		DisplayPreorder(root);
	}
 
 	// Postorder Display
	void DisplayPostorder(NODE *p) {
		if (p != NULL) {
			DisplayPreorder(p -> left); // LC
			DisplayPreorder(p -> right); // RC
			cout << p -> ID << "\t" << p -> name << "\t" << p -> balance << "\n"; // P
		}
	}
	void DisplayPostorder() {
		DisplayPostorder(root);
	}

	// Display Leaves
	void DisplayLeaves(NODE *p) {
		if (p != NULL) {
			if (p -> left == NULL && p -> right == NULL) {
				cout << p -> ID << "\t" << p -> name << "\t" << p -> balance << "\n";
			} else {
				DisplayLeaves(p -> left);
				DisplayLeaves(p -> right);
			}
		}
	}
	void DisplayLeaves() {
		DisplayLeaves(root);
	}

	// Display Parents with 2 children
	void DisplayParent(NODE *p) {
		if (p != NULL) {
			if (p -> left != NULL && p -> right != NULL) {
				cout << p -> ID << "\t" << p -> name << "\t" << p -> balance << "\n";
				DisplayParent(p -> left);
				DisplayParent(p -> right);
			} else {
				DisplayParent(p -> left);
				DisplayParent(p -> right);
			}
		}
	}
	void DisplayParent() {
		DisplayParent(root);
	}

	void DisplayAccount(NODE *p, int x) {
		if (p != NULL) {
			if (p -> ID == x) {
				cout << "\t" << p -> name << ", you have " << p -> balance << " in your account.\n";
			} else {
				DisplayAccount(p -> left, x);
				DisplayAccount(p -> right, x);
			}
		}
	}

	void DisplayAccount(int x) {
		DisplayAccount(root, x);
	}

	void DepositAccount(NODE *p, int x, int y) {
		if (p != NULL) {
			if (p -> ID == x) {
				p -> balance += y;
				cout << "\t" << p -> name << ", you have deposited " << y << " into your account.\n";
				cout << "\tYou now have a total of " << p -> balance << " in your account.\n";
			} else {
				DepositAccount(p -> left, x, y);
				DepositAccount(p -> right, x, y);
			}
		}
	}

	void DepositAccount(int x, int y) {
		DepositAccount(root, x, y);
	}

	void WithdrawAccount(NODE *p, int x, int y) {
		if (p != NULL) {
			if (p -> ID == x) {
				p -> balance -= y;
				cout << "\t" << p -> name << ", you have withdrawn " << y << " from your account.\n";
				cout << "\tYou now have a total of " << p -> balance << " in your account.\n";
			} else {
				WithdrawAccount(p -> left, x, y);
				WithdrawAccount(p -> right, x, y);
			}
		}
	}

	void WithdrawAccount(int x, int y) {
		WithdrawAccount(root, x, y);
	}

	void DeleteNode(NODE *p, NODE *q, int x) {
		// p = current node
		// q = parent node
		NODE *d;
		if (p != NULL) {
			if (p -> ID == x) {
				// Node to remove has NO child
				if (p -> left == NULL && p -> right == NULL && q -> right -> ID == p -> ID) {
					q -> right = NULL;
					delete p;
				} else if (p -> left == NULL && p -> right == NULL && q -> left -> ID == p -> ID) {
					q -> left = NULL;
					delete p;
				} 
				// Node to remove has ONE child
				else if (p -> left == NULL && p -> right != NULL && q -> right -> ID == p -> ID) {
					q -> right = p -> right;
					delete p;
				} else if (p -> left != NULL && p -> right == NULL && q -> right -> ID == p -> ID) {
					q -> right = p -> left;
					delete p;
				} else if (p -> left == NULL && p -> right != NULL && q -> left -> ID == p -> ID) {
					q -> left = p -> right;
					delete p;
				} else if (p -> left != NULL && p -> right == NULL && q -> left -> ID == p -> ID) {
					q -> left = p -> left;
					delete p;
				}
				// Node to remove has TWO children
				else if (p -> left != NULL && p -> right != NULL) {
					d = p;
					if (p -> right -> left == NULL) {
						p = p -> right;
						d -> ID = p -> ID;
						d -> name = p -> name;
						d -> balance = p -> balance;
						DeleteNode(d -> right, d, p -> ID);
					} else {
						p = p -> right -> left;
						d -> ID = p -> ID;
						d -> name = p -> name;
						d -> balance = p -> balance;
						DeleteNode(d -> right, d, p -> ID);
					}
				} else {
					// do nothing - all cases covered
				}
			} else {
				DeleteNode(p -> left, p, x);
				DeleteNode(p -> right, p, x);
			}
		}
	}

	void DeleteNode(int x) {
		DeleteNode(root, root, x);
	}
	/*
	// this function needs a rewrite or something
	// http://www.algolist.net/Data_structures/Binary_search_tree/Removal
	void Delete(NODE* & p, int x) {
		NODE *q;
		if (p != NULL) {
			q = p;
			if (p -> right -> ID == x) {
				p = p -> right;
				// deletion of a leaf
				if (p -> right == NULL && p -> left == NULL) {
					q -> right = NULL;
					delete(p);
				// deletion if left subtree empty
				} else if (p -> right != NULL && p -> left == NULL) {
					q -> right = p -> right;
					delete(p);
				// deletion if right subtree empty
				} else if (p -> right == NULL && p -> left != NULL) {
					q -> right = p -> left;
					delete(p);
				// deletion if both subtree not empty
				} else {
					if (p -> right -> left == NULL) {
						// right subtree root is min
						// replace values and then delete the min
						NODE *r;
						r = p -> right;
						p -> ID = r -> ID;
						p -> name = r -> name;
						p -> balance = r -> balance;
						Delete(p, r -> ID);
					} else {
						// right subtree left is min
						NODE *r;
						r = p -> right -> left;
						p -> ID = r -> ID;
						p -> name = r -> name;
						p -> balance = r -> balance;
						Delete(p -> right, r -> ID);
					}
				}
			} else if (p -> left -> ID == x) {
				p = p -> left;
				if (p -> right == NULL && p -> left == NULL) {
					q -> left = NULL;
					delete p;
				// deletion if left subtree empty
				} else if (p -> right != NULL && p -> left == NULL) {
					q -> left = p -> right;
					delete p;
				// deletion if right subtree empty
				} else if (p -> right == NULL && p -> left != NULL) {
					cout << q -> ID;
					cout << p -> left -> ID;
					q -> left = p -> left;
					delete p;
				// deletion if both subtree not empty
				} else {
					if (p -> right -> left == NULL) {
						// right subtree root is min
						// replace values and then delete the min
						NODE *r;
						r = p -> right;
						p -> ID = r -> ID;
						p -> name = r -> name;
						p -> balance = r -> balance;
						Delete(p, r -> ID);
					} else {
						// right subtree left is min
						NODE *r;
						r = p -> right -> left;
						p -> ID = r -> ID;
						p -> name = r -> name;
						p -> balance = r -> balance;
						Delete(p -> right, r -> ID);
					}
				}
			} else {
				Delete(p -> right, x);
				Delete(p -> left, x);
			}
		}
	}

	void Delete(int x) {
		Delete(root, x);
	}
	*/
};

#endif