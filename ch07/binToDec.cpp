// This is a driver program to test a function that converts
// binary numbers to decimal using a stack.

#include <cassert>
#include <iostream>
#include <stack>

using namespace std;

int binToDec(int bin);
// Precondition: bin is an unsigned positive binary number.
// Postcondition: Returned decimal equivalent of bin.

int main() {
  int bin;

  cout << "Please enter a positive binary integer: ";
  cin >> bin;

  cout << '(' << bin << ")_2 = " << '(' << binToDec(bin) << ")_10" << endl;

  return 0;
}

int binToDec(int bin) {
  assert(bin > 0);

  stack<int> weighted;
  int exp, cur, dec = 0, weight = 0;

  // Add weights corresponding to 1 to stack.
  while (bin > 0) {
    assert(bin % 10 == 1 || bin % 10 == 0);
    if (bin % 10 == 1)
      weighted.push((weight));
    bin /= 10;
    weight += 1;
  }

  // Add 2^(weight) to decimal number for each weight in stack.
  while (!weighted.empty()) {
    for (exp = weighted.top(), cur = 1; exp > 0; exp--)
      cur *= 2;
    dec += cur;
    weighted.pop();
  }

  return dec;
}
