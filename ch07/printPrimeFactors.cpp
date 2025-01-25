// This is a driver program to test the function printPrimeFactors
// that prints all prime factors of a positive integer in descending
// order.

#include <cassert>
#include <iostream>
#include <stack>

using namespace std;

void printPrimeFactors(int num);
// Precondition: num > 0;
// Postcondition: Printed all prime factors of num to console in
//  descending order.

bool isPrime(int num);
// Precondition: num > 0;
// Postcondition: Returned true if num is prime, otherwise false.

int main() {
  int num;

  cout << "Please enter a positive integer: ";
  cin >> num;

  printPrimeFactors(num);

  return 0;
}

void printPrimeFactors(int num) {
  assert(num > 0);

  stack<int> primeStack;
  int current = 1;

  while (current <= num) {
    if (isPrime(current))
      primeStack.push(current);
    current++;
  }

  while (!primeStack.empty()) {
    cout << primeStack.top() << " ";
    primeStack.pop();
  }
}

bool isPrime(int num) {
  assert(num > 0);

  int current = num / 2;

  while (current > 1) {
    if (num % current == 0)
      return false;
    else
      current--;
  }

  return true;
}
