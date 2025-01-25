// This program tests various operation of a linked list
// 34 62 21 90 66 53 88 24 10 -999

#include "unorderedLinkedList.h" //Line 2
#include <iostream>              //Line 1

using namespace std; // Line 3

int main()                                      // Line 4
{                                               // Line 5
  unorderedLinkedList<int> list1, list2, list3; // Line 6
  int num;                                      // Line 7

  cout << "Line 8: Enter integers ending "
       << "with -999" << endl; // Line 8
  cin >> num;                  // Line 9

  while (num != -999)      // Line 10
  {                        // Line 11
    list1.insertLast(num); // Line 12
    cin >> num;            // Line 13
  } // Line 14

  cout << endl; // Line 15

  cout << "Line 16: list1: ";                                     // Line 16
  list1.print();                                                  // Line 17
  cout << endl;                                                   // Line 18
  cout << "Line 19: Length of list1: " << list1.length() << endl; // Line 19

  list2 = list1; // test the assignment operator Line 20

  cout << "Line 21: list2: ";                                     // Line 21
  list2.print();                                                  // Line 22
  cout << endl;                                                   // Line 23
  cout << "Line 24: Length of list2: " << list2.length() << endl; // Line 24

  cout << "Line 25: Enter the number to be "
       << "deleted: "; // Line 25
  cin >> num;          // Line 26
  cout << endl;        // Line 27

  list2.deleteNode(num); // Line 28

  cout << "Line 29: After deleting " << num << " list2: " << endl; // Line 29
  list2.print();                                                   // Line 30
  cout << endl;                                                    // Line 31

  cout << "Line 32: Length of list2: " << list2.length() << endl; // Line 32

  cout << endl
       << "Line 33: Output list1 "
       << "using an iterator" << endl; // Line 33

  linkedListIterator<int> it; // Line 34

  for (it = list1.begin(); it != list1.end(); ++it) // Line 35
    cout << *it << " ";                             // Line 36
  cout << endl << endl;                             // Line 37

  cout << "Line 38: After deleting smallest "
       << "in list1:" << endl;                      // Line 38
  list1.deleteSmallest();                           // Line 39
  for (it = list1.begin(); it != list1.end(); ++it) // Line 40
    cout << *it << " ";                             // Line 41
  cout << endl << endl;                             // Line 42

  cout << "Line 43: Enter a value to be "
       << "deleted: ";  // Line 43
  cin >> num;           // Line 44
  list1.deleteAll(num); // Line 45
  cout << "After deleting all ocurrences of " << num
       << ", list1: " << endl;                      // Line 46
  for (it = list1.begin(); it != list1.end(); ++it) // Line 47
    cout << *it << " ";                             // Line 48
  cout << endl << endl;                             // Line 49

  cout << "Enter an index to delete: ";                    // Line 50
  cin >> num;                                              // Line 51
  list1.deleteItemAt(num);                                 // Line 52
  cout << "After deleting item at " << num << ", list1: "; // Line 53
  for (it = list1.begin(); it != list1.end(); ++it)        // Line 54
    cout << *it << " ";                                    // Line 55
  cout << endl << endl;                                    // Line 56

  cout << "After calling list1.divideMid(list2), "
       << "list1: ";                                // Line 57
  list1.divideMid(list2);                           // Line 58
  for (it = list1.begin(); it != list1.end(); ++it) // Line 59
    cout << *it << " ";                             // Line 60
  cout << "\nand list2: ";                          // Line 61
  for (it = list2.begin(); it != list2.end(); ++it) // Line 62
    cout << *it << " ";                             // Line 63
  cout << endl << endl;                             // Line 64

  cout << "Line 65: Enter integers ending "
       << "with -999" << endl; // Line 65
  cin >> num;                  // Line 66

  while (num != -999)      // Line 67
  {                        // Line 68
    list3.insertLast(num); // Line 69
    cin >> num;            // Line 70
  } // Line 71

  cout << endl; // Line 72

  cout << "Line 73: list3: "; // Line 73
  list3.print();              // Line 74
  cout << endl;               // Line 75

  cout << "Please enter an item at which to "
       << "split list3 (remainder stored in "
       << "list2): ";                               // Line 76
  cin >> num;                                       // Line 76
  list3.divideAt(list2, num);                       // Line 77
  for (it = list3.begin(); it != list3.end(); ++it) // Line 78
    cout << *it << " ";                             // Line 79
  cout << "\nand list2: ";                          // Line 80
  for (it = list2.begin(); it != list2.end(); ++it) // Line 81
    cout << *it << " ";
  cout << endl << endl;

  return 0; // Line 82
} // Line 83
