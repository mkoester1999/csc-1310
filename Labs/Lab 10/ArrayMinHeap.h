#ifndef HEAP_h
#define HEAP_h

#include "Creature.h"

class ArrayMinHeap
{
private:
    Creature* heapArray;
    int capacity;
    int heap_size;

    //swap function
    //takes 2 creature pointers and swaps them
    //parameters: Creature*, Creature*
    //returns void
    void swap(Creature* creature1, Creature* creature2)
    {
        Creature* temp = creature1;
        creature1 = creature2;
        creature2 = temp;
    }

    //parent function
    //returns the parent creature of the creature at index
    //parameters: int index
    //returns Creature*
    int parent(int index)
    {
        return (index-1)/2; 
    }

    //left function
    //returns the left index of the creature at index
    //paramters: int index
    //returns int 
    int left(int index)
    {
        return (2*index + 1);
    }

    //right function
    //returns the right index of the creature at index
    //paramters: int index
    //returns int
    int right(int index)
    {
        return (2*index + 2);
    }

public:
    //constructor
    ArrayMinHeap(int capacity)
    {
        this->capacity = capacity;
        heapArray = new Creature[capacity];
        heap_size = 0;
    }
    //destructor
    ~ArrayMinHeap()
    {
        delete[] heapArray;
    }

    //minHeapify function
    //adjusts heap to make sure it fits min heap rule
    //parameters: int index
    //returns void
    void minHeapify(int index)
    {
        int l = left(index);
        int r = right(index);
        int smallest = index;
        if (l < heap_size && heapArray[l].getCost() < heapArray[index].getCost())
            smallest = l;
        if (r < heap_size && heapArray[r].getCost() < heapArray[smallest].getCost())
            smallest = r;
        if (smallest != index)
        {
            swap(&heapArray[index], &heapArray[smallest]);
            minHeapify(smallest);
        }

    }

    //peek function
    //returns the root creature
    //parameters: none
    //returns Creature*
    Creature* peek()
    {
        if (isEmpty())
        {
            cout << "Error:  there are no nodes in the heap.\n";
            return nullptr;
        }
        Creature* creaturePtr = &heapArray[0];
        return creaturePtr;
    }

    //remove function
    //removes the root creature and readjusts the heap
    //parameters: reference to creature being deleted(this is just to return the removed creature)
    //returns bool
    bool remove(Creature &creature)
    {
        if (isEmpty())
        {
            cout << "Error:  there are no nodes in the heap.\n";
            return false;
        }
        else
        {
            creature = heapArray[0];
            heapArray[0] = heapArray[heap_size];
            heap_size--;
            minHeapify(0);
            return true;
        }
    }
    void insert(Creature* newCreature)
    {
        if (heap_size == capacity)
	    {
		    resizeArray();	//double the size of array & capacity
	    }

    	// First insert the new value at the end
	    heapArray[heap_size] = *newCreature;
	    heap_size++;
	    int i = heap_size - 1;

    	// Fix the min heap property if it is violated
	    while (i != 0 && heapArray[parent(i)].getCost() > heapArray[i].getCost())
	    {
		    swap(&heapArray[i], &heapArray[parent(i)]);
		    i = parent(i);
	    }
    }
    void resizeArray()
    {
        int cap = capacity * 2; 
        Creature* newHeapArray = new Creature[cap];
        
        for(int x = 0; x < capacity; x++)
        {
            newHeapArray[x] = heapArray[x];
        }
        delete [] heapArray;
        heapArray = newHeapArray;
        capacity = cap;
    }
    bool isEmpty()
    {
        if(heap_size == 0)
            return true;
        else
            return false;
    }
    int getNumberOfNodes()
    {
        return heap_size;
    }

    void display()
    {
        for(int i = 0; i < heap_size; i++)
        {
            heapArray[i].printCreature();
        }
    }

    void saveToFile()
    {
        for(int i = 0; i < heap_size; i++)
        {
            heapArray[i].printCreatureToFile("savedCreatures.txt");
        }
    }
};

#endif