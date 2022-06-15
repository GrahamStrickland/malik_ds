#ifndef CUSTOMER_TYPE_H
#define CUSTOMER_TYPE_H

//************************************************************
// Author: D.S. Malik
//
// class customerType
// This class specifies the members to implement a customer.
//************************************************************

class customerType
{
public:
    customerType(int cN = 0, int arrvTime = 0, int wTime = 0,
                 int tTime = 0);
        //Constructor to initialize the instance variables
        //according to the parameters
        //If no value is specified in the object declaration,
        //the default values are assigned.
        //Postcondition: customerNumber = cN; arrivalTime = arrvTime;
        //  waitingTime = wTime; transactionTime = tTime

    void setCustomerInfo(int cN = 0, int inTime = 0,
                         int wTime = 0, int tTime = 0);
        //Function to initialize the instance variables.
        //Instance variables are set according to the parameters.
        //Postcondition: customerNumber = cN; arrivalTime = arrvTime;
        //  waitingTime = wTime; transactionTime = tTime;

    int getWaitingTime() const;
        //Function to return the waiting time of a customer.
        //Postcondition: waitingTime = time;

    void setWaitingTime(int time);
        //Function to set the waiting time of a customer.
        //Postcondition: waitingTime = time;

    void incrementWaitingTime();
        //Function to increment the waiting time by one time unit.
        //Postcondition: waitingTime++;

    int getArrivalTime() const;
        //Function to return the arrival time of a customer.
        //Postcondition: The value of arrivalTime is returned.

    int getTransactionTime() const;
        //Function to return the transaction time of a customer.
        //Postcondition: The value of transactionTime is returned.
        
    int getCustomerNumber() const;
        //Function to return the customer number.
        //Postcondition: The value of customerNumber is returned.

private:
    int customerNumber;
    int arrivalTime;
    int waitingTime;
    int transactionTime;
};
#endif //CUSTOMER_TYPE_H
