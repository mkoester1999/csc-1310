#include <iostream>
#include "HashTable.h"
using namespace std;

const int TIMES = 5;
int main()
{
	int size;
	int value;
	
	cout << "\nHello.\n\n";
	
	cout <<"What size is the table?   ";
	cin >> size;
	
	//create a Hash Table
	HashTable myHashTable(size);
	
	//add some keys and values

	for(int i = 0; i < TIMES; i++)

	{
		cout << "\nEnter a value:  ";
		cin >> value;
		myHashTable.putValue(value, value);
	}
	
		
	cout << "\n\nHERE IS THE TABLE:\n\n";
	myHashTable.printHashTable();
	cout << endl << endl;
	
	//delete value
	cout<<"Please enter a value to delete: ";
	cin>>value;
	myHashTable.removeValue(value);

	cout<<"Table after deletion"<<endl;
	myHashTable.printHashTable();
	cout << endl << endl;

	
}