#ifndef AVL_TREE_H
#define AVL_TREE_H

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations to implement an
// AVL (height-balanced) tree.
//*************************************************************

#include "arrStack.h"

// Definition of the node
template <class elemType> struct AVLNode {
  elemType info;
  int bfactor; // balance factor
  AVLNode<elemType> *llink;
  AVLNode<elemType> *rlink;
};

template <class elemType> class AVLTree {
public:
  const AVLTree<elemType> &operator=(const AVLTree<elemType> &);
  // Overload the assignment operator.

  bool isEmpty() const;
  // Returns true if the AVL tree is empty;
  // otherwise, returns false.

  void insert(const elemType &newItem);
  // Creates a node, stores the info in the node, and calls
  // the function insertIntoAVL to isnert the new node in
  // the AVL tree.

  void inorderTraversal() const;
  // Function to do an inorder traversal of the AVL tree.

  void inorderTraversal(void (*visit)(elemType &));
  // Function to do an inorder traversal of the AVL tree.
  // The parameter visit, which is a function, specifies the
  // action to be taken at each node.

  void preorderTraversal() const;
  // Function to do a preorder traversal of the AVL tree.

  void preorderTraversal(void (*visit)(elemType &));
  // Function to do a preorder traversal of the AVL tree.
  // The parameter visit, which is a function, specifies the
  // action to be taken at each node.

  void postorderTraversal() const;
  // Function to do a postorder traversal of the AVL tree.

  void postorderTraversal(void (*visit)(elemType &));
  // Function to do a postorder traversal of the AVL tree.
  // The parameter visit, which is a function, specifies the
  // action to be taken at each node.

  void nonRecursiveInTraversal() const;
  // Function to do a non-recursive inorder traversal of the
  //   AVL tree.

  void nonRecursivePreTraversal() const;
  // Function to do a non-recursive preorder traversal of the
  //   AVL tree.

  void nonRecursivePostTraversal() const;
  // Function to do a non-recursive postorder traversal of the
  //   AVL tree.

  bool search(const elemType &searchItem) const;
  // Function to determine if searchItem is in the AVL tree.
  // Postcondition: Returns true if searchItem is found in
  //   AVL tree; otherwise, returns false.

  void destroyTree();
  // Deallocates the memory space occupied by the AVL tree.
  // Postcondition: root = NULL;

  int treeHeight() const;
  // Returns the height of the AVL tree.

  int treeNodeCount() const;
  // Returns the number of nodes in the AVL tree.

  int treeLeavesCount() const;
  // Returns the number of leaves in the AVL tree.

  AVLTree(const AVLTree<elemType> &otherTree);
  // Copy constructor

  AVLTree();
  // Default constructor

  ~AVLTree();
  // Destructor

private:
  AVLNode<elemType> *root;

  void copyTree(AVLNode<elemType> *&copiedTreeRoot,
                AVLNode<elemType> *otherTreeRoot);
  // Makes a copy of the AVL tree to which
  // otherTreeRoot points. The pointer copiedTreeRoot
  // points to the root of the copied AVL tree.

  void destroy(AVLNode<elemType> *&p);
  // Function to destroy the tree to which p points.
  // Postcondition: p = NULL

  void inorder(AVLNode<elemType> *p) const;
  // Function to do an inorder traversal of the AVL
  // tree to which p points.

  void inorder(AVLNode<elemType> *p, void (*visit)(elemType &));
  // Function to do an inorder traversal of the AVL
  // tree, starting at the node specified by the parameter p.
  // The parameter visit, which is a function, specifies the
  // action to be taken at each node.

  void preorder(AVLNode<elemType> *p) const;
  // Function to do a preorder traversal of the AVL
  // tree to which p points.

  void preorder(AVLNode<elemType> *p, void (*visit)(elemType &));
  // Function to do a preorder traversal of the AVL
  // tree, starting at the node specified by the parameter p.
  // The parameter visit, which is a function, specifies the
  // action to be taken at each node.

  void postorder(AVLNode<elemType> *p) const;
  // Function to do a postorder traversal of the AVL
  // tree to which p points.

  void postorder(AVLNode<elemType> *p, void (*visit)(elemType &));
  // Function to do a postorder traversal of the AVL
  // tree, starting at the node specified by the parameter p.
  // The parameter visit, which is a function, specifies the
  // action to be taken at each node.

  void insertIntoAVL(AVLNode<elemType> *&root, AVLNode<elemType> *newNode,
                     bool &isTaller);
  // Inserts newNode into the AVLTree.

  void balanceFromLeft(AVLNode<elemType> *&root);
  // Function to balance the tree with given root from the left.

  void balanceFromRight(AVLNode<elemType> *&root);
  // Function to balance the tree with given root from the right.

  void rotateToLeft(AVLNode<elemType> *&root);
  // Function to rotate the AVL tree with given root to the left.

  void rotateToRight(AVLNode<elemType> *&root);
  // Function to rotate the AVL tree with given root to the right.

  int max(int x, int y) const;
  // Returns the larger of x and y.

  int height(AVLNode<elemType> *p) const;
  // Function to return the height of the AVL tree
  // to which p points.

  int nodeCount(AVLNode<elemType> *p) const;
  // Function to return the number of nodes in the
  // AVL tree to which p points.

  int leavesCount(AVLNode<elemType> *p) const;
  // Function to return the number of leaves in the
  // AVL tree to which p points.
};

