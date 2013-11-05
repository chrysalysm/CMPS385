//============================================================================
// Name        : PFDMenu.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Perfect Fibonacci Distribution w/ Polyphase Merging
//============================================================================

#include <iostream>

using namespace std;

struct NODE {
	int info;
	NODE *next;
};

int main() {
	cout << endl;
	int fileSize, fileSizeDistro;
	char choice, cont;
	int fileSizeArrayOrderThree[7] = {1, 3, 5, 9, 17, 31, 57};
	int fileSizeArrayOrderFour[7] = {1, 4, 7, 13, 25, 49, 94};


	while (true) {
		cout << endl;
		cout << "=========PFD Menu=========\n";
		cout << "Enter a file size (< 50): ";
		cin >> fileSize;
		cout << "a. PFD of order 3\n";
		cout << "b. PFD of order 4\n";
		cout << "Enter your choice (a/b): ";
		cin >> choice;
		cout << endl;

		// Order 3 - Distribution and Output

		if (choice == 'a' && fileSize < 57) {
			cout << "F1\tT1\tT2\tT3\n";
			cout << "==========================";
			for (int i = 0; i < 7; i++) {
				if (fileSize > fileSizeArrayOrderThree[i]) {
					fileSizeDistro = fileSizeArrayOrderThree[i+1];
				} else if (fileSize == fileSizeArrayOrderThree[i]) {
					fileSizeDistro = fileSizeArrayOrderThree[i];
				} else {
					break;
				}
			}
			if (fileSizeDistro == 1) {
				cout << "\n1\t--\t--\t--\n";
				NODE *f1, *t1, *t2, *t3;
				f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE;
				f1 -> info = 0;	t1 -> info = 1;	t2 -> info = 0;	t3 -> info = 0;
				f1 -> next = t1; t1 -> next = t2; t2 -> next = t3; t3 -> next = NULL;
				NODE *p, *q, *r;
				int min = fileSizeDistro;
				while ((f1 -> info + t1 -> info + t2 -> info + t3 -> info) > 1) {
					p = f1;
					while (p != NULL) {
						if (min > p -> info && p -> info != 0) {
							min = p -> info;
						}					
						p = p -> next;
					}
					q = f1;
					while (q != NULL) {
						if (q -> info == 0) {
							cout << "--\t";
							q = q -> next;
						} else {
							cout << q -> info << "\t";
							q = q -> next;
						}
					}
					cout << "\n";
					r = f1;
					while (r != NULL) {
						r -> info -= min;
						if (r -> info < 0) {
							r -> info = min;
						}
						r = r -> next;
					}
				}
				q = f1;
				while (q != NULL) {
					if (q -> info == 0) {
						cout << "--\t";
						q = q -> next;
					} else {
						cout << q -> info << "\t";
						q = q -> next;
					}
				}
			} else if (fileSizeDistro == 3) {
				cout << "\n3\t--\t--\t--\n";
				NODE *f1, *t1, *t2, *t3;
				f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE;
				f1 -> info = 0;	t1 -> info = 1;	t2 -> info = 1;	t3 -> info = 1;
				f1 -> next = t1; t1 -> next = t2; t2 -> next = t3; t3 -> next = NULL;
				NODE *p, *q, *r;
				int min = fileSizeDistro;
				while ((f1 -> info + t1 -> info + t2 -> info + t3 -> info) > 1) {
					p = f1;
					while (p != NULL) {
						if (min > p -> info && p -> info != 0) {
							min = p -> info;
						}					
						p = p -> next;
					}
					q = f1;
					while (q != NULL) {
						if (q -> info == 0) {
							cout << "--\t";
							q = q -> next;
						} else {
							cout << q -> info << "\t";
							q = q -> next;
						}
					}
					cout << "\n";
					r = f1;
					while (r != NULL) {
						r -> info -= min;
						if (r -> info < 0) {
							r -> info = min;
						}
						r = r -> next;
					}
				}
				q = f1;
				while (q != NULL) {
					if (q -> info == 0) {
						cout << "--\t";
						q = q -> next;
					} else {
						cout << q -> info << "\t";
						q = q -> next;
					}
				}
			} else if (fileSizeDistro == 5) {
				cout << "\n5\t--\t--\t--\n";
				NODE *f1, *t1, *t2, *t3;
				f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE;
				f1 -> info = 0;	t1 -> info = 2;	t2 -> info = 2;	t3 -> info = 1;
				f1 -> next = t1; t1 -> next = t2; t2 -> next = t3; t3 -> next = NULL;
				NODE *p, *q, *r;
				int min = fileSizeDistro;
				while ((f1 -> info + t1 -> info + t2 -> info + t3 -> info) > 1) {
					p = f1;
					while (p != NULL) {
						if (min > p -> info && p -> info != 0) {
							min = p -> info;
						}					
						p = p -> next;
					}
					q = f1;
					while (q != NULL) {
						if (q -> info == 0) {
							cout << "--\t";
							q = q -> next;
						} else {
							cout << q -> info << "\t";
							q = q -> next;
						}
					}
					cout << "\n";
					r = f1;
					while (r != NULL) {
						r -> info -= min;
						if (r -> info < 0) {
							r -> info = min;
						}
						r = r -> next;
					}
				}
				q = f1;
				while (q != NULL) {
					if (q -> info == 0) {
						cout << "--\t";
						q = q -> next;
					} else {
						cout << q -> info << "\t";
						q = q -> next;
					}
				}
			} else if (fileSizeDistro == 9) {
				cout << "\n9\t--\t--\t--\n";
				NODE *f1, *t1, *t2, *t3;
				f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE;
				f1 -> info = 0; t1 -> info = 4;	t2 -> info = 3;	t3 -> info = 2;
				f1 -> next = t1; t1 -> next = t2; t2 -> next = t3; t3 -> next = NULL;
				NODE *p, *q, *r;
				int min = fileSizeDistro;
				while ((f1 -> info + t1 -> info + t2 -> info + t3 -> info) > 1) {
					p = f1;
					while (p != NULL) {
						if (min > p -> info && p -> info != 0) {
							min = p -> info;
						}					
						p = p -> next;
					}
					q = f1;
					while (q != NULL) {
						if (q -> info == 0) {
							cout << "--\t";
							q = q -> next;
						} else {
							cout << q -> info << "\t";
							q = q -> next;
						}
					}
					cout << "\n";
					r = f1;
					while (r != NULL) {
						r -> info -= min;
						if (r -> info < 0) {
							r -> info = min;
						}
						r = r -> next;
					}
				}
				q = f1;
				while (q != NULL) {
					if (q -> info == 0) {
						cout << "--\t";
						q = q -> next;
					} else {
						cout << q -> info << "\t";
						q = q -> next;
					}
				}
			} else if (fileSizeDistro == 17) {
				cout << "\n17\t--\t--\t--\n";
				NODE *f1, *t1, *t2, *t3;
				f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE;
				f1 -> info = 0; t1 -> info = 7; t2 -> info = 6; t3 -> info = 4;
				f1 -> next = t1; t1 -> next = t2; t2 -> next = t3; t3 -> next = NULL;
				NODE *p, *q, *r;
				int min = fileSizeDistro;
				while ((f1 -> info + t1 -> info + t2 -> info + t3 -> info) > 1) {
					p = f1;
					while (p != NULL) {
						if (min > p -> info && p -> info != 0) {
							min = p -> info;
						}					
						p = p -> next;
					}
					q = f1;
					while (q != NULL) {
						if (q -> info == 0) {
							cout << "--\t";
							q = q -> next;
						} else {
							cout << q -> info << "\t";
							q = q -> next;
						}
					}
					cout << "\n";
					r = f1;
					while (r != NULL) {
						r -> info -= min;
						if (r -> info < 0) {
							r -> info = min;
						}
						r = r -> next;
					}
				}
				q = f1;
				while (q != NULL) {
					if (q -> info == 0) {
						cout << "--\t";
						q = q -> next;
					} else {
						cout << q -> info << "\t";
						q = q -> next;
					}
				}
			} else if (fileSizeDistro == 31) {
				cout << "\n31\t--\t--\t--\n";
				NODE *f1, *t1, *t2, *t3;
				f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE;
				f1 -> info = 0; t1 -> info = 13; t2 -> info = 11; t3 -> info = 7;
				f1 -> next = t1; t1 -> next = t2; t2 -> next = t3; t3 -> next = NULL;
				NODE *p, *q, *r;
				int min = fileSizeDistro;
				while ((f1 -> info + t1 -> info + t2 -> info + t3 -> info) > 1) {
					p = f1;
					while (p != NULL) {
						if (min > p -> info && p -> info != 0) {
							min = p -> info;
						}					
						p = p -> next;
					}
					q = f1;
					while (q != NULL) {
						if (q -> info == 0) {
							cout << "--\t";
							q = q -> next;
						} else {
							cout << q -> info << "\t";
							q = q -> next;
						}
					}
					cout << "\n";
					r = f1;
					while (r != NULL) {
						r -> info -= min;
						if (r -> info < 0) {
							r -> info = min;
						}
						r = r -> next;
					}
				}
				q = f1;
				while (q != NULL) {
					if (q -> info == 0) {
						cout << "--\t";
						q = q -> next;
					} else {
						cout << q -> info << "\t";
						q = q -> next;
					}
				}
			} else if (fileSizeDistro == 57) {
				cout << "\n57\t--\t--\t--\n";
				NODE *f1, *t1, *t2, *t3;
				f1 = new NODE; t1 = new NODE; t2 = new NODE; t3 = new NODE;
				f1 -> info = 0; t1 -> info = 24; t2 -> info = 20; t3 -> info = 13;
				f1 -> next = t1; t1 -> next = t2; t2 -> next = t3; t3 -> next = NULL;
				NODE *p, *q, *r;
				int min = fileSizeDistro;
				while ((f1 -> info + t1 -> info + t2 -> info + t3 -> info) > 1) {
					p = f1;
					while (p != NULL) {
						if (min > p -> info && p -> info != 0) {
							min = p -> info;
						}					
						p = p -> next;
					}
					q = f1;
					while (q != NULL) {
						if (q -> info == 0) {
							cout << "--\t";
							q = q -> next;
						} else {
							cout << q -> info << "\t";
							q = q -> next;
						}
					}
					cout << "\n";
					r = f1;
					while (r != NULL) {
						r -> info -= min;
						if (r -> info < 0) {
							r -> info = min;
						}
						r = r -> next;
					}
				}
				q = f1;
				while (q != NULL) {
					if (q -> info == 0) {
						cout << "--\t";
						q = q -> next;
					} else {
						cout << q -> info << "\t";
						q = q -> next;
					}
				}

			} else {
				// do nothing
			}

		// Order 4 - Distribution and Output

		} else if (choice == 'b') {
			cout << "F1\tT1\tT2\tT3\tT4\n";
			cout << "==================================";
			

		} else {
			cout << "\nThat is an invalid choice and/or filesize.\n";
			break;
		}

		cout << endl;
		cin.ignore();
		cout << "\nContinue (y/n)?: ";
		cin >> cont;
		if (cont == 'y') {
			// do nothing
		} else {
			break;
		}
	}

	cout << endl;
	return 0;
}