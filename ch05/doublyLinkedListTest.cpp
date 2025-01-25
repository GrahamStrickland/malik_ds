// Driver program to test the ADT doublyLinkedList.
#include "doublyLinkedList.h"
#include <iostream>

using namespace std;

int main() {
  doublyLinkedList<int> list1;
  int num;

  cout << "Please enter a list of numbers for list1, "
       << "-999 to terminate list entry: ";
  cin >> num;
  while (num != -999) {
    list1.insert(num);
    cin >> num;
  }

  cout << "list1: ";
  list1.print();
  cout << endl << endl;

  cout << "list1 in reverse: ";
  list1.reversePrint();
  cout << endl << endl;

  cout << "Please enter an item to delete from the list: ";
  cin >> num;
  list1.deleteNode(num);

  cout << "list1: ";
  list1.print();
  cout << endl << endl;

  doublyLinkedList<int> list2;
  list2 = list1;

  cout << "After copying from list1, list2: ";
  list2.print();
  cout << endl << endl;

  return 0;
}
