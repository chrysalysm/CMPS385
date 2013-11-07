#ifndef BST_
#define BST_

using namespace std;

template <class T>

class BST {

private:
	struct NODE {
		T info;
		NODE *left;
		NODE *right;
	};
	
	NODE *root;
 
public:

	BST() { root = NULL; }
 
	void Insert(NODE* & p, T x) {
		NODE* q;
		if (p == NULL) {
			q = new NODE;
			q -> info = x;
			q -> left = NULL;
			q -> right = NULL;
			p = q;
		} else {
			if (x < p -> info) {
				Insert(p -> left, x);
			} else {
				Insert(p -> right, x);
			}
		}
	}
 
	void Insert(T x) {
		Insert(root, x);
	}
 
 	// Inorder Display
	void DisplayInorder(NODE *p) {
		if (p != NULL) {
			DisplayInorder(p -> left); // LC
			cout << p -> info << "\t"; // P
			DisplayInorder(p -> right); // RC
		}
	}
	void DisplayInorder() {
		DisplayInorder(root);
	}

	// Preorder Display
	void DisplayPreorder(NODE *p) {
		if (p != NULL) {
			cout << p -> info << "\t"; // P
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
			cout << p -> info << "\t"; // P
		}
	}
	void DisplayPostorder() {
		DisplayPostorder(root);
	}

	// Display Leaves
	void DisplayLeaves(NODE *p) {
		if (p != NULL) {
			if (p -> left == NULL && p -> right == NULL) {
				cout << p -> info << "\t";
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
				cout << p -> info << "\t";
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
};

#endif