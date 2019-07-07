#include <iostream>
#include "BQUEUE.h"
using namespace std;
//*********************************************************************************************
//*********************************************************************************************
// "B Q U E U E _ d r i v e r . C P P
//EXAMPLE OF PROGRAM HEADER
/********************************************************************************************
Name: Brandon Palomino			Z#: Z23254937
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 07/03/2019	 Due Time: 11:59PM
Total Points: 25
Assignment 8: Queue program
Description: This program is to demonstrates 
*********************************************************************************************/
int main()
{
    BQUEUE k;
    
    k.Enqueue(60);
    k.Print();
    k.Enqueue(20);
    k.Enqueue(30);
    k.Print();
    k.Enqueue(10);
    k.Print();
    k.Enqueue(50);
    k.Enqueue(40);
    k.Print();
    
    BQUEUE j = k;
    
    j.Dequeue();
    j.Print();
    j.Dequeue();
    j.Dequeue();
    j.Dequeue();
    j.Print();
    j.Dequeue();
    j.Dequeue();
    j.Print();
    j.Dequeue();
    j.Dequeue();
    return 0;
}
