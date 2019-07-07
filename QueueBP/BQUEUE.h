#include <iostream>
#include <string>

using namespace std;

#ifndef BQUEUE_H
#define BQUEUE_H

class bqnode
{
    public:
        int time; //data
        bqnode *prev, *next; //node prev and next
};
class BQUEUE
{
    public:
        BQUEUE(); //default constructor
        ~BQUEUE(); //destructor
        BQUEUE(const BQUEUE &); //copy constructor
        void Enqueue(int); //inserting an element (type: int)
        void Dequeue(); //deleting an element
        bool Empty(){return front==0;} //checks if empty
        void Print(); //display values
        
    private:
        bqnode *front;//use ONLY one pointer
};

#endif
	