// overloading the assignment operator
template <class elemType>
const AVLTree<elemType> &
AVLTree<elemType>::operator=(const AVLTree<elemType> &otherTree) {
  if (this != &otherTree) // avoid self-copy
  {
    if (this->root != NULL) // if the AVL tree is not empty,
                            // destroy the AVL tree.
      destroy(this->root);

    if (otherTree.root == NULL) // otherTree is empty
      this->root = NULL;
    else
      copyTree(this->root, otherTree.root);
  } // end else

  return *this;
}

template <class elemType> bool AVLTree<elemType>::isEmpty() const {
  return (this->root == NULL);
}

template <class elemType>
void AVLTree<elemType>::insert(const elemType &newItem) {
  bool isTaller = false;
  AVLNode<elemType> *newNode;

  newNode = new AVLNode<elemType>;
  newNode->info = newItem;
  newNode->bfactor = 0;
  newNode->llink = NULL;
  newNode->rlink = NULL;

  insertIntoAVL(root, newNode, isTaller);
}

template <class elemType> void AVLTree<elemType>::inorderTraversal() const {
  inorder(root);
}

template <class elemType>
void AVLTree<elemType>::inorderTraversal(void (*visit)(elemType &item)) {
  inorder(this->root, *visit);
}

template <class elemType> void AVLTree<elemType>::preorderTraversal() const {
  preorder(this->root);
}

template <class elemType>
void AVLTree<elemType>::preorderTraversal(void (*visit)(elemType &item)) {
  preorder(this->root, *visit);
}

template <class elemType> void AVLTree<elemType>::postorderTraversal() const {
  postorder(this->root);
}

template <class elemType>
void AVLTree<elemType>::postorderTraversal(void (*visit)(elemType &item)) {
  postorder(this->root, *visit);
}

template <class elemType>
void AVLTree<elemType>::nonRecursiveInTraversal() const {
  stackType<AVLNode<elemType> *> stack;
  AVLNode<elemType> *current;
  current = this->root;

  while ((current != NULL) || (!stack.isEmptyStack()))
    if (current != NULL) {
      stack.push(current);
      current = current->llink;
    } else {
      current = stack.top();
      stack.pop();
      std::cout << current->info << " ";
      current = current->rlink;
    }
}

template <class elemType>
void AVLTree<elemType>::nonRecursivePreTraversal() const {
  stackType<AVLNode<elemType> *> stack;
  AVLNode<elemType> *current;

  current = this->root;

  while ((current != NULL) || (!stack.isEmptyStack()))
    if (current != NULL) {
      std::cout << current->info << " ";
      stack.push(current);
      current = current->llink;
    } else {
      current = stack.top();
      stack.pop();
      current = current->rlink;
    }
}

template <class elemType>
void AVLTree<elemType>::nonRecursivePostTraversal() const {
  stackType<AVLNode<elemType> *> nodeStack;
  stackType<int> intStack;
  AVLNode<elemType> *current;
  int v = 0;

  current = this->root;

  if (current == NULL)
    std::cout << "The AVL tree is empty.\n";
  else {
    nodeStack.push(current);
    intStack.push(1);
    current = current->llink;

    while (!nodeStack.isEmptyStack())
      if (current != NULL && v == 0) {
        nodeStack.push(current);
        intStack.push(1);
        current = current->llink;
      } else {
        current = nodeStack.top();
        v = intStack.top();
        nodeStack.pop();
        intStack.pop();
        if (v == 1) {
          nodeStack.push(current);
          intStack.push(2);
          current = current->rlink;
          v = 0;
        } else
          std::cout << current->info << " ";
      }
  }
}

