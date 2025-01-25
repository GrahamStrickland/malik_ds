// This is a driver program to test the member function
// shellSort() of the ADT arrayListType.

#include "arrayListType.h"

int main() {
  arrayListType<int> list;
  int num;

  // Input list from terminal and print list.
  std::cout << "Please enter a list of integers ending with -999: ";
  std::cin >> num;
  while (num != -999) {
    list.insert(num);
    std::cin >> num;
  }
  std::cout << "\nlist before shellSort(): ";
  list.print();
  std::cout << '\n';

  // Test shellSort() and print list again.
  list.shellSort();
  std::cout << "list after shellSort(): ";
  list.print();

  return 0;
}