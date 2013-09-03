//============================================================================
// Name        : Project2i.cpp
// Author      : Benjamin Chu
// Version     :
// Copyright   : Creative Commons - Attribution 3.0
// Description : Project2i
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream myFile;
	myFile.open("data.txt", ios::out);
	myFile << "Michael 33 3.3\n";
	myFile << "Joseph 44 3.7\n";
	myFile << "Rusian 19 2.9\n";
	myFile << "Joel 17 3\n";
	myFile << "Cristina 21 3.2\n";
	myFile.close();
	return 0;
}
