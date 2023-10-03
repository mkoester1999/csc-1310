/*****************************************************************
	Title:  		Lab4.cpp
	Creation Date:  9-27-2023
	Last Updated:	9-27-2023
	Author: 		Mitchell Koester
	Purpose:		CSC 1310 Lab 4
******************************************************************/


#ifndef list_h
#define list_h

#include <string>
#include<iostream>
using namespace std;
struct ListNode
{
    string element;
    ListNode * next;
};

class List
{
public:

    ListNode* head;
    ListNode* tail;

    //constructor
    //parameters: head and tail
    List()
        {
            head = nullptr;
            tail = nullptr;
        }
    
    //destructor
    ~List();

    //appendNode function
    //makes a new node and appends it to the end of the list
    //parameters: string
    //returns: void
    void appendNode(string nodeElement);
    
    //insertNode function
    //insert the new node alphabetically.
    //parameters: string
    //returns: void
    void insertNode(string nodeElement);

    //deleteNode function
    //traverses list searching for node with element and deletes it
    //parameters: string
    //returns: void
    void deleteNode(string nodeElement);

    //displayList function
    //displays the list of nodes
    //parameters: none
    //returns: void
    void displayList() const;
    
};

List::~List()
{
 if(head)
    {
        //create temp node
        ListNode* temp = head;

    //traverse list until temp is null
        while(temp)
        {
            //create temp2 node and set to temp
            ListNode* temp2 = temp;
            //set temp to temp->next
            temp = temp->next;
            //delete temp2
            delete temp2;
        }
        
    }
    

}

void List::appendNode(string nodeElement)

{
    //create new node
    ListNode* newNode = new ListNode();
    //set element of newNode  to nodeElement
    newNode->element = nodeElement;

    //if list is empty, set head and tail to newNode
    if(!head)
    {
        head = newNode;
        tail = newNode;
    }

    //if list is not empty, set tail->next to newNode
    tail->next = newNode;
    //point tail to newNode
    tail = newNode;

}

void List::insertNode(string nodeElement)
{
    //create new node
    ListNode* newNode = new ListNode();
    //set element of newNode  to nodeElement
    newNode->element = nodeElement;

    //if list is empty, set head and tail to newNode
    if(!head)
    {
        head = newNode;
        tail = newNode;
    }

    //make temp node point to head
    ListNode* temp = head;
    //iterate through list until newNode->element is less than temp->element
    while(temp->next->element < newNode->element)
    {
        temp = temp->next;
    }
    //set newNode->next to temp->next
    newNode->next = temp->next;
    //set temp->next to newNode
    temp->next = newNode;
}

void List::deleteNode(string nodeElement)
{
    //check if list is full
    if(head)
    {
         //create temp node and set to head
        ListNode* temp = head;
        ListNode* temp2 = nullptr; //set to previous node 
        //traverse list until temp is null or temp->element is equal to nodeElement
        while(temp && temp->element != nodeElement)
        {
            temp2 = temp;
            temp = temp->next;
        }

        //check if temp = tail
        if(temp==tail)
        {
            tail = temp2;
        } 
        //set the previous node to the node after temp.
        else {temp2->next = temp->next;}
        delete temp; //delete temp
    }
       
}

void List::displayList() const
{
    ListNode* temp = head;
    while(temp)
    {
        cout << temp->element << endl;
        temp = temp->next;
    }
}



#endif