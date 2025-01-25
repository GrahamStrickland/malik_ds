#ifndef LINKED_STACK_TYPE_H
#define LINKED_STACK_TYPE_H

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operation on a stack as a
// linked list.
//*************************************************************

#include "stackADT.h"
#include <cassert>
#include <iostream>

using namespace std;

// Definition of the node
template <class Type> struct nodeType {
  Type info;
  nodeType<Type> *link;
};

template <class Type> class linkedStackType : public stackADT<Type> {
public:
  bool operator==(const linkedStackType<Type> &);
  // Overload the equality comparison operator.

  const linkedStackType<Type> &operator=(const linkedStackType<Type> &);
  // Overload the assignment operator.

  bool isEmptyStack() const;
  // Function to determine whether the stack is empty.
  // Postcondition: Returns true if the stack is empty;
  //   otherwise returns false.

  bool isFullStack() const;
  // Function to determine whether the stack is full.
  // Postcondition: Returns false.

  void initializeStack();
  // Function to initialize the stack to an empty state.
  // Postcondition: The stack elements are removed;
  //   stackTop = NULL;

  void push(const Type &newItem);
  // Function to add newItem to the stack.
  // Precondition: The stack exists and is not full.
  // Postcondition: The stack is changed and newItem is
  //   added to the top of the stack.

  Type top() const;
  // Function to return the top element of the stack.
  // Precondition: The stack exists and is not empty.
  // Postcondition: If the stack is empty, the program
  //   terminates; otherwise, the top element of
  //   the stack is returned.

  void pop();
  // Function to remove the top element of the stack.
  // Precondition: The stack exists and is not empty.
  // Postcondition: The stack is changed and the top
  //   element is removed from the stack.

  void reverseStack(linkedStackType<Type> &otherStack);
  // Function to copy the elements of calling stack onto
  //   otherStack in reverse order.
  // Postcondition: otherStack contains the elements of
  //   calling stack in reverse order.

  linkedStackType();
  // Default constructor
  // Postcondition: stackTop = NULL;

  linkedStackType(const linkedStackType<Type> &otherStack);
  // Copy constructor

  ~linkedStackType();
  // Destructor
  // Postcondition: All the elements of the stack are removed.

private:
  nodeType<Type> *stackTop; // pointer to the stack

  void copyStack(const linkedStackType<Type> &otherStack);
  // Function to make a copy of otherStack.
  // Postcondition: A copy of otherStack is created and
  //   assigned to this stack.
};

template <class Type>
bool linkedStackType<Type>::operator==(
    const linkedStackType<Type> &otherStack) {
  nodeType<Type> *current;
  nodeType<Type> *otherCurrent;

  current = stackTop;
  otherCurrent = otherStack.stackTop;

  while (current != NULL && otherCurrent != NULL) {
    if (current->info != otherCurrent->info)
      return false;
    else {
      current = current->link;
      otherCurrent = otherCurrent->link;
    }
  }

  if (otherCurrent != NULL || current != NULL)
    return false;

  return true;
}

template <class Type>
const linkedStackType<Type> &
linkedStackType<Type>::operator=(const linkedStackType<Type> &otherStack) {
  if (this != &otherStack) // avoid self-copy
    copyStack(otherStack);

  return *this;
} // end operator=

template <class Type> bool linkedStackType<Type>::isEmptyStack() const {
  return (stackTop == NULL);
} // end isEmptyStack

template <class Type> bool linkedStackType<Type>::isFullStack() const {
  return false;
} // end isFullStack

template <class Type> void linkedStackType<Type>::initializeStack() {
  nodeType<Type> *temp; // pointer to delete the node

  while (stackTop != NULL) // while there are elements in
                           // the stack

  {
    temp = stackTop; // set temp to point to the
                     // current node
    stackTop = stackTop->link; // advance stackTop to the
                               // next node
    delete temp; // deallocate memory occupied by temp
  }
} // end initializeStack

template <class Type> void linkedStackType<Type>::push(const Type &newElement) {
  nodeType<Type> *newNode; // pointer to create the new node

  newNode = new nodeType<Type>; // create the node

  newNode->info = newElement; // store newElement in the node
  newNode->link = stackTop;   // insert newNode before stackTop
  stackTop = newNode;         // set stackTop to point to the
                      // top node
} // end push

template <class Type> Type linkedStackType<Type>::top() const {
  assert(stackTop != NULL); // if stack is empty,
                            // terminate the program
  return stackTop->info; // return the top element
} // end top

template <class Type> void linkedStackType<Type>::pop() {
  nodeType<Type> *temp; // pointer to deallocate memory

  if (stackTop != NULL) {
    temp = stackTop; // set temp to point to the top node

    stackTop = stackTop->link; // advance stackTop to the
                               // next node
    delete temp; // delete the top node
  } else
    cout << "Cannot remove from an empty stack." << endl;
} // end pop

template <class Type>
void linkedStackType<Type>::reverseStack(linkedStackType<Type> &otherStack) {
  nodeType<Type> *current;
  nodeType<Type> *prevNode;
  nodeType<Type> *newNode;

  otherStack.initializeStack();

  current = stackTop;
  prevNode = NULL;

  while (current != NULL) {
    newNode = new nodeType<Type>;
    newNode->info = current->info;
    newNode->link = prevNode;
    prevNode = newNode;
    current = current->link;
  }

  otherStack.stackTop = newNode;
} // end reverseStack

template <class Type> linkedStackType<Type>::linkedStackType() {
  stackTop = NULL;
}

// copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(
    const linkedStackType<Type> &otherStack) {
  stackTop = NULL;
  copyStack(otherStack);
} // end copy constructor

// destructor
template <class Type> linkedStackType<Type>::~linkedStackType() {
  initializeStack();
} // end destructor

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> &otherStack) {
  nodeType<Type> *newNode, *current, *last;

  if (stackTop != NULL) // if stack is nonempty, make it empty
    initializeStack();

  if (otherStack.stackTop == NULL)
    stackTop = NULL;
  else {
    current = otherStack.stackTop; // set current to point
                                   // to the stack to be copied

    // copy the stackTop element of the stack
    stackTop = new nodeType<Type>; // create the node

    stackTop->info = current->info; // copy the info
    stackTop->link = NULL;          // set the link field to NULL
    last = stackTop;                // set last to point to the node
    current = current->link;        // set current to point to the
                             // next node
    // copy the remaining stack
    while (current != NULL) {
      newNode = new nodeType<Type>;

      newNode->info = current->info;
      newNode->link = NULL;
      last->link = newNode;
      last = newNode;
      current = current->link;
    } // end while
  } // end else
} // end copyStack

#endif // LINKED_STACK_TYPE_H
