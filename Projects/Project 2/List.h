#ifndef list_h
#define list_h

using namespace std;

template<class T>
struct listNode
{
    T element;
    listNode<T> *next;
    listNode<T> *prev;
};

template<class T>
class List
{
public:

    listNode<T>* head;
    listNode<T>* tail;

    //list constructor
    //parameters: none
    List();

    //list destructor
    ~List();

    //print function
    //prints all elements of the list
    //parameters: none
    //returns: void
    void print();

    //append function
    //appends node to end of list
    //parameters: T element
    //returns: void
    void append(T element);


};

#endif