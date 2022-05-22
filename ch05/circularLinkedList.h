#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

// This is the interface of the struct nodeType<Type>
// which represents a node in a circular linked list.

template <class Type>
struct nodeType
{
public:
    Type info;
    nodeType<Type> *link;
};

// This is the interface of the ADT circularLinkedList<Type>
// which creates a linked list where the last node points
// to the first node.

template <class Type>
class circularLinkedList
{
public:
    circularLinkedList& operator=(const circularLinkedList<Type>& otherList);
        // Overloaded assignment operator

    bool operator!=(const circularLinkedList<Type>& otherList) const;
        // Overloaded inequality comparison operator

    void initializeList();
        // Function to initialize the circular linked list.
        // Postcondition: first = NULL;

    bool isEmpty() const;
        // Function to check whether the circular linked list is empty.
        // Postcondition: Returned true if list is empty; otherwise false.

    void destroyList();
        // Function to destroy all nodes in the linked list.
        // Postcondition: first = NULL;

    void printList() const;
        // Function to print all nodes in the list to the console.
        // Postcondition: All nodes from first->link to first printed
        //  if list is empty, error message printed.

    int length() const;
        // Function to return the length of the circular linked list.
        // Postcondition: Returned count;

    bool searchList(const Type& searchItem) const;
        // Function to search the list for a given item.
        // Postcondition: Returned true if searchItem is in the list;
        //  otherwise false; error printed if list is empty.

    void insertNode(const Type& insertItem);
        // Function to insert a node into the list.
        // Postcondition: insertItem added to list in ascending sequential
        //  position.

    void deleteNode(const Type& deleteItem);
        // Function to delete a node from the list.
        // Postcondition: deleteItem removed from list; if deleteItem is
        //  not in list, error printed to console.


private:
};
#endif // CIRCULAR_LINKED_LIST_H