template <class elemType>
bool AVLTree<elemType>::search(const elemType &searchItem) const {
  AVLNode<elemType> *current;
  bool found = false;

  if (this->root == NULL)
    std::cerr << "Cannot search an empty tree.\n";
  else {
    current = this->root;

    while (current != NULL && !found) {
      if (current->info == searchItem)
        found = true;
      else if (current->info > searchItem)
        current = current->llink;
      else
        current = current->rlink;
    } // end while
  } // end else

  return found;
} // end search

template <class elemType> void AVLTree<elemType>::destroyTree() {
  destroy(this->root);
}

template <class elemType> int AVLTree<elemType>::treeHeight() const {
  return height(this->root);
}

template <class elemType> int AVLTree<elemType>::treeNodeCount() const {
  return nodeCount(this->root);
}

template <class elemType> int AVLTree<elemType>::treeLeavesCount() const {
  return leavesCount(this->root);
}

// copy constructor
template <class elemType>
AVLTree<elemType>::AVLTree(const AVLTree<elemType> &otherTree) {
  if (otherTree.root == NULL) // otherTree is empty
    this->root = NULL;
  else
    copyTree(this->root, otherTree.root);
}

template <class elemType> AVLTree<elemType>::AVLTree() { this->root = NULL; }

// destructor
template <class elemType> AVLTree<elemType>::~AVLTree() { destroy(this->root); }

template <class elemType>
void AVLTree<elemType>::copyTree(AVLNode<elemType> *&copiedTreeRoot,
                                 AVLNode<elemType> *otherTreeRoot) {
  if (otherTreeRoot == NULL)
    copiedTreeRoot = NULL;
  else {
    copiedTreeRoot = new AVLNode<elemType>;
    copiedTreeRoot->info = otherTreeRoot->info;
    copiedTreeRoot->bfactor = otherTreeRoot->bfactor;
    copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
    copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
  }
}

template <class elemType>
void AVLTree<elemType>::destroy(AVLNode<elemType> *&p) {
  if (p != NULL) {
    destroy(p->llink);
    destroy(p->rlink);
    delete p;
    p = NULL;
  }
}

template <class elemType>
void AVLTree<elemType>::inorder(AVLNode<elemType> *p) const {
  if (p != NULL) {
    inorder(p->llink);
    std::cout << p->info << " ";
    inorder(p->rlink);
  }
}

template <class elemType>
void AVLTree<elemType>::inorder(AVLNode<elemType> *p,
                                void (*visit)(elemType &item)) {
  if (p != NULL) {
    inorder(p->llink, *visit);
    (*visit)(p->info);
    inorder(p->rlink, *visit);
  }
}

template <class elemType>
void AVLTree<elemType>::preorder(AVLNode<elemType> *p) const {
  if (p != NULL) {
    std::cout << p->info << " ";
    preorder(p->llink);
    preorder(p->rlink);
  }
}

template <class elemType>
void AVLTree<elemType>::preorder(AVLNode<elemType> *p,
                                 void (*visit)(elemType &item)) {
  if (p != NULL) {
    (*visit)(p->info);
    inorder(p->llink, *visit);
    inorder(p->rlink, *visit);
  }
}

template <class elemType>
void AVLTree<elemType>::postorder(AVLNode<elemType> *p) const {
  if (p != NULL) {
    postorder(p->llink);
    postorder(p->rlink);
    std::cout << p->info << " ";
  }
}

template <class elemType>
void AVLTree<elemType>::postorder(AVLNode<elemType> *p,
                                  void (*visit)(elemType &item)) {
  if (p != NULL) {
    postorder(p->llink, *visit);
    postorder(p->rlink, *visit);
    (*visit)(p->info);
  }
}

template <class elemType>
void AVLTree<elemType>::insertIntoAVL(AVLNode<elemType> *&root,
                                      AVLNode<elemType> *newNode,
                                      bool &isTaller) {
  if (root == NULL) {
    root = newNode;
    isTaller = true;
  } else if (root->info == newNode->info)
    std::cerr << "No duplicates are allowed.\n";
  else if (root->info > newNode->info) // newItem goes in
                                       // the left subtree
  {
    insertIntoAVL(root->llink, newNode, isTaller);

    if (isTaller) // after insertion, the subtree grew in height
      switch (root->bfactor) {
      case -1:
        balanceFromLeft(root);
        isTaller = false;
        break;

      case 0:
        root->bfactor = -1;
        isTaller = true;
        break;

      case 1:
        root->bfactor = 0;
        isTaller = false;
        break;
      } // end switch
  } // end else if
  else {
    insertIntoAVL(root->rlink, newNode, isTaller);

    if (isTaller) // after insertion, the subtree grew in height
      switch (root->bfactor) {
      case -1:
        root->bfactor = 0;
        isTaller = false;
        break;

      case 0:
        root->bfactor = 1;
        isTaller = true;
        break;

      case 1:
        balanceFromRight(root);
        isTaller = false;
        break;
      } // end switch
  } // end else
} // end insertIntoAVL

