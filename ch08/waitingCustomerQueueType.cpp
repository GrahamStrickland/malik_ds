//************************************************************
// Author: D.S. Malik
//
// class waitingCustomerQueueType
// This class extends the class queueType to implement a list
// of waiting customers.
//************************************************************

#include "waitingCustomerQueueType.h"

using namespace std;

waitingCustomerQueueType::waitingCustomerQueueType()
{
}

void waitingCustomerQueueType::updateWaitingQueue()
{
    customerType cust;

    cust.setWaitingTime(-1);
    int wTime = 0;

    push(cust);

    while (wTime != -1)
    {
        cust = front();
        pop();

        wTime = cust.getWaitingTime();
        if (wTime == -1)
            break;
        cust.incrementWaitingTime();
        push(cust);
    }
}
