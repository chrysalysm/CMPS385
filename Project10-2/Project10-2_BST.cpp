//============================================================================
// Name        : Project10-2.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Binary Search Tree
//============================================================================

#include <iostream>
#include "BST.h"
 
using namespace std;
 
int main() {
	BST<int> tree;
	int a[6] = {25, 9, 36, 2, 17, 40};
	for (int i = 0; i < 6; i++) {
		tree.Insert(a[i]);
	}

	cout << "\nInorder Traversal Display: \n";
	tree.DisplayInorder();
	cout << "\n\nPostorder Traversal Display: \n";
	tree.DisplayPostorder();
	cout << "\n\nPreorder Traversal Display: \n";
	tree.DisplayPreorder();
	cout << "\n\nDisplay Leaves only: \n";
	tree.DisplayLeaves();
	cout << "\n\nDisplay Parents only: \n";
	tree.DisplayParent();
 	cout << endl << endl;
	return 0;
}