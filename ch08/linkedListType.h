#ifndef LINKED_LIST_TYPE_H
#define LINKED_LIST_TYPE_H

#include <cassert>
#include <iostream>

using namespace std;

//**********************************************
// Author: D.S. Malik
//
// This is the interface for the class nodeType
// to be used in an ADT for a linked list.
//**********************************************

template <class Type> class nodeType {
public:
  const nodeType<Type> &operator=(const nodeType<Type> &);
  // Overload the assignment operator.

  void setInfo(const Type &elem);
  // Function to set the info of the node.
  // Postcondition: info = elem;

  Type getInfo() const;
  // Function to return the info of the node.
  // Postcondition: The value of info is returned.

  void setLink(nodeType<Type> *ptr);
  // Function to set the link of the node.
  // Postcondition: link = ptr;

  nodeType<Type> *getLink() const;
  // Function to return the link of the node.
  // Postcondition: The value of link is returned.

  nodeType();
  // Default constructor
  // Postcondition: link = NULL;

  nodeType(const Type &elem, nodeType<Type> *ptr);
  // Constructor with parameters
  // Sets info point to the object elem points to and
  // link is set to point to the object ptr points to.
  // Postcondition: info = elem; link = ptr

  nodeType(const nodeType<Type> &otherNode);
  // Copy constructor

  ~nodeType();
  // Destructor

private:
  Type info;
  nodeType<Type> *link;
};

template <class Type>
const nodeType<Type> &
nodeType<Type>::operator=(const nodeType<Type> &rightNode) {
  if (this != &rightNode) // avoid self-assignment
  {
    info = rightNode.info;
    assert(rightNode != NULL); // if unable to allocate memory,
                               // terminate program
    link = rightNode.link;
  }

  return *this; // return the object assigned
}

template <class Type> void nodeType<Type>::setInfo(const Type &elem) {
  info = elem;
}

template <class Type> Type nodeType<Type>::getInfo() const { return info; }

template <class Type> void nodeType<Type>::setLink(nodeType<Type> *ptr) {
  link = ptr;
}

template <class Type> nodeType<Type> *nodeType<Type>::getLink() const {
  return link;
}

template <class Type> nodeType<Type>::nodeType() { link = NULL; }

template <class Type>
nodeType<Type>::nodeType(const Type &elem, nodeType<Type> *ptr) {
  info = elem;
  link = ptr;
}

template <class Type>
nodeType<Type>::nodeType(const nodeType<Type> &otherNode) {
  info = otherNode.info;
  link = otherNode.link;
}

template <class Type> nodeType<Type>::~nodeType() { delete link; }

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement an iterator
// to a linked list.
//***********************************************************

template <class Type> class linkedListIterator {
public:
  linkedListIterator();
  // Default constructor
  // Postcondition: current = NULL;

  linkedListIterator(nodeType<Type> *ptr);
  // Constructor with a paremeter.
  // Postcondition: current = ptr;

  Type operator*();
  // Function to overload the dereferencing operator *.
  // Postcondition: Returns the info contained in the node.

  linkedListIterator<Type> operator++();
  // Overload the preincrement operator.
  // Postcondition: The iterator is advanced to the next node.

  bool operator==(const linkedListIterator<Type> &right) const;
  // Overload the equality operator.
  // Postcondition: Returns true if this iterator is equal to
  //   the iterator specified by right, otherwise it returns
  //   false.

  bool operator!=(const linkedListIterator<Type> &right) const;
  // Overload the not equal to operator.
  // Postcondition: Returns true if this iterator is not equal to
  //   the iterator specified by right, otherwise it returns
  //   false.

private:
  nodeType<Type> *current; // pointer to point to the current
                           // node in the linked list
};

template <class Type> linkedListIterator<Type>::linkedListIterator() {
  this->current.setLink(NULL);
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr) {
  current = ptr;
}

