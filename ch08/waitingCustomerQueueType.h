#ifndef WAITING_CUSTOMER_QUEUE_TYPE_H
#define WAITING_CUSTOMER_QUEUE_TYPE_H

//************************************************************
// Author: D.S. Malik
//
// class waitingCustomerQueueType
// This class extends the class queueType to implement a list
// of waiting customers.
//************************************************************

#include "customerType.h"
#include <queue>

using namespace std;

class waitingCustomerQueueType : public queue<customerType> {
public:
  waitingCustomerQueueType();
  // Constructor

  void updateWaitingQueue();
  // Function to increment the waiting time of each
  // customer in the queue by one time unit.
};
#endif // WAITING_CUSTOMER_QUEUE_TYPE_H
