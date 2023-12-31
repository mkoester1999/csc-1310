/*
	Header for List class
	Project 2 - CSC1310
	Mitchell Koester & Bryant Koester

	10/13/23
*/

#ifndef list_h
#define list_h
#include<iostream>




template<class T>
class List
{
private:

   
    struct listNode
    {
        T element;
        listNode* next;
        listNode* prev;
        listNode(const T& value) : element(value), prev(nullptr), next(nullptr) {} //don't know why I need constructor, but default constructor gets implicitly delted for some reason

    };
    listNode* head;
    listNode* tail;
     
    
    //print function
    //prints out every element of list after the parameter node.
    //parameters: listNode
    //returns: void
    //comparing Ts with *(node->value)
    void print(listNode* node)
{
    listNode* temp = node; // Use the provided node instead of head
    while (temp != nullptr)
    {
        std::cout << temp->element << std::endl;
        temp = temp->next;
    }
}
    //mergesort function overload
    //manages recursive calls for mergesort function
    //parameters: listNode, listNode
    //returns: Node<T>*
    //comparing Ts with *(node->value)
    typename List<T>::listNode* mergesort(listNode* node1, listNode* node2)
    {
        //base case
        if(node1 == node2->next || node1 == node2 )
        {
            return node1;
        }

        listNode* mid = split(node1, node2);

        listNode* left = mergesort(node1, mid->prev);
        listNode* right  = mergesort(mid, node2);
        
        return merge(left, right);
    }
    
    //merge function
    //merges two sorted lists
    //parameters: listNode*, listNode*
    //returns: listNode *
    //comparing Ts with *(node->value)

    typename List<T>::listNode* merge(listNode* node1, listNode* node2)
    {
        //check if lists are empty
        if(!node1) return node2;
        if(!node2) return node1;

        //if node1 is smaller than node2
        if (node1->element > node2->element)
        {   
            //recursively call merge to get node1->next
            node1->next = merge(node1->next, node2);

            //set next and prev of node1
            node1->next->prev = node1;
            node1->prev = nullptr;

            return node1;
        }
        else
        {
            //recursively call merge to get node2->next
            node2->next = merge(node1, node2->next);

            //set next and prev of node2
            node2->next->prev = node2;
            node2->prev = nullptr;

            return node2;
        }
    }
    //split function
    //subdivide list partition into 2 new lists
    //paramters: listNode*, listNode*
    //returns: listNode*
    typename List<T>::listNode* split(listNode* _head, listNode* _tail)
    {
        
        //traverse from both sides of list to find middle node. Also check to see if _head->next is null
        while (_head != _tail && _head->next != _tail)
        {
            _head = _head->next;
            _tail = _tail->prev;
        }
        listNode* midNode = _head->next;
        _head->next = nullptr;

        return midNode;

     

    }


public:

    //list constructor
    //parameters: none
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    //list destructor
    ~List()
    {
        listNode* temp = head;
        while(temp != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        delete head;
        delete tail;
        delete temp;
    }


    //print function
    //prints all elements of the list
    //parameters: none
    //returns: void
    void print()
    {   
        print(head);
    }

    //append function
    //appends node to end of list
    //parameters: T element
    //returns: void
    void append(T element)
    {
        listNode* newNode = new listNode(element);
        if (!head) 
        {
                head = tail = newNode;
        } 
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

            
    }

    //mergesort function
    //sorts the list 
    //parameters: none
    //returns: void
    void mergesort()
    {
        head = mergesort(head, tail);    
    }

    //extra credit
    //selectionSort function
    //sorts the list
    //ascending order
    //parameters none
    //void selectionSort();
    

    //extra credit
    //swap function
    //swaps two nodes
    //parameters: listNode*, listNode*
    //called by selectionSort
    //void swap(listNode*, listNode*);
    
};

#endif