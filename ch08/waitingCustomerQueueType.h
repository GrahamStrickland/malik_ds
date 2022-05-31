#ifndef WAITING_CUSTOMER_QUEUE_TYPE_H
#define WAITING_CUSTOMER_QUEUE_TYPE_H

//************************************************************
// Author: D.S. Malik
//
// class waitingCustomerQueueType
// This class extends the class queueType to implement a list
// of waiting customers.
//************************************************************

#include "arrQueue.h"
#include "customerType.h"

class waitingCustomerQueueType: public queueType<customerType>
{
public:
    waitingCustomerQueueType(int size = 100);
        //Constructor
        //Postcondition: The queue is initialized according to the
        //  parameter size. The value of size is passed to the
        //  constructor of queueType.

    void updateWaitingQueue();
        //Function to increment the waiting time of each
        //customer in the queue by one time unit.
};
#endif //WAITING_CUSTOMER_QUEUE_TYPE_H
