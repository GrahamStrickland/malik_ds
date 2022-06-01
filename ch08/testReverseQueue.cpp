//This is a driver program to test the function reverseQueue,
//which reverses a queue in place, using a stack.

#include <iostream>
#include "arrQueue.h"
#include "arrStack.h"

using namespace std;

template <class Type>
void reverseQueue(queueType<Type>& q);
    //Function to reverse the elements of a queue.
    //Postcondition: q has all elements rearranged in reverse order.

int main()
{
    int queueSize = 10;
    queueType<int> queue(queueSize);

    for (int i = 0; i < queueSize; i++)
        queue.addQueue(i);

    queueType<int> dummyQueue = queue;

    cout << "Before reverseQueue(queue), queue: ";
    for (int i = 0; i < queueSize; i++) {
        cout << dummyQueue.front() << ' ';
        dummyQueue.deleteQueue();
    }
    cout << endl;

    reverseQueue(queue);

    cout << "After reverseQueue(queue), queue: ";
    for (int i = 0; i < queueSize; i++) {
        cout << queue.front() << ' ';
        queue.deleteQueue();
    }
    cout << endl;

    return 0;
}

template <class Type>
void reverseQueue(queueType<Type>& q)
{
    stackType<Type> s;

    while (!q.isEmptyQueue())
    {
        s.push(q.front());
        q.deleteQueue();
    }

    while (!s.isEmptyStack())
    {
        q.addQueue(s.top());
        s.pop();
    }
}
