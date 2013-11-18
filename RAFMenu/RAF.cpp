#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct RECORD
{
	int ID;
	char name[10];
	float balance;
};

void Display(const char fname[])
{
	RECORD st;
	fstream f;
	f.open(fname, ios::in|ios::binary);
	cout<<fixed<<showpoint<<setprecision(2);
	for(int i=1; i<=5; ++i)
	{
		//read a record file from the RAF
		f.read((char*)&st, sizeof(st));
		cout<<st.ID<<'\t'<<st.name<<'\t'<<st.balance<<endl;
	}
	f.close();
}

int main()
{
	//initalize the RAF with dummy record 0, "nnn", 0.0
	fstream g;
	g.open("data.raf", ios::out|ios::binary);
	RECORD dummy={0, "nnn", 0.0};
	for(int i=1; i<=5; ++i)
	{
		g.write((char*)&dummy, sizeof(RECORD));
	}
	g.close();

	Display("data.raf");

	//copy text file into RAF
	fstream ftxt;
	fstream fraf;

	//open text file to read from
	ftxt.open("../../Cplusplus_CMPS385/RAFMenu/data.txt", ios::in);

	//open RAF to write
	fraf.open("data.raf", ios::out|ios::binary);

	for(int i=1; i<=5; ++i)
	{
		ftxt>>dummy.ID>>dummy.name>>dummy.balance;
		int byteOfSet = (dummy.ID/10-1)*sizeof(RECORD);

		//seekp	to put (write)
		//seekg	to get (read)
		fraf.seekp(byteOfSet, ios::beg);

		//beg	from beginning of file
		fraf.write((char*)&dummy, sizeof(RECORD));
	}

	//deposit 100 in ID #40
	int	id;
	cout<<"Enter an ID number: ";
	cin>>id;
	fraf.open("data.raf", ios::in|ios::out|ios::binary);
	int	byteOfSet = (id/10-1)*sizeof(RECORD);
	fraf.seekg(byteOfSet, ios::beg);
	fraf.read((char*)&dummy, sizeof(RECORD));
	dummy.balance += 100;

	//put the updated record back into the same place
	fraf.seekp(byteOfSet, ios::beg);
	fraf.write((char*)&dummy, sizeof(RECORD));
	//fraf.close();

	ftxt.close();
	fraf.close();
	Display("data.raf");

	return 0;
}

