#ifndef RESERVED_SLOT_QUEUE_H
#define RESERVED_SLOT_QUEUE_H

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operation on a queue as an
// array.
//*************************************************************

#include <iostream>
#include <cassert>
#include "queueADT.h"

using namespace std;

template <class Type>
class queueType: public queueADT<Type>
{
public:
    const queueType<Type>& operator=(const queueType<Type>&);
        //Overload the assignment operator.

    bool isEmptyQueue() const;
        //Function to determine whether the queue is empty.
        //Postcondition: Returns true if the queue is empty,
        //  otherwise returns false.

    bool isFullQueue() const;
        //Function to determine whether the queue is full.
        //Postcondition: Returns true if the queue is full,
        //  otherwise returns false.

    void initializeQueue();
        //Function to initialize the queue to an empty state.
        //Postcondition: The queue is empty.

    Type front() const;
        //Function to return the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        //  terminates; otherwise, the first element of the
        //  queue is returned.

    Type back() const;
        //Function to return the last element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        //  terminates; otherwise, the last element of the queue
        //  is returned.

    void addQueue(const Type& queueElement);
        //Function to add queueElement to the queue.
        //Precondition: The queue exists and is not full.
        //Postcondition: The queue is changed and queueElement is
        //  added to the queue.

    void deleteQueue();
        //Function to remove the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: The queue is changed and the first element
        //  is removed from the queue.

    queueType(int queueSize = 100);
        //Constructor

    queueType(const queueType<Type>& otherQueue);
        //Copy constructor

    ~queueType();
        //Destructor

private:
    int maxQueueSize;   //variable to store the maximum queue size
    int queueFront;     //variable to point to the first
                        //element of the queue
    int queueRear;      //variable to point to the last
                        //element of the queue
    Type *list;         //pointer to the array that holds
                        //the queue elements

    void copyQueue(const queueType<Type>& otherQueue);
        //Function to make a copy of otherQueue.
        //Postcondition: A copy of otherQueue is created and assigned
        //  to this queue.
};

template <class Type>
const queueType<Type>& queueType<Type>::operator=
                        (const queueType<Type>& otherQueue)
{
    if (this != &otherQueue)    //avoid self-copy
        copyQueue(otherQueue);

    return *this;
}

template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
    return queueFront == queueRear;
} //end isEmptyQueue

template <class Type>
bool queueType<Type>::isFullQueue() const
{
    return (queueFront == queueRear + 1) ||
        (queueFront == 0 && queueRear == maxQueueSize - 1);
} //end isFullQueue
  
template <class Type>
void queueType<Type>::initializeQueue()
{
    queueFront = 0;
    queueRear = 0;
} //end initializeQueue

template <class Type>
Type queueType<Type>::front() const
{
    assert(!isEmptyQueue());
    return list[(queueFront + 1) % maxQueueSize];
} //end front

template <class Type>
Type queueType<Type>::back() const
{
    assert(!isEmptyQueue());
    return list[queueRear];
} //end back

template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
    if (!isFullQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize; //use the
                            //mod operator to advance queueRear
                            //because the array is circular
        list[queueRear] = newElement;
    } else
        cout << "Cannot add to a full queue." << endl;
} //end addQueue

template <class Type>
void queueType<Type>::deleteQueue()
{
    if (!isEmptyQueue())
        queueFront = (queueFront + 1) % maxQueueSize;   //use the
                                //mode operator to advance queueFront
                                //because the array is circular
    else
        cout << "Cannot remove from an empty queue." << endl;
} //end deleteQueue

template <class Type>
queueType<Type>::queueType(int queueSize)
{
    if (queueSize <= 0)
    {
        cout << "Size of the array to hold the queue must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize;   //set maxQueueSize to
                                    //queueSize
    queueFront = 0;                 //initialize queueFront
    queueRear = 0;                  //initialize queueRear
    list = new Type[maxQueueSize];  //create the array to
                                    //hold the queue elements
} //end constructor
  
template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
    list = NULL;

    copyQueue(otherQueue);
}

template <class Type>
queueType<Type>::~queueType()
{
    delete [] list;
} //end destructor

template <class Type>
void queueType<Type>::copyQueue(const queueType<Type>& otherQueue)
{
    delete [] list;
    maxQueueSize = otherQueue.maxQueueSize;
    queueFront = otherQueue.queueFront;
    queueRear = otherQueue.queueRear;

    list = new Type[maxQueueSize];

        //copy otherQueue into this queue
    for (int j = queueFront; j <= queueRear; j++ )
        list[j] = otherQueue.list[j];
} //end copyQueue
#endif //RESERVED_SLOT_QUEUE_H
