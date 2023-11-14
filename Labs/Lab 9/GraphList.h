#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include<iostream>

using namespace std;

class GraphList
{
private:
    struct ListNode
    {
        int vertex;
        ListNode *next;
    };

    ListNode ** headArray;

    int numVertices;
    int numEdges;

public:
    //constructor
    GraphList(int _numVertices)
    {
        this->numVertices = _numVertices;
        headArray = new ListNode*[numVertices];

        //add vertices to headarray
        for(int i = 0; i<numVertices; i++)
        {
            headArray[i] = new ListNode;
            headArray[i]->vertex = i;
        }
    }

    //destructor
    ~GraphList()
    {
        //traverse headarray
        for (int i = 0; i < numVertices; i++)
        {
            //while there is a node at position i, delete it and all nodes it points to
            while(headArray[i])
            {
                ListNode* temp = headArray[i];
                headArray[i] = headArray[i]->next;
                delete temp;
            }
        }
    }

    
    void addEdge(int source, int destination)
    {
        //create destinationNode
        ListNode* destinationNode = new ListNode;
        destinationNode->vertex = destination;

        ListNode* tempNode = headArray[source];
        //traverse linked list attached to sourceNode to find the end
        while(tempNode->next)
        {
            tempNode = tempNode->next;
        }
        //add destinationNode to the end of the list
        tempNode->next = destinationNode;

    }

    //printGraph function
    //traverses list and prints out the values of all the nodes
    //parameters: none
    //returns void
    void printGraph()
    {
        //traverse headarray
        for (int i = 0; i < numVertices; i++)
        {   
            //traverse list at position i
            ListNode* temp = headArray[i];
            while (temp)
            {
                cout << temp->vertex << "--->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

#endif