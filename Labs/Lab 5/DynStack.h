#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

/*
Mitchell Koester
Lab 5
Oct 16, 2023
Header for Dynamic Stack
*/

template<typename T>
class DynStack
{
private:

    struct StackNode
    {
        T data;
        StackNode* next;
    };
    StackNode* top;


public:

    //constructor
    DynStack()
    {
        top = nullptr;
    }

    //destructor
    ~DynStack()
    {
        //iterates through list and deletes each node until list is empty
        while(!isEmpty())
        {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    //push function
    //takes value T and creates a new node, then pushes that node to the stack
    //parameters: T value
    //returns void
    void push(T value)
    {
        //make new node and set it's data to value
        StackNode* newNode = new StackNode;
        newNode->data = value;

        if(!isEmpty())
        {
            //if list isn't empty, set new node's next to the top
            newNode->next = top;

            //set top to newNode
            top = newNode;
        }
        else 
        {
            //set top to newNode and next to null
            top = newNode;
            top->next = nullptr;
        }
    }

    //pop function
    //removes the top node from the stack and then returns it.
    //Parameters: none
    //returns T*
    //The lab directions did not tell us this is how were were supposed to implement this function. I had to figure it out by deduction.
    void pop(T& item)
    {
        if(!isEmpty())
        {
            StackNode* temp = top;
            //set item to top
            item = top->data;
            //set top to the next node
            top = top->next;

            //delete temp;
            delete temp;
        }
    }

    //isEmpty function
    //returns whether or not the stack is empty
    //Parameters: none
    //returns bool
    bool isEmpty()
    {
        return (top == nullptr);
    }
};


#endif