//***********************************************************
// Author: D.S. Malik
//
// class serverListType
// This class specifies the members to implement a list of
// servers.
//***********************************************************

#include "serverListType.h"

using namespace std;

serverListType::serverListType(int num)
{
    numOfServers = num;
    servers = new serverType[num];
}

serverListType::~serverListType()
{
    delete [] servers;
}

int serverListType::getFreeServerID() const
{
    int serverID = -1;

    for (int i = 0; i < numOfServers; i++)
        if (servers[i].isFree())
        {
            serverID = i;
            break;
        }
}

int serverListType::getNumberOfBusyServers() const
{
    int busyServers = 0;

    for (int i = 0; i < numOfServers; i++)
        if (!servers[i].isFree())
            busyServers++;

    return busyServers;
}

void serverListType::setServerBusy(int serverID,
                            customerType cCustomer, int tTime)
{
    servers[serverID].setBusy();
    servers[serverID].setTransactionTime(tTime);
    servers[serverID].setCurrentCustomer(cCustomer);
}

void serverListType::setServerBusy(int serverID,
                            customerType cCustomer)
{
    int time = cCustomer.getTransactionTime();

    servers[serverID].setBusy();
    servers[serverID].setTransactionTime(time);
    servers[serverID].setCurrentCustomer(cCustomer);
}

void serverListType::updateServers(ostream& outF)
{
    for (int i = 0; i < numOfServers; i++)
        if (!servers[i].isFree())
        {
            servers[i].decreaseTransactionTime();

            if (servers[i].getRemainingTransactionTime() == 0)
            {
                outF << "From server number " << (i + 1)
                     << " customer number "
                     << servers[i].getCurrentCustomerNumber()
                     << "\n     depareted at clock unit "
                     << servers[i].getCurrentCustomerArrivalTime()
                     + servers[i].getCurrentCustomerWaitingTime()
                     + servers[i].getCurrentCustomerTransactionTime()
                     << endl;
                servers[i].setFree();
            }
        }
}
