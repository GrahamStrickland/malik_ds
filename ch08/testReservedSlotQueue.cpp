// This is a driver program to test the ADT queueType
// implemented as an array with a reserved slot.

#include "reservedSlotQueue.h"
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
  cout << endl;

  return 0;
}
