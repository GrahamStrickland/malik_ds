#ifndef SERVER_LIST_TYPE_H
#define SERVER_LIST_TYPE_H

//***********************************************************
// Author: D.S. Malik
//
// class serverListType
// This class specifies the members to implement a list of
// servers.
//***********************************************************

#include <iostream>
#include <fstream>
#include "serverType.h"

class serverListType
{
public:
    serverListType(int num = 1);
        //Constructor to initialize a list of servers
        //Postcondition: numOfServers = num
        //  A list of servers, specified by num, is created and
        //  each server is initialized to "free".

    ~serverListType();
        //Destructor
        //Postcondition: The list of servers is destroyed.

    int getFreeServerID() const;
        //Function to search the list of servers.
        //Postcondition: If a free server is found, returns its ID;
        //  otherwise, returns -1.

    int getNumberOfBusyServers() const;
        //Function to return the number of busy servers.
        //Postcondition: The number of busy servers is returned.

    void setServerBusy(int serverID, customerType cCustomer,
                       int tTime);
        //Function to set a server busy.
        //Postcondition: The server specified by serverId is set to
        //  "busy", to serve the customer specified by cCustomer,
        //  and the transaction time is set according to the
        //  parameter tTime.

    void setServerBusy(int serverID, customerType cCustomer);
        //Function to set a server busy.
        //Postcondition: The server specified by serverID is set to
        //  "busy", to serve the customer specified by cCustomer.

    void updateServers(ostream& outFile);
        //Function to update the status of a server.
        //Postcondition: The transaction time of each busy server
        //  is decremented by one unit. If the transaction time of
        //  a busy server is reduced to zero, the server is set to
        //  "free". Moreover, if the actual parameter corresponding
        //  to outFile is cout, a message indicating which customer
        //  has been served is printed on the screen, together with the
        //  customer's departing time. Otherwise, the output is sent
        //  to a file specified by the user.

private:
    int numOfServers;
    serverType *servers;
};
#endif //SERVER_LIST_TYPE_H
