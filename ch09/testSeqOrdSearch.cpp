// This is a driver program to test the member function seqOrdSearch()
// of the ADT orderedArrayListType.

#include "orderedArrayListType.h"
#include <string>

int main() {
  orderedArrayListType<int> list;
  int item = 0, loc = 0;

  // Add items to list and print.
  list.insertOrd(159);
  list.insertOrd(9);
  list.insertOrd(65);
  list.insertOrd(15);
  list.insertOrd(102);
  list.insertOrd(371);
  list.insertOrd(20);
  list.insertOrd(205);
  list.insertOrd(4);
  list.insertOrd(35);
  list.insertOrd(98);

  std::cout << "list: ";
  list.print();
  std::cout << '\n';

  // Test list.seqOrdSearch().
  item = 3;
  loc = list.seqOrdSearch(item);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");
  item = 4;
  loc = list.seqOrdSearch(item);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");
  item = 98;
  loc = list.seqOrdSearch(item);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");
  item = 400;
  loc = list.seqOrdSearch(item);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");
  item = 5;
  loc = list.seqOrdSearch(item);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");
  item = 100;
  loc = list.seqOrdSearch(item);
  std::cout << "Item " << item
            << (loc == -1 ? " does not occur in list.\n"
                          : " occurs at position " + std::to_string(loc) +
                                " in list.\n");

  return 0;
}
