/*Title   	  Implementaion for Program 3
  Authors     Bryant & Mitchell Koester
  Purpose     Hashing Passwords
  Date 		  Nov 3th 2023
  */

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
//hashTable destructor
//parameters: none
//returns: none
hashTable::~hashTable()
{
	for(int i = 0; i < tableSize; i++)
	{
		if(hashArray[i])
		{
			entry* temp = hashArray[i];
			while(temp)
			{
				entry* next = temp->next;
				delete temp;
				temp = next;
			}
		}
	}
	delete[] hashArray;
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

	if(!user) return "";
	return user->getSalt();

}

void hashTable::addEntry(string username, string salt, string passHash)
{
	tableSize++;
	entry* user = new entry(username, salt, passHash);

	//generate hash for the index 
	int hashIndex = hash(username);

	//check if there is a value at hashIndex already
	if(!hashArray[hashIndex])
	{
		//add user to hashIndex if there is no collisoin
		hashArray[hashIndex] = user;
	}
	else
	{
		//make temp entry for traversal
		entry* temp = hashArray[hashIndex];
		//iterate through list until next entry is null
		while(temp->next)
		{
			temp = temp->next;
		}
		//set next entry to user
		temp->next = user;
	}
	

}

bool hashTable::validateLogin(string username, string hashedPass)
{
	//call getentry and set to new entry pointer
	entry* user = getEntry(username);

	//check if the hashed password matches the stored hashed password
	if(user && user->getHashedpwd() == hashedPass) return true;
	//else return false
	return false;


}

//remove user from hashTable
//parameters: string username, string hashedpassword
//returns bool
bool hashTable::removeUser(string username, string hashedPassword) 
{
    int hashIndex = hash(username);

    if (hashArray[hashIndex]) {
        entry* current = hashArray[hashIndex];
        entry* previous = nullptr;

        while (current) {
            if (current->getUsername() == username && current->getHashedpwd() == hashedPassword) 
			{
                if (previous) {
                    // If it's not the first element in the list
                    previous->next = current->next;
                } else {
                    // If it's the first element in the list
                    hashArray[hashIndex] = current->next;
                }

                delete current;
				tableSize--;
                return true;
            }

            previous = current;
            current = current->next;
        }
    }

    return false;
}
hashTable::entry * hashTable::getEntry(string key)
{
	//check if table is empty
	if(tableSize>0)
	{
		//hash string 
		int hashIndex = hash(key);

		//check if there is an entry at hashIndex
		if(!hashArray[hashIndex]) return nullptr;

		if(hashArray[hashIndex]->getUsername() == key) return hashArray[hashIndex];

		//if there were prior collisions
		else if(hashArray[hashIndex]->next)
		{
			//iterate through list checking for username
			entry * temp = hashArray[hashIndex];
			while(temp && temp->getUsername() != key)
			{
				temp = temp->next;				
			}
			//temp either is set to the correct entry or reached the end of the list and is null
			return temp;
		}
	}
	return nullptr;
	
}

//entry class functions-------------------------------------------------
hashTable::entry::entry(string _uname, string _salt, string _passedHash)
{
	uname = _uname;
	salt = _salt;
	passHash = _passedHash;
	next = nullptr;

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
