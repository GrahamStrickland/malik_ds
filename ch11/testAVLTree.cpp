// This is a program to test the member functions
// of the ADT AVLTree.

#include "AVLTree.h"
#include <iostream>

void printParity(int &x);
// Helper function to print "Even" if x is even, or "Odd" if x is odd.

int main() {
  AVLTree<int> tree;

  // Test isEmpty().
  std::cout << "Before insert statements, tree is"
            << (tree.isEmpty() ? " " : " not ") << "empty.\n";

  // Test insert().
  tree.insert(40);
  tree.insert(30);
  tree.insert(20);
  tree.insert(60);
  tree.insert(50);
  tree.insert(80);
  tree.insert(15);
  tree.insert(28);
  tree.insert(25);

  // Test isEmpty().
  std::cout << "After insert statements, tree is"
            << (tree.isEmpty() ? " " : " not ") << "empty.\n\n";

  // Test treeHeight(), treeNodeCount(), treeLeavesCount() and singleParent().
  std::cout << "The tree has height " << tree.treeHeight() << " and contains "
            << tree.treeNodeCount() << " nodes and " << tree.treeLeavesCount()
            << " leaves.\n\n";

  // Test inorderTraversal().
  std::cout << "Inorder traversal of tree: ";
  tree.inorderTraversal();
  std::cout << "\nNon-recursive inorder traversal of tree: ";
  tree.nonRecursiveInTraversal();
  std::cout << "\nInorder parity traversal of tree: ";
  tree.inorderTraversal(printParity);
  std::cout << "\n\n";

  // Test preorderTraversal().
  std::cout << "Preorder traversal of tree: ";
  tree.preorderTraversal();
  std::cout << "\nNon-recursive preorder traversal of tree: ";
  tree.nonRecursivePreTraversal();
  std::cout << "\nPreorder parity traversal of tree: ";
  tree.preorderTraversal(printParity);
  std::cout << "\n\n";

  // Test postorderTraversal().
  std::cout << "Postorder traversal of tree: ";
  tree.postorderTraversal();
  std::cout << "\nNon-recursive postorder traversal of tree: ";
  tree.nonRecursivePostTraversal();
  std::cout << "\nPostorder parity traversal of tree: ";
  tree.postorderTraversal(printParity);
  std::cout << "\n\n";

  // Test search().
  int item = 48;
  std::cout << item << (tree.search(item) ? " is " : " is not ")
            << "in the tree.\n";
  item = 1;
  std::cout << item << (tree.search(item) ? " is " : " is not ")
            << "in the tree.\n\n";

  // Test copy constructor.
  AVLTree<int> newTree = tree;

  return EXIT_SUCCESS;
}

void printParity(int &x) { std::cout << (x % 2 == 0 ? "Even " : "Odd "); }