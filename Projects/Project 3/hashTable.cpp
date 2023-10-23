#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
using std::string;
using std::cout;

hashTable::hashTable(int size)
{
	//you need to add everything else that belongs in the constructor--------------------------------------
	srand (time(0));	//this needs to be in the constructor, otherwise every user gets the same salt

	hashArray = new entry*[size];
	for(int i = 0; i < size; i++)
		hashArray[i] = nullptr;


}

//don't touch this!
int hashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.size(); i++)
		sum += key[i];
	
	return sum % tableSize;
}

//don't touch this!
string hashTable::generateSalt()
{
	string s = "";
	
	for(int i = 0; i < tableSize; i++)
		s = s + char('!' + (rand() % 93));
	return s;
}

string hashTable::getSalt(string username)
{
	entry* user = getEntry(username);
	return user->getSalt();

}

//entry class functions-------------------------------------------------
hashTable::entry::entry(string _uname, string _salt, string _passedHash)
{
	uname = _uname;
	salt = _salt;
	passHash = _passedHash;

}

string hashTable::entry::getUsername()
{
	return uname;
}

string hashTable::entry::getSalt()
{
	return salt;
}

string hashTable::entry::getHashedpwd()
{
	return passHash;
}
