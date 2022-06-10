#ifndef UNORDERED_LINKED_QUEUE_H
#define UNORDERED_LINKED_QUEUE_H

#include "unorderedLinkedList.h"

using namespace std;

template <class Type>
class linkedQueueType: public unorderedLinkedList<Type>
{
public:
    const linkedQueueType<Type>& operator=
                        (const linkedQueueType<Type>&);
        //Overload the assignment operator.

    bool isEmptyQueue() const;
        //Function to determine whether the queue is empty.
        //Postcondition: Returns true if the queue is empty,
        //  otherwise returns false.

    void initializeQueue();
        //Function to initialize the queue to an empty state.
        //Postcondition: queueFront = NULL; queueRear = NULL

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
        //  terminates; otherwise, the last element of the
        //  queue is returned.
        
    int queueCount() const;
        //Function to return the number of elements in the queue.
        //Postcondition: Returned count.

    void addQueue(const Type& queueElement);
        //Function to remove the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: The queue is changed and the first element
        //  is removed from the queue.

    void deleteQueue();
        //Function to remove the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: The queue is changed and the first element
        //  is removed from the queue.

    linkedQueueType();
        //Default constructor.

    linkedQueueType(const linkedQueueType<Type>& otherQueue);
        //Copy constructor.

    ~linkedQueueType();
        //Destructor.
private:
    void copyQueue(const linkedQueueType<Type>& otherQueue);
        //Function to make a copy of otherQueue.
        //Postcondition: A copy of otherQueue is created and
        //  assigned to this queue.
};

template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
                        (const linkedQueueType<Type>& otherQueue)
{
    if (this != &otherQueue)    //avoid self-copy
        copyQueue(otherQueue);

    return *this;
} //end operator=

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    using linkedListType<Type>::isEmptyList;
    return isEmptyList();
} //end isEmptyQueue

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    using linkedListType<Type>::initializeList;
    initializeList();
} //end initializeQueue

template <class Type>
Type linkedQueueType<Type>::front() const
{
    using linkedListType<Type>::front;
    return front();
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const
{
    using linkedListType<Type>::back;
    return back();
} //end back

template <class Type>
int linkedQueueType<Type>::queueCount() const
{
    using linkedListType<Type>::count;
    return count;
} //end queueCount

template <class Type>
void linkedQueueType<Type>::addQueue(const Type& queueElement)
{
    using unorderedLinkedList<Type>::insertLast;
    insertLast(queueElement);
} //end addQueue

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    using unorderedLinkedList<Type>::deleteItemAt;
    deleteItemAt(0);
} //end deleteQueue

template <class Type>
linkedQueueType<Type>::linkedQueueType()
{
    initializeQueue();
} //end default constructor

template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>&
                                        otherQueue)
{
    initializeQueue();
    copyQueue(otherQueue);
} //end copy constructor

template <class Type>
linkedQueueType<Type>::~linkedQueueType()
{
    initializeQueue();
} //end destructor

template <class Type>
void linkedQueueType<Type>::copyQueue
                        (const linkedQueueType<Type>& otherQueue)
{
    using linkedListType<Type>::copyList;
    copyList(otherQueue);
}
#endif //UNORDERED_LINKED_QUEUE_H
