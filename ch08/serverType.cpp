//************************************************************
// Author: D.S. Malik
//
// class serverType
// This class specifies the members to implement a server.
//************************************************************

#include "serverType.h"

using namespace std;

serverType::serverType() {
  status = "free";
  transactionTime = 0;
}

bool serverType::isFree() const { return (status == "free"); }

void serverType::setBusy() { status = "busy"; }

void serverType::setFree() { status = "free"; }

void serverType::setTransactionTime(int t) { transactionTime = t; }

void serverType::setTransactionTime() {
  int time;

  time = currentCustomer.getTransactionTime();

  transactionTime = time;
}

int serverType::getRemainingTransactionTime() const { return transactionTime; }

void serverType::decreaseTransactionTime() { transactionTime--; }

void serverType::setCurrentCustomer(customerType cCustomer) {
  currentCustomer = cCustomer;
}

int serverType::getCurrentCustomerNumber() const {
  return currentCustomer.getCustomerNumber();
}

int serverType::getCurrentCustomerArrivalTime() const {
  return currentCustomer.getArrivalTime();
}

int serverType::getCurrentCustomerWaitingTime() const {
  return currentCustomer.getWaitingTime();
}

int serverType::getCurrentCustomerTransactionTime() const {
  return currentCustomer.getTransactionTime();
}
