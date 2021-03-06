/* bst.h
   Jennifer Leopold
   Class definition for a BST
 */
#ifndef BST_H
#define BST_H

#include "bnode.h"
#include "binarytree.h"

template <class T>
class BST : public BinaryTree<T>
{
public:
  // Purpose: default constructor
  // Postconditions: (see BinaryTree default constructor)
  BST( ) {
    // automatically calls BinaryTree default constructor
  }
  
  // Purpose: destructor
  // Postconditions: (see BinaryTree default destructor)
  ~BST( ) { 
    // automatically calls BinaryTree destructor
  }
  
  // Purpose: determine whether or not a specified value is in this tree 
  // Parameters: x is specified value to be found
  // Returns: true if x is in this tree; otherwise, returns false
  bool find(const T& x) const;

  //Purpose:Find if x is located in the tree
  //Parameters:x is the specific value to be found. The nodePtr is specified
  //Returns: true if x is in this tree; otherwise, returns false
  bool findStartingAtNode(const T& x, BNode<T> *nodePtr) const;
  
  
  // Purpose: insert the specified value into this tree 
  // Parameters: x is value to be inserted
  // Postconditions: if x already exists in this tree, that node's count
  // is incremented; otherwise, a new node with data value x and count 1 
  // is added to this tree, and m_size is incremented
  void insert(const T& x);

  //Purpose: insert the specified value into the tree
  //Parameters: x is value to be inserted, nodePtr is a specified value
  //Postconditions: if x already exists in the tree, that node's count
  //is incremented. Otherwise, a new node with data value x and count 1
  //is added to the tree, and m_size is incremented
  void insertStartingAtNode(const T& x, BNode<T> *& nodePtr);
    
  // Purpose: determine whether or not this tree is equivalent to a 
  // specified tree 
  // Parameters: rhs is the tree to be compared to this tree
  // Returns: if the trees are exactly the same in terms of structure and
  // content, return true; otherwise, return false
  bool operator==(const BST<T>& rhs) const;
     
};

#include "bst.hpp"

#endif 