template <class Type> Type linkedListIterator<Type>::operator*() {
  return this->current.getInfo();
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
  current = this->current.getLink();

  return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(
    const linkedListIterator<Type> &right) const {
  return (this->current.getInfo() == this->right.current.getInfo() &&
          this->current.getLink() == this->right.current.getLink());
}

template <class Type>
bool linkedListIterator<Type>::operator!=(
    const linkedListIterator<Type> &right) const {
  return (this->current.getInfo() != this->right.current.getInfo() ||
          this->current.getLink() != this->right.current.getLink());
}

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of a linked list. This is an abstract class.
// We cannot instantiate an object of this class.
//***********************************************************

template <class Type> class linkedListType {
public:
  const linkedListType<Type> &operator=(const linkedListType<Type> &);
  // Overload the assignment operator.

  void initializeList();
  // Initialize the list to an empty state.
  // Postcondition: first = NULL, last = NULL, count = 0;

  bool isEmptyList() const;
  // Function to determine whether the list is empty.
  // Postcondition: Returns true if the list is empty, otherwise
  //   it returns false.

  void print() const;
  // Function to output the data contained in each node.
  // Postcondition: none

  int length() const;
  // Function to return the number of nodes in the list.
  // Postcondition: The value of count is returned.

  void destroyList();
  // Function to delete all the nodes from the list.
  // Postcondition: first = NULL, last = NULL, count = 0;

  Type front() const;
  // Function to return the first element of the list.
  // Precondition: The list must exist and must not be empty.
  // Postcondition: If the list is empty, the program terminates;
  //   otherwise, the first element of the list is returned.

  Type back() const;
  // Function to return the last element of the list.
  // Precondition: The list must exist and must not be empty.
  // Postcondition: If the list is empty, the program
  //                terminates; otherwise, the last
  //                element of the list is returned.

  virtual bool search(const Type &searchItem) const = 0;
  // Function to determine whether searchItem is in the list.
  // Postcondition: Returns true if searchItem is in the list.
  //   otherwise te value false is returned.

  virtual void insertFirst(const Type &newItem) = 0;
  // Function to insert newItem at the beginning of the list.
  // Postcondition: first points to the new list, newItem is
  //   inserted at the beginning of the list, last points to
  //   the last node in the list, and count is incremented by
  //   1.

  virtual void insertLast(const Type &newItem) = 0;
  // Function to insert newItem at the end of the list.
  // Postcondition: first points to the new list, newItem is
  //   inserted at the end of the list, last points to the
  //   last node in the list, and count is incremented by 1.

  virtual void deleteNode(const Type &deleteItem) = 0;
  // Function to delete deleteItem from the list.
  // Postcondition: If found, the node containing deleteItem is
  //   deleted from the list. first points to the first node,
  //   last points to the last node of the updated list, and
  //   count is decremented by 1.

  virtual void deleteAll(const Type &deleteItem) = 0;
  // Function to delete all nodes with given info from the list.
  // Postcondition: All occurrences of nodes with info == deletItem
  //   deleted from the list. first points to the first node,
  //   last points to the last node of the updated list,
  //   and count is decremented by 1.

  virtual void deleteSmallest() = 0;
  // Function to delete the node with the smallest info in the list.
  // Postcondition: First occurrence of the node with smallest info
  //   in the list is deleted from the list. first points to the
  //   first node, last points to the last node of the updated list,
  //   and count is decremented by 1.

  virtual void deleteItemAt(int k) = 0;
  // Function to delete the kth item in the list.
  // Precondition: k < count.
  // Postcondition: Returned the kth item in the list, terminated
  //   program if no such item exists.

  void divideMid(linkedListType<Type> &sublist);
  // This operation divides the given list into two sublists
  // of (almost) equal sizes.
  // Postcondition: first points to the first node and last
  //   points to the last node of the first sublist.
  //   sublist.first points to the first node and sublist.last
  //   points to the last node of the second sublist.

  void divideAt(linkedListType<Type> &secondList, const Type &item);
  // Divide the list at the node with the info item into two
  // sublists.
  // Postcondition: first and last point to the first and last
  //   nodes of the first sublist.
  //   secondList.first and secondList.last point to the
  //   first and last nodes of the second sublist.

  linkedListIterator<Type> begin();
  // Function to return an iterator at the beginning of the
  // linked list.
  // Postcondition: Returns an iterator such that current is set
  //   to first.

  linkedListIterator<Type> end();
  // Function to return an iterator one element past the
  // last element of the linked list.
  // Postcondition: Returns an iterator such that current is set
  //   to NULL.

  linkedListType();
  // default constructor
  // Initializes the list to an empty state.
  // Postcondition: first = NULL, last = NULL, count = 0;

  linkedListType(const linkedListType<Type> &otherList);
  // copy constructor

  ~linkedListType();
  // destructor
  // Deletes all the nodes from the list.
  // Postcondition: The list object is destroyed.

protected:
  int count;             // variable to store the number of elements in the list
  nodeType<Type> *first; // pointer to the first node of the list
  nodeType<Type> *last;  // pointer to the last node of the list

private:
  void copyList(const linkedListType<Type> &otherList);
  // Function to make a copy of otherList.
  // Postcondition: A copy of otherList is created and assigned
  //   to this list.
};

// overload the assignment operator
template <class Type>
const linkedListType<Type> &
linkedListType<Type>::operator=(const linkedListType<Type> &otherList) {
  if (this != &otherList) // avoid self-copy
  {
    copyList(otherList);
  } // end else

  return *this;
}

template <class Type> void linkedListType<Type>::initializeList() {
  destroyList(); // if the list has any nodes, delete them
}

template <class Type> bool linkedListType<Type>::isEmptyList() const {
  return (first == NULL);
}

template <class Type> void linkedListType<Type>::print() const {
  nodeType<Type> *current; // pointer to traverse the list

  current = first;        // set current pointer to the first node
  while (current != NULL) // while more data to print
  {
    cout << this->current.getInfo() << " ";
    current = this->current.getLink();
  }
} // end print

template <class Type> void linkedListType<Type>::destroyList() {
  nodeType<Type> *temp; // pointer to deallocate the memory
                        // occupied by the node
  while (first != NULL) // while there are nodes in the list
  {
    temp = first;                  // set temp to the current node
    first = this->first.getLink(); // advance first to the next node
    delete temp;                   // deallocate the memory occupied by temp
  }

  last = NULL; // initialize last to NULL; first has already
               // been set to NULL by the while loop
  count = 0;
}

template <class Type> int linkedListType<Type>::length() const { return count; }

template <class Type> Type linkedListType<Type>::front() const {
  assert(first != NULL);

  return this->first.getInfo(); // return the info of the first node
} // end front

template <class Type> Type linkedListType<Type>::back() const {
  assert(last != NULL);

  return this->last.getInfo(); // return the info of the last node
} // end back

template <class Type>
void linkedListType<Type>::divideMid(
    linkedListType<Type> &sublist) { // Check that sublist is empty.
  sublist.initializeList();

  // Node to walk through list.
  nodeType<Type> *current;

  // Calculate middle index of list.
  int mid = (count % 2 == 0) ? (count / 2) - 1 : count / 2;
  int currentIndex = 0;

  if (first != NULL) // List not empty.
  {
    current = first;
    if (current != last) // List has more than one element.
    {                    // Update location of pointers.
      while (currentIndex < mid) {
        current = this->current.getLink();
        currentIndex++;
      }

      // Update last element of list and first of sublist.
      last = current;
      if (current->link != NULL) {
        sublist.first = this->current.getLink();
        current = this->current.getLink();
        currentIndex++;
      }
      this->last.setLink(NULL);

      // Move through until last.
      while (currentIndex < count - 1) {
        current = this->current.getLink();
        currentIndex++;
        sublist.count++;
      }

      // Update first and last for sublist.
      if (current != NULL)
        sublist.last = current;
      else {
        sublist.first = NULL;
        sublist.last = NULL;
      }

      // Update count value.
      count = mid + 1;
    } // end else
  } // end if
} // end divideMid

template <class Type>
void linkedListType<Type>::divideAt(linkedListType<Type> &secondList,
                                    const Type &item) {
  // Nodes to walk through list.
  nodeType<Type> *current;
  nodeType<Type> *trailCurrent;

  // Search for index of item to divide at.
  int currentIndex = 0, total = count;

  if (first != NULL) { // List not empty.
    current = first;

    while (current->info != item && currentIndex < total - 1) {
      trailCurrent = current;
      current = this->current.getLink();
      currentIndex++;
    }

    if (current == first) {        // First node == item.
      secondList.initializeList(); // Check that secondList is empty.
      count = 1;

      if (this->current.getLink() != NULL) { // More than one node in list.
        last = current;
        count--;
        secondList.first = this->current.getLink();
        secondList.count++;
        current = this->current.getLink();
        currentIndex++;
        this->last.setLink(NULL);
      } else
        last = first;
    } else if (current != last) {  // First node != item.
      secondList.initializeList(); // Check that secondList is empty.
      secondList.first = this->current.getLink();
      secondList.count++;
      if (this->current.getLink() == NULL) {
        last = current;
        this->last.setLink(NULL);
        secondList.last = current;
      } else {
        last = current;
        current = this->current.getLink();
        currentIndex++;
        this->last.setLink(NULL);
        count--;
      }
    } else if (current == last && this->last.getInfo() == item)
      secondList.initializeList();
    else
      cout << item << " not found in list." << endl;

    // Walk through list for secondList through until secondList.last.
    if (current == secondList.first) {
      while (currentIndex < total - 1) {
        current = this->current.getLink();
        currentIndex++;
        secondList.count++;
      }

      // Update first and last for sublist.
      if (current != NULL)
        secondList.last = current;
      else {
        secondList.first = NULL;
        secondList.last = NULL;
      }
    } // end if
  } else
    cout << "Cannot delete from an empty list." << endl;
} // end divideAt

template <class Type> linkedListIterator<Type> linkedListType<Type>::begin() {
  linkedListIterator<Type> temp(first);

  return temp;
}

template <class Type> linkedListIterator<Type> linkedListType<Type>::end() {
  linkedListIterator<Type> temp(NULL);

  return temp;
}

template <class Type>
linkedListType<Type>::linkedListType() // default constructor
{
  first = NULL;
  last = NULL;
  count = 0;
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type> &otherList) {
  first = NULL;
  copyList(otherList);
} // end copy constructor

template <class Type>
linkedListType<Type>::~linkedListType() // destructor
{
  destroyList();
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type> &otherList) {
  nodeType<Type> *newNode; // pointer to create a node
  nodeType<Type> *current; // pointer to traverse the list

  if (first != NULL) // if the list is nonempty, make it empty
    destroyList();

  if (otherList.first == NULL) // otherList is empty
  {
    first = NULL;
    last = NULL;
    count = 0;
  } else {
    current = otherList.first; // current points to the
                               // list to be copied
    count = otherList.count;

    // copy the first node
    first = new nodeType<Type>;                   // create the node
    this->first.setInfo(this->current.getInfo()); // copy the info
    this->first.setLink(NULL);         // set the link field of the node to NULL
    last = first;                      // make last point to the first node
    current = this->current.getLink(); // make current point to the next
                                       //   node
    // copy the remaining list
    while (current != NULL) {
      newNode = new nodeType<Type>;                   // create a node
      this->newNode.setInfo(this->current.getInfo()); // copy the info
      this->newNode.setLink(NULL); // set the link of newNode to NULL
      this->last.setLink(newNode); // attach newNode after last
      last = newNode;              // make last point to the actual last
                      // node
      current = this->current.getLink(); // make current point to the
                                         // next node
    } // end while
  } // end else
} // end copylist
#endif // LINKED_LIST_TYPE_H
