/*
Mitchell Koester
Header file for Queue class
Lab 6
10/20/23
*/

#ifndef QUEUE_H
#define QUEUE_H
#include<string>
#include<iostream>

using namespace std;
class Queue
{
private:
    struct QueueNode
    {
        string value;
        QueueNode* next;
    };

    int numNodes;
    QueueNode* head;
    QueueNode* tail;

public:
    //Default constructor
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        numNodes = 0;
    }

    //Destructor
    ~Queue()
    {
        string name;
        //dequeue until list is empty
        while(!isEmpty())
        {
            name = dequeue();
            cout<<"Oh shoot, I am sorry, our park is closed so "<< name<< " will not get to ride today."<<endl;

        }
    }

    //enqueue function
    //Takes a value and adds it to the end of the queue
    //Paramters: string value
    //Returns void
    void enqueue(string value)
    {
        //make new QueueNode
        QueueNode* newNode = new QueueNode;
        newNode->value = value;
        //check if queue is empty
        if(!isEmpty())
        {   
            //set newNode->next to head
            newNode->next = head;
            //set head to newNode
            head = newNode;
        }
        else
        {
            //set head to newNode
            head = tail = newNode;
        }
        numNodes++;
    }

    //dequeue function
    //removes the last item from queue
    //parameters: none
    //returns string
    string dequeue()
    {
        if (!isEmpty())
        {
            //grab the value of the current tail node for returning
            string returnedValue = tail->value;

            if (head == tail)
            {
                // If there is only one node in the queue, set head and tail to null
                head = nullptr;
                tail = nullptr;
            }
            else 
            {
                //create tempNode for traversing through queue
                QueueNode* tempNode = head;
                // Iterate to find the node before the tail
                while (tempNode->next != tail)
                {
                    tempNode = tempNode->next;
                }
                // set tail to tempNode and delete the last node (tempNode->next)
                tail = tempNode;
                delete tempNode->next;

                //set tail->next to null just in case it's still pointing to the deleted tempNode->next 
                tail->next = nullptr;
            }
            numNodes--;
            return returnedValue;
        }
        //return empty string if there's nothing in the queue.
        return "";
    }


    bool isEmpty()
    {
        return(!head);
    }

};


#endif