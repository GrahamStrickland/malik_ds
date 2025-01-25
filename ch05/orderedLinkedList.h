#ifndef ORDERED_LINKED_LIST_H
#define ORDERED_LINKED_LIST_H

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an ordered linked list. This class is
// derived from the class linkedListType.
//***********************************************************

#include "linkedListType.h"

using namespace std;

template <class Type> class orderedLinkedList : public linkedListType<Type> {
public:
  bool search(const Type &searchItem) const;
  // Function to determine whether searchItem is in the list.
  // Postcondition: Returns true if searchItem is in the list,
  //   otherwise the value false is returned.

  void insert(const Type &newItem);
  // Function to insert newItem in the list.
  // Postcondition: first points to the new list, newItem
  //   is inserted at the proper place in the list, and
  //   count is incremented by 1.

  void insertFirst(const Type &newItem);
  // Function to insert newItem at the beginning of the list.
  // Postcondition: first points to the new list, newItem is
  //   inserted at the beginning of the list, last points to the
  //   last node in the list, and count is incremented by 1.

  void insertLast(const Type &newItem);
  // Function to insert newItem at the end of the list.
  // Postcondition: first points to the new list, newItem is
  //   inserted at the end of the list, last points to the
  //   last node in the list, and count is incremented by 1.

  void mergeLists(orderedLinkedList<Type> &list1,
                  orderedLinkedList<Type> &list2);
  // This function creates a new list by merging the
  // elements of list1 and list2.
  // Postcondition: first points to the merged list; list1
  //   and list2 are empty.

  void deleteNode(const Type &deleteItem);
  // Function to delete deleteItem from the list.
  // Postcondition: If found, the node containing deleteItem is
  //   deleted from the list; first points to the first node
  //   of the new list, and count is decremented by 1. If
  //   deleteItem is not in the list, an appropriate message
  //   is printed.

  void deleteAll(const Type &deleteItem);
  // Function to delete all nodes with given info from the list.
  // Postcondition: All occurrences of nodes with info == deletItem
  //   deleted from the list. first points to the first node,
  //   last points to the last node of the updated list,
  //   and count is decremented by 1.

  void deleteSmallest();
  // Function to delete the node with the smallest info in the list.
  // Postcondition: First occurrence of the node with smallest info
  //   in the list is deleted from the list. first points to the
  //   first node, last points to the last node of the updated list,
  //   and count is decremented by 1.

  void deleteItemAt(int k);
  // Function to delete the kth item in the list.
  // Precondition: k < count.
  // Postcondition: Returned the kth item in the list, terminated
  //   program if no such item exists.
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type &searchItem) const {
  bool found = false;
  nodeType<Type> *current; // pointer to traverse the list

  current = this->first; // start the search at the first node

  while (current != NULL && !found)
    if (current.getInfo() >= searchItem)
      found = true;
    else
      current = current.getLink();

  if (found)
    found = (current.getInfo() == searchItem); // test for equality

  return found;
} // end search

template <class Type>
void orderedLinkedList<Type>::insert(const Type &newItem) {
  nodeType<Type> *current;      // pointer to traverse the list
  nodeType<Type> *trailCurrent; // pointer just before current
  nodeType<Type> *newNode;      // pointer to create a node

  bool found;
  if (search(newItem) == true) {
    cout << "\nError: " << newItem << " already in list." << endl;
    return;
  }

  newNode = new nodeType<Type>; // create the node
  newNode.setInfo(newItem);     // store newItem in the node
  newNode.setLink(NULL);        // set the link field of the node
                         // to NULL
  if (this->first == NULL) // Case 1
  {
    this->first = newNode;
    this->last = newNode;
    this->count++;
  } else {
    current = this->first;
    found = false;

    while (current != NULL && !found) // search the list
      if (current.getInfo() >= newItem)
        found = true;
      else {
        trailCurrent = current;
        current = current.getLink();
      }

    if (current == this->first) // Case 2
    {
      newNode.setLink(this->first);
      this->first = newNode;
      this->count++;
    } else // Case 3
    {
      trailCurrent.setLink(newNode);
      newNode.setLink(current);

      if (current == NULL)
        this->last = newNode;

      this->count++;
    }
  } // end else
} // end insert

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type &newItem) {
  insert(newItem);
} // end insertFirst

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type &newItem) {
  insert(newItem);
} // end insertLast

