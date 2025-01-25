// This is a driver program to test the member function
// recursiveBinarySearch() of the ADT orderedArrayListType.

#include "orderedArrayListType.h"
#include <string>

int main() {
  orderedArrayListType<int> list;
  int item, first = 0, last, loc = 0;

  // Add items to list.
  list.insertOrd(4);
  list.insertOrd(8);
  list.insertOrd(19);
  list.insertOrd(25);
  list.insertOrd(34);
  list.insertOrd(39);
  list.insertOrd(45);
  list.insertOrd(48);
  list.insertOrd(66);
  list.insertOrd(75);
  list.insertOrd(89);
  list.insertOrd(95);

  // Print items in list.
  std::cout << "list: ";
  list.print();
  std::cout << '\n';

  // Test recursiveBinarySearch().
  item = 4;
  last = list.listSize();
  loc = list.recursiveBinarySearch(item, first, last);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");
  item = 100;
  first = 0;
  last = list.listSize();
  loc = list.recursiveBinarySearch(item, first, last);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");
  item = 39;
  first = 0;
  last = list.listSize();
  loc = list.recursiveBinarySearch(item, first, last);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");
  item = 1000;
  first = 0;
  last = list.listSize();
  loc = list.recursiveBinarySearch(item, first, last);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");

  return 0;
}
