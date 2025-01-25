// This is a driver program to test the ADT linkedQueueType.

#include "linkedQueue.h"
#include <iostream>

using namespace std;

int main() {
  // Test linkedQueueType constructors.
  linkedQueueType<int> queue1, queue2;

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
  cout << endl;

  // Test queueCount().
  queue1 = queue2;
  cout << "queue1.queueCount() = " << queue1.queueCount() << endl;

  return 0;
}
