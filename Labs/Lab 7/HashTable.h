/*
	Title:    Lab.7cpp
	Author:   Mitchell Koester 
	Date:     October 31, 2023
	Purpose: Header and implementation of hash table 
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<string>
#include"HashEntry.h"

using namespace std;

class HashTable
{

private:
   int size;
   HashEntry **table;

    //hash function
    //hashes a given key
    //parameters: string key
    //returns int
   int hash(int key)
   {
       return key % size;
   }

public:

    //constructor
    //parameters: int size
    HashTable(int tableSize)
    {
        //point table to array of hashEntry pointers
        table = new HashEntry*[tableSize];
        this->size = tableSize;
    }

    //destructor
    ~HashTable()
    {
        //iterate through table deleting all entries inside
        for(int i = 0; i< this->size; i++)
        {
            delete table[i];
        }
    }

    //putValue function
    //takes a key a costume object and puts it into the hash table. Handles collisions witgh linear probing
    //parameters: int key, costume
    //returns void
    void putValue(int key, Costume* costume)
    {
        //hash key to get index
        int index = hash(key);
        //check if there is a collision
        while (table[index] != nullptr)
        {
            cout<<"Collision at bucket "<<index<<endl;
            index++;
        }
        //output the current index and make a new entry with the key and costume
        cout<<"Bucket "<<index<<endl;
        table[index] = new HashEntry(key, costume);
    }

    //printHashTable function
    void printHashTable()
    {
        for(int i = 0; i < size; i++)
        {
            if(table[i] != nullptr)
            {
                cout<<i<<": "<<table[i]->getKey()<<", "<< table[i]->getValue()->getCostumeName()<<endl;
            }
        }
    }

};


#endif
