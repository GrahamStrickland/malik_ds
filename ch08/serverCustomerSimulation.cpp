//This is a simulation of a server/customer queueing system.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "serverListType.h"
#include "waitingCustomerQueueType.h"

using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers,
                             int& transTime, int& tBetweenCArrival);

void startTransaction();

void runSimulation();

int main() {
    runSimulation();
}

void setSimulationParameters(int& sTime, int& numOfServers,
                             int& transTime, int& tBetweenCArrival)
{
    cout << "Enter the simulation time: ";
    cin >> sTime;
    cout << endl;

    cout << "Enter the number of servers: ";
    cin >> numOfServers;
    cout << endl;

    cout << "Enter the transaction time: ";
    cin >> transTime;
    cout << endl;

    cout << "Enter the time between customers arrival: ";
    cin >> tBetweenCArrival;
    cout << endl;
}

void startTransaction()
{
    // 1. Remove the customer from the front of the queue.
    customer = customerQueue.front();
    customerQueue.deleteQueue();

    // 2. Update the total waiting time by adding the current
    // customer's waiting time to the previous total waiting time.
    totalWait = totalWait + customer.getWaitingTime();

    // 3. Set the free server to begin the transaction.
    serverList.setServerBusy(serverID, customer, transTime);
}

void runSimulation()
{
    // 1. Declare and initialize the variables such as the simulation parameters,
    // customer number, clock, total and average waiting times, number of
    // customers arrived, number of customers served, number of customers
    // left in the waiting queue, number of customers left with the servers,
    // waitingCustomerQueue, and a list of servers.
    int simulationTime, numOfServers, transTime, tBetweenCArrival, numOfCustomers = 0, 
        clock, totalWaitingTime = 0, avgWaitingTime = 0, numOfCustArrived = 0, 
        numOfCustServed = 0, numOfCustInQueue = 0, numOfCustAtServers = 0,
        serverID;
    double randomNumber = 0.0;
    bool customerArrives = false;
    setSimulationParameters(simulationTime, numOfServers, transTime, tBetweenCArrival);
    waitingCustomerQueueType queue;
    serverList servers(numOfServers);

    // Seed random number generator.
    srand(time(0));

    // 2.
    for (clock = 1; clock <= simulationTime; clock++)
    {
        // 2.1. Update the server list to decrement the transaction time of
        // each busy server by one time unit.
        servers.updateServers(cout);

        // 2.2. If the customer's queue is nonempty, increment the waiting
        // time of each customer by one time unit.
        if (!queue.isEmptyQueue())
            queue.updateWaitingQueue();

        // 2.3. If a customer arrives, increment the number of customers by 1
        // and add the new customer to the queue.
        randomNumber = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        if (randomNumber > exp(-(1.0 / static_cast<double>(tBetweenCArrival))))
        {
            numOfCustomers++;
            customerType cust(numOfCustomers, clock, 0, transTime);
            queue.addQueue(cust);
        }

        // 2.4. If a server is free and the customer's queue is nonempty,
        // remove a customer from the front of the queue and send
        // the customer to the free server
        serverID = servers.getFreeServerID();
        if (serverID)
            startTransaction(serverID);
    }

    // 3. Print the appropriate results. Your results must include the number of
    // customers left in the queue, the number of customers still with servers,
    // the number of customers arrived, and the number of customers who
    // actually completed a transaction.
}
