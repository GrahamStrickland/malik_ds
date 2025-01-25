// This is a driver program to test the ADT queueType.

#include "arrQueue.h"
#include <iostream>

using namespace std;

int main() {
  // Test queueType constructors.
  queueType<int> queue1;
  queueType<int> queue2(50);

  // Test addQueue() and deleteQueue().
  queue1.addQueue(2);
  queue1.addQueue(58);
  queue1.addQueue(36);
  queue1.deleteQueue();
  queue1.addQueue(61);

  // Test assignment operator.
  queue2 = queue1;

  // Output queue1 and test isEmptyQueue() and front()
  cout << "queue1: ";
  while (!queue1.isEmptyQueue()) {
    cout << queue1.front() << ' ';
    queue1.deleteQueue();
  }
  cout << endl << endl;

  // Test queueCount().
  queue1 = queue2;
  cout << "queue1.queueCount() = " << queue1.queueCount() << endl;

  // Test initializeQueue().
  queue1.initializeQueue();

  // Test moveNthFront().
  cout << endl;
  queue1.addQueue(5);
  queue1.addQueue(11);
  queue1.addQueue(34);
  queue1.addQueue(67);
  queue1.addQueue(43);
  queue1.addQueue(55);
  queue2 = queue1;
  cout << "queue1 before moveNthFront(3): ";
  while (!queue1.isEmptyQueue()) {
    cout << queue1.front() << ' ';
    queue1.deleteQueue();
  }
  cout << endl;
  queue1 = queue2;
  queue1.moveNthFront(3);
  cout << "queue1 after moveNthFront(3): ";
  while (!queue1.isEmptyQueue()) {
    cout << queue1.front() << ' ';
    queue1.deleteQueue();
  }
  cout << endl;

  return 0;
}
