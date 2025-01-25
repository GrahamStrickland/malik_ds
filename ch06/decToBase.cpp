// Driver program to test function that takes a decimal number
// and a base and outputs the number converted to that base.
#include <cassert>
#include <iostream>

using namespace std;

void decToBase(int num, int base);
// Precondition: 2 <= base <= 36
// Postcondition: Output num in num_(base) notation

int main() {
  int decimalNum;
  int base;

  cout << "Enter number in decimal: ";
  cin >> decimalNum;
  cout << "Enter base for conversion: ";
  cin >> base;
  cout << endl;

  cout << '(' << decimalNum << ")_10 = (";
  decToBase(decimalNum, base);
  cout << ")_" << base << endl;

  return 0;
}

void decToBase(int num, int base) {
  int digit;

  assert(base >= 2 && base <= 36);

  if (num > 0) {
    decToBase(num / base, base);
    digit = num % base;
    if (0 <= digit && digit < 10)
      cout << digit;
    else
      cout << static_cast<char>(digit + 55);
  }
}
