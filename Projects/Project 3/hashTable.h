/*Title   	  Header for Program 3
  Authors     Bryant & Mitchell Koester
  Purpose     Hashing Passwords
  Date 		  Nov 3th 2023
  */

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
using std::string;

class hashTable
{
	private:
		class entry;

		//add the attributes you need for the class---------------------------------------------------------
		int tableSize;
		//array of entry pointers
		entry** hashArray;
		
		//hash function
		//map a key onto a bucket index the key is mapped to
		//Parameters: string
		//returns: int
		int hash(string);

		//getEntry function
		//retrieves entry from hash table
		//parameters: string
		//returns entry*
		entry* getEntry(string key);


	public:
		//add all the functions you need--------------------------------------------------------------------

		//generateSalt function
		//assigns attribute to given parameter and sets next pointer to null
		//parameters: none
		//Returns: string
		string generateSalt();

		//constructor
		//parameters: int space
		hashTable(int space);

		//destructor
		~hashTable();

		//getSalt function
		//appends the salt to a password before we hash it
		//parametrers: string username
		//returns: string
		string getSalt(string username);

		//addEntry function
		//add new user to table
		//Parameters: string, string, string
		//returns: void
		void addEntry(string username, string salt, string passHash);

		//validateLogin function
		//check if user has entered correct credentials
		//parameters: string username, string password
		//returns bool
		bool validateLogin(string username, string password);

		//removeuser function
		//remove user from hashTable
		//parameters: string username, string hashedpassword
		//returns bool
		bool removeUser(string username, string hashedPassword);



};

class hashTable::entry
{
	private:
		string uname;
		string salt;
		string passHash;
	public:
		entry* next;

		//add the constructor and getter functions-----------------------------------------------------------
		//constructor
		entry(string _uname, string _salt, string _passHash);

		//getusername function
		//parameters: none
		//returns string username
		string getUsername();

		//getSalt function
		//returns salt for hashing password
		//parameters: none
		//returns string salt
		string getSalt();

		//getHashedpwd function
		//paramters: none
		//returns string passHash
		string getHashedpwd();

};

#endif