template <class Type>
void orderedLinkedList<Type>::mergeLists(orderedLinkedList<Type> &list1,
                                         orderedLinkedList<Type> &list2) {
  this->initializeList();
  nodeType<Type> *current = list1.first; // pointer to traverse list1 & list2.

  while (current != list1.last) { // Add elements from list1.
    insert(current.getInfo());
    current = current.getLink();
  }
  if (list1.last != NULL)
    insert(list1.last.getInfo());
  list1.destroyList();

  current = list2.first;
  while (current != list2.last) { // Add elements from list2.
    insert(current.getInfo());
    current = current.getLink();
  }
  if (list2.last != NULL)
    insert(list2.last.getInfo());
  list2.destroyList();
} // end mergeLists

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type &deleteItem) {
  nodeType<Type> *current;      // pointer to traverse the list
  nodeType<Type> *trailCurrent; // pointer just before current
  bool found;

  if (this->first == NULL) // Case 1
    cout << "Cannot delete from an empty list." << endl;
  else {
    current = this->first;
    found = false;

    while (current != NULL && !found) // search the list
      if (current.getInfo() >= deleteItem)
        found = true;
      else {
        trailCurrent = current;
        current = current.getLink();
      }

    if (current == NULL) // Case 4
      cout << "The item to be deleted is not in the list." << endl;
    else if (current.getInfo() == deleteItem) // the item to be
                                              // deleted is in the list
    {
      if (this->first == current) // Case 2
      {
        this->first = this->first.getLink();

        if (this->first == NULL)
          this->last = NULL;

        delete current;
      } else // Case 3
      {
        trailCurrent.setLink(current.getLink());

        if (current == this->last)
          this->last = trailCurrent;

        delete current;
      }
      this->count--;
    } else // Case 4
      cout << "The item to be deleted is not in the "
           << "list." << endl;
  }
} // end deleteNode

template <class Type>
void orderedLinkedList<Type>::deleteAll(const Type &deleteItem) {
  nodeType<Type> *current;      // pointer to traverse the list
  nodeType<Type> *trailCurrent; // pointer just before current
  bool found;

  if (this->first == NULL)
    cout << "Cannot delete from an empty list." << endl;
  else {
    found = false;
    // Check if first node matches deleteItem.
    if (this->first.getInfo() == deleteItem) {
      found = true;
      current = this->first;
      this->first = this->first.getLink();
      this->count--;

      if (this->first == NULL) // the list has only one node
        this->last = NULL;

      delete current;
      current = this->first;
    }
    trailCurrent = this->first; // set trailCurrent to point
                                // to the first node
    current = this->first.getLink(); // set current to point to
                                     // the second node
    while (current != NULL) {
      if (current.getInfo() == deleteItem) {
        found = true;
        trailCurrent.setLink(current.getLink());
        this->count--;

        if (this->last == current) // node to be deleted was the
                                   // last node
          this->last = trailCurrent; // update the value of last
        delete current;              // delete the node from the list

        if (this->last != trailCurrent)
          current = trailCurrent.getLink(); // Reassign current for
                                            // next iteration.
      }
      trailCurrent = current;
      current = current.getLink();
    } // end while

    if (!found)
      cout << "The item to be deleted is not in "
           << "the list." << endl;
  } // end else
} // end deleteAll

template <class Type>
void orderedLinkedList<Type>::deleteSmallest() { // Assign 4 pointers for
                                                 // finding and deleting
                                                 // smallest node.
  nodeType<Type> *current;
  nodeType<Type> *trailCurrent;
  nodeType<Type> *smallest;
  nodeType<Type> *trailSmallest;

  if (this->first == NULL) // If list is empty.
    cout << "Cannot delete from an empty list." << endl;
  else // List is not empty.
  {
    smallest = this->first; // Assign smallest and update as necessary.
    current = this->first;  // Assign current and walk through list.

    while (current != NULL) { // Update smallest and trailing iterator.
      if (current.getInfo() < smallest.getInfo()) {
        smallest = current;
        trailSmallest = trailCurrent;
      } // No update; walk through list.
      else {
        trailCurrent = current;
        current = current.getLink();
      }
    }

    // Update pointers for deletion of node.
    if (this->first == smallest) {
      this->first = this->first.getLink();
      if (this->first == NULL) // If list has only one node.
        this->last = NULL;
    } else { // Otherwise, update link of previous node.
      // If smallest node is last.
      if (this->last == smallest)
        this->last = trailSmallest;
      trailSmallest.setLink(smallest.getLink());
    }

    // Decrement length of list and delete smallest node.
    this->count--;
    delete smallest;
  }
} // end deleteSmallest

template <class Type>
void orderedLinkedList<Type>::deleteItemAt(
    int k) { // Check if k is a valid index reference.
  assert(k < this->count);

  nodeType<Type> *current;
  nodeType<Type> *trailCurrent;

  if (k == 0) { // Delete first item.
    current = this->first;
    this->first = this->first.getLink();
    if (this->first == NULL) // If list has only one node.
      this->last = NULL;
    delete current;
  } else { // Delete item at index != 0.
    current = this->first;

    for (int i = 0; i < k; i++) {
      trailCurrent = current;
      current = current.getLink();
    }
    // Update link to remove current and decrement count.
    trailCurrent.setLink(current.getLink());

    if (this->last == current) // Check for last element in list.
      this->last = trailCurrent;
    delete current;
  }
  this->count--;
} // end deleteItemAt
#endif // ORDERED_LINKED_LIST_H
