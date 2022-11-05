//This is a driver program to test the ADT binarySearchTree.

#include "binarySearchTree.h"
#include <iostream>

void printParity(int& x);
//Helper function to print "Even" if x is even, or "Odd" if x is odd.

int main()
{
    //Test constructor.
    bSearchTreeType<int> tree;

    //Test isEmpty().
    std::cout << "Before insert statements, tree is" 
              << (tree.isEmpty() ? " " : " not ") << "empty.\n";

    //Test insert() member function.
    tree.insert(60);
    tree.insert(50);
    tree.insert(30);
    tree.insert(35);
    tree.insert(32);
    tree.insert(40);
    tree.insert(48);
    tree.insert(45);
    tree.insert(53);
    tree.insert(57);
    tree.insert(70);
    tree.insert(80);
    tree.insert(75);
    tree.insert(77);

    //Test isEmpty().
    std::cout << "After insert statements, tree is" 
              << (tree.isEmpty() ? " " : " not ") << "empty.\n\n";

    //Test treeNodeCount(), treeLeavesCount() and singleParent().
    std::cout << "tree contains " << tree.treeNodeCount() << " nodes, "
              << tree.treeLeavesCount() << " leaves, and "
              << tree.singleParent() << " nodes with only one child.\n\n";

    //Test inorderTraversal().
    std::cout << "Inorder traversal of tree: ";
    tree.inorderTraversal();
    std::cout << '\n';
    tree.inorderTraversal(printParity);
    std::cout << "\n\n";

    //Test preorderTraversal().
    std::cout << "Preorder traversal of tree: ";
    tree.preorderTraversal();
    std::cout << '\n';
    tree.preorderTraversal(printParity);
    std::cout << "\n\n";

    //Test postorderTraversal().
    std::cout << "Postorder traversal of tree: ";
    tree.postorderTraversal();
    std::cout << '\n';
    tree.postorderTraversal(printParity);
    std::cout << "\n\n";

    //Test swapSubtrees().
    std::cout << "Before swapSubtrees, inorder "
              << "traversal of tree:\n";
    tree.inorderTraversal();
    std::cout << '\n';
    tree.swapSubtrees();
    std::cout << "After swapSubtrees, inorder "
              << "traversal of tree:\n";
    tree.inorderTraversal();
    std::cout << "\n\n";

    return EXIT_SUCCESS;
}

void printParity(int& x)
{
    std::cout << (x % 2 == 0 ? "Even " : "Odd ");
}
