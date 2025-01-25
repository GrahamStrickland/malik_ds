// Driver program to test function which prints strings backwards
// using recursion.

#include <iostream>
#include <string>

using namespace std;

void printBackwards(string str);
// Postcondition: str printed to console backwards.

int main() {
  string str;

  cout << "Please enter a string to be printed backwards: ";
  getline(cin, str);

  printBackwards(str);
  cout << endl;

  return 0;
}

void printBackwards(string str) {
  if (str.size() == 1)
    cout << str.at(0);
  else {
    printBackwards(str.substr(1, str.size() - 1));
    cout << str.at(0);
  }
}
