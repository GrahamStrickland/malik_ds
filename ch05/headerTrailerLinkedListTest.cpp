// This is a driver program for the ADT headerTrailerLinkedList

#include "headerTrailerLinkedList.h"
#include <iostream>

using namespace std;

int main() {
  headerTrailerLinkedList<int> list1;
  int num;

  cout << "Please enter a list of numbers followed by -999: ";
  cin >> num;

  while (num != -999) {
    list1.insertNode(num);
    cin >> num;
  }

  cout << endl << "list1: ";
  list1.print();
  cout << "\nlist1 has length " << list1.length() << endl << endl;

  headerTrailerLinkedList<int> list2(-1000, 1000);

  list2 = list1;

  cout << "After assignment to list1, list2 = ";
  list2.print();
  cout << endl << endl;

  cout << "Please enter a number to delete from list2: ";
  cin >> num;
  list2.deleteNode(num);
  cout << "After deleting " << num << ", list2: ";
  list2.print();
  cout << endl << endl;

  cout << "Please enter a number to insert into list2: ";
  cin >> num;
  list2.insertNode(num);
  cout << "After inserting " << num << ", list2: ";
  list2.print();
  cout << endl << endl;

  cout << "Please enter a number to search for in list2: ";
  cin >> num;
  cout << num << (list2.search(num) ? " is in list2." : " not in list2.");
  cout << endl << endl;

  return 0;
}
