//*************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use selection sort in a
// program.
//*************************************************************

#include "arrayListType.h"
#include <iostream>

int main() {
  arrayListType<int> list;
  int num;

  std::cout << "Line 8: Enter numbers ending with -999\n";

  std::cin >> num;

  while (num != -999) {
    list.insert(num);
    std::cin >> num;
  }

  std::cout << "Line 15: The list before sorting:\n";
  list.print();
  std::cout << '\n';

  list.selectionSort();

  std::cout << "Line 19: The list after sorting:\n";
  list.print();
  std::cout << '\n';

  return 0;
}