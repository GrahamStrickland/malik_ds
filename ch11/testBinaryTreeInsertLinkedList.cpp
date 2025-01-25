// This is a driver program to test the function
// binaryTreeInsertLinkedList which takes a binary
// tree and inserts its nodes into a linked list.

#include "binarySearchTree.h"

#include <iostream>

int main() {
  bSearchTreeType<int> tree;
  orderedLinkedList<int> list;

  tree.insert(40);
  tree.insert(30);
  tree.insert(70);
  tree.insert(5);
  tree.insert(16);
  tree.insert(82);
  tree.insert(95);
  tree.insert(100);
  tree.insert(73);
  tree.insert(54);
  tree.insert(98);
  tree.insert(37);
  tree.insert(25);
  tree.insert(62);
  tree.insert(81);
  tree.insert(150);
  tree.insert(79);
  tree.insert(87);

  std::cout << "Inorder traversal of tree before call to "
            << "binaryTreeInsertLinkedList:\n";
  tree.inorderTraversal();
  std::cout << "\n\n";

  list = tree.binaryTreeInsertLinkedList();

  std::cout << "Linked list after call to "
            << "binaryTreeInsertLinkedList:\n";
  list.print();
  std::cout << "\n";

  return EXIT_SUCCESS;
}