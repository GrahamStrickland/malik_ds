//************************************************************
// Author: D.S. Malik
//
// class customerType
// This class specifies the members to implement a customer.
//************************************************************

#include "customerType.h"

using namespace std;

customerType::customerType(int cN, int arrvTime,
                           int wTime, int tTime)
{
    setCustomerInfo(cN, arrvTime, wTime, tTime);
}

void customerType::setCustomerInfo(int cN, int arrvTime,
                                   int wTime, int tTime)
{
    customerNumber = cN;
    arrivalTime = arrvTime;
    waitingTime = wTime;
    transactionTime = tTime;
}

int customerType::getWaitingTime() const
{
    return waitingTime;
}

void customerType::incrementWaitingTime()
{
    waitingTime++;
}
