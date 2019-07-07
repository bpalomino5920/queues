#include "BQUEUE.h"

using namespace std;

//*********************************************************************************************
//*********************************************************************************************
// B Q U E U E . C P P

/*************************************************************************************
Name: BQUEUE
Precondition: front is not yet initialized yet
Postcondition:  front is initialized assigning to null
Description: This default constructor function starts off with front being null 0
*************************************************************************************/

BQUEUE::BQUEUE()
{
    front = 0;
}
/*************************************************************************************
Name: ~BQUEUE
Precondition: while loop is idle
Postcondition: while loop active and checking if time(data) is not null where it proceeds to delete front and move front.
Description: This destructor deallocates memory to make more room
*************************************************************************************/
BQUEUE::~BQUEUE()
{
    //Check if the Queue
    //is empty or not.
    if (front != NULL)
    {
        //Run the loop to deallocate the
        //memory that has been assignned
        //to the elements of the queue.
        //the elements.
        while(true)
        {
            //If only 1 element is remaining
            //in the queue then,
            //deallocate the memory, and
            //break out of the loop.
            if(front->next == front)
            {
                //Delete the front element
                //from the queue
                delete front;
                //Set the front pointer to NULL.
                front = NULL;
                break;
            }
            
            //Deallocate the memory allocated
            //to the current element and move
            //on to the next element.
            bqnode *curr = front->next;
            curr->next->prev = front;
            front->next = curr->next;
            delete curr;
        }
    }
}
/*************************************************************************************
Name: BQUEUE
Precondition:  front is not yet initialized.
Postcondition: front is assigned to org.front or a copy constructor.
Description: This copy constructor function copies a contructor
*************************************************************************************/
BQUEUE::BQUEUE(const BQUEUE & org)
{
    
    cout<<"Starting Copy Contructor and start Dequeuing... \n"<<endl;
    front = org.front;
}
/*************************************************************************************
Name: Enqueue
Precondition: empty is idle and parameter is not initialized.
Postcondition: if empty, front will create a node and organized itself with next and prev.
Else, create a node and organize the circular by moving a pointer and next and prev. 
Description: This Enqueue function insert an element
*************************************************************************************/
void BQUEUE::Enqueue(int i)
{
    cout<<"Element "<<i<<" inserted into Queue."<<endl;
    
    if (Empty())
    {
        front = new bqnode; //make a new node
        front->time = i;
        front->next = front->prev = front;
    }
    else
    {
        bqnode *p = new bqnode;
        p->time = i;
        p->prev = front->prev;
        p->next = front;
        front->prev = p;
        p->prev->next = p;
    }
}
/*************************************************************************************
Name: Dequeue
Precondition: if statement is idle, along with the assigning being not initialized yet.
Postcondition: if statement active and checking time from next is NULL, then arranges the circular queue using next and prev. 
Else, the queue is empty (display)
Description: This Dequeue function deletes an element.
*************************************************************************************/
void BQUEUE::Dequeue()
{
    //If the queue is empty then,
    //display an error message.
    if (front == NULL)
    {
        cout<<"Error in Dequeue: The queue"<<" is empty.\n";
    }
    //Otherwise, if there is only one
    //element in the queue then,
    //delete the element and set the
    //front pointer to NULL.
    else if (front->next == front)
    {
        cout<<"Deleted "<<front->time
        <<" from the queue.\n";
        delete front;
        front = NULL;
    }
    //Otherwise, delete the element
    //at the front of the queue.
    else
    {
        bqnode *temp = front;
        front->prev->next = temp->next;
        front->next->prev = temp->prev;
        front = front ->next;
        cout<<"Deleted "<<temp->time
        <<" from the queue.\n";
        delete temp;
    }
}


/*************************************************************************************
Name: Print
Precondition: if statment not active, ptr p not initialized yet, while loop idle.
Postcondition: if statment and while loop active. Checks empty condition. Ables to print when conditions passed. 
Description: This Print function displays the values or elements
*************************************************************************************/
void BQUEUE::Print()
{
    bqnode *p = front;

    if (!Empty())
    {
        while (p->next != front)
        {
            cout << p->time << endl;
            p = p->next;
        }
            cout << p->time << endl;
    }
}
