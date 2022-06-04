//This is a driver program to test the ADT queueType.

#include <iostream>
#include "arrQueue.h"

using namespace std;

int main() {
    //Test queueType constructors.
    queueType<int> queue1;
    queueType<int> queue2(50);

    //Test addQueue() and deleteQueue().
    queue1.addQueue(2);
    queue1.addQueue(58);
    queue1.addQueue(36);
    queue1.deleteQueue();
    queue1.addQueue(61);

    //Test assignment operator.
    queue2 = queue1;

    // Output queue1 and test isEmptyQueue() and front()
    cout << "queue1: ";
    while (!queue1.isEmptyQueue()) {
        cout << queue1.front() << ' ';
        queue1.deleteQueue();
    }
    cout << endl;
    
    //Test queueCount().
    cout << "queue1.queueCount() = " << queue1.queueCount() << endl;
    cout << "queue2.queueCount() = " << queue2.queueCount() << endl;
    
    return 0;
}
