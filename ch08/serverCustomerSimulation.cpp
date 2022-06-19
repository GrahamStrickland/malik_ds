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

void runSimulation()
{
    // 1. Declare and initialize the variables such as the simulation parameters,
    // customer number, clock, total and average waiting times, number of
    // customers arrived, number of customers served, number of customers
    // left in the waiting queue, number of customers left with the servers,
    // waitingCustomerQueue, and a list of servers.
    int simulationTime, numOfServers, transTime, tBetweenCArrival, numOfCustomers = 0, 
        clock = 0, totalWaitingTime = 0, numOfCustArrived = 0, numOfCustServed = 0, 
        numOfCustInQueue = 0, numOfCustAtServers = 0, serverID, served = 0;
    double randomNumber = 0.0, avgWaitingTime = 0.0;
    setSimulationParameters(simulationTime, numOfServers, transTime, tBetweenCArrival);
    waitingCustomerQueueType queue;
    serverListType servers(numOfServers);
    customerType cust(numOfCustomers, clock, 0, transTime);

    // Seed random number generator.
    srand(time(0));

    // 2.
    for (clock = 1; clock <= simulationTime; clock++)
    {
        // 2.1. Update the server list to decrement the transaction time of
        // each busy server by one time unit.
        served = servers.updateServers(cout);
        numOfCustServed += served;
        numOfCustAtServers -= served;

        // 2.2. If the customer's queue is nonempty, increment the waiting
        // time of each customer by one time unit.
        if (!queue.isEmptyQueue())
            queue.updateWaitingQueue();

        // 2.3. If a customer arrives, increment the number of customers by 1
        // and add the new customer to the queue.
        randomNumber = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        if (randomNumber > exp(-(1.0 / static_cast<double>(tBetweenCArrival)))
                && !queue.isFullQueue())
        {
            cust.setCustomerInfo(numOfCustomers, clock, 0, transTime);
            queue.addQueue(cust);
            cout << "Customer number " << numOfCustomers + 1 << " arrived at time unit " 
                 << clock << endl;
            numOfCustomers++;
            numOfCustArrived++;
            numOfCustInQueue++;
        }

        // 2.4. If a server is free and the customer's queue is nonempty,
        // remove a customer from the front of the queue and send
        // the customer to the free server
        serverID = servers.getFreeServerID();
        if (serverID != -1 && !queue.isEmptyQueue()) {
            // 2.4.1. Remove the customer from the front of the queue.
            cust = queue.front();
            queue.deleteQueue();

            // 2.4.2. Update the total waiting time by adding the current
            // customer's waiting time to the previous total waiting time.
            totalWaitingTime = totalWaitingTime + cust.getWaitingTime();

            // 2.4.3. Set the free server to begin the transaction.
            servers.setServerBusy(serverID, cust, transTime);
            numOfCustAtServers++;
            numOfCustInQueue--;
        }
    }

    // 3. Print the appropriate results. Your results must include the number of
    // customers left in the queue, the number of customers still with servers,
    // the number of customers arrived, and the number of customers who
    // actually completed a transaction.
    int custWaitingTime = 0;
    while (!queue.isEmptyQueue()) {
        cust = queue.front();
        custWaitingTime = cust.getWaitingTime();
        if (custWaitingTime > 0)
            totalWaitingTime += custWaitingTime;
        queue.deleteQueue();
    }
    avgWaitingTime = static_cast<double>(totalWaitingTime) / 
                     static_cast<double>(numOfCustomers);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << endl << "The simulation ran for " << simulationTime << " time units"
         << endl << "Number of servers: " << numOfServers << endl << "Average "
         << "transaction time: " << transTime << endl << "Average arrival time "
         << "difference between customers: " << tBetweenCArrival << endl
         << "Total waiting time: " << totalWaitingTime << endl << "Number of customers "
         << "that completed a transaction: " << numOfCustServed << endl
         << "Number of customers left at the servers: " << numOfCustAtServers << endl
         << "Number of customers left in the queue: " << numOfCustInQueue << endl
         << "Average waiting time: " << avgWaitingTime << endl
         << "************** END SIMULATION **************" << endl;
}
