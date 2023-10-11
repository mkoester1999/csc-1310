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

    //mergesort function
    //sorts the list 
    //parameters: none
    //returns: void
    void mergesort();


private:
    //print function
    //prints out every element of list after the parameter node.
    //parameters: listNode<T>
    //returns: void
    void print(listNode<T>* node);

    //mergesort function overload
    //manages recursive calls for mergesort function
    //parameters: listNode<T>, listNode<T>
    //returns: Node<T>*
    listNode<T>* mergesort(listNode<T>* node1, listNode<T>* node2);
    
    //merge function
    //merges two sorted lists
    //parameters: listNode<T>*, listNode<T>*
    //returns: listNode<T> *
    listNode<T>* merge(listNode<T>* node1, listNode<T>* node2);

    //split function
    //subdivide list partition into 2 new lists
    //paramters: listNode<T>*, listNode<T>*
    //returns: listNode<T>*
    listNode<T>* split(listNode<T>* node1, listNode<T>* node2)
    


};

#endif