template <class elemType>
void AVLTree<elemType>::balanceFromLeft(AVLNode<elemType> *&root) {
  AVLNode<elemType> *p;
  AVLNode<elemType> *w;

  p = root->llink; // p points to the left subtree of root

  switch (p->bfactor) {
  case -1:
    root->bfactor = 0;
    p->bfactor = 0;
    rotateToRight(root);
    break;

  case 0:
    std::cerr << "Error: Cannot balance from the left.\n";
    break;

  case 1:
    w = p->rlink;
    switch (w->bfactor) // adjust the balance factors
    {
    case -1:
      root->bfactor = 1;
      p->bfactor = 0;
      break;

    case 0:
      root->bfactor = 0;
      p->bfactor = 0;
      break;

    case 1:
      root->bfactor = 0;
      p->bfactor = -1;
      break;
    } // end switch

    w->bfactor = 0;
    rotateToLeft(p);
    root->llink = p;
    rotateToRight(root);
  } // end switch
} // end balanceFromLeft

template <class elemType>
void AVLTree<elemType>::balanceFromRight(AVLNode<elemType> *&root) {
  AVLNode<elemType> *p;
  AVLNode<elemType> *w;

  p = root->rlink; // p points to the left subtree of root

  switch (p->bfactor) {
  case -1:
    w = p->llink;
    switch (w->bfactor) // adjust the balance factors
    {
    case -1:
      root->bfactor = 0;
      p->bfactor = 1;
      break;

    case 0:
      root->bfactor = 0;
      p->bfactor = 0;
      break;

    case 1:
      root->bfactor = -1;
      p->bfactor = 0;
      break;
    } // end switch

    w->bfactor = 0;
    rotateToRight(p);
    root->rlink = p;
    rotateToLeft(root);
    break;

  case 0:
    std::cerr << "Error: Cannot balance from the left.\n";
    break;

  case 1:
    root->bfactor = 0;
    p->bfactor = 0;
    rotateToLeft(root);
  } // end switch
} // end balanceFromRight

template <class elemType>
void AVLTree<elemType>::rotateToLeft(AVLNode<elemType> *&root) {
  AVLNode<elemType> *p; // pointer to the root of the
                        // right subtree of root
  if (root == NULL)
    std::cerr << "Error in the tree.\n";
  else if (root->rlink == NULL)
    std::cerr << "Error in the tree:"
              << " No right subtree to rotate.\n";
  else {
    p = root->rlink;
    root->rlink = p->llink; // the left subtree of p becomes
                            // the right subtree of root
    p->llink = root;
    root = p; // make p the new root node
  }
} // end rotateToLeft

template <class elemType>
void AVLTree<elemType>::rotateToRight(AVLNode<elemType> *&root) {
  AVLNode<elemType> *p; // pointer to the root of
                        // the left subtree of root

  if (root == NULL)
    std::cerr << "Error in the tree.\n";
  else if (root->llink == NULL)
    std::cerr << "Error in the tree:"
              << " No left subtree to rotate.\n";
  else {
    p = root->llink;
    root->llink = p->rlink; // the right subtree of p becomes
                            // the left subtree of root
    p->rlink = root;
    root = p; // make p the new root node
  }
} // end rotateRight

template <class elemType> int AVLTree<elemType>::max(int x, int y) const {
  if (x >= y)
    return x;
  else
    return y;
}

template <class elemType>
int AVLTree<elemType>::height(AVLNode<elemType> *p) const {
  if (p == NULL)
    return 0;
  else
    return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int AVLTree<elemType>::nodeCount(AVLNode<elemType> *p) const {
  if (p == NULL)
    return 0;
  else
    return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template <class elemType>
int AVLTree<elemType>::leavesCount(AVLNode<elemType> *p) const {
  if (p == NULL)
    return 0;
  if (p->llink == NULL && p->rlink == NULL)
    return 1;
  return leavesCount(p->llink) + leavesCount(p->rlink);
}
#endif // AVL_TREE_H