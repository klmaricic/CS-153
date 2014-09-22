/*  binaryTree.h
    Jennifer Leopold
    Class definition for a binary tree
 */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "bnode.h"

template <class T>
class BinaryTree
{
protected:
  BNode<T> *m_root;       // root of tree
  unsigned int m_size;    // number of nodes in tree

public:
  // Purpose: default constructor
  // Postconditions: root is set to NULL and size is set to 0
  BinaryTree( ) : m_root(NULL), m_size(0) { }
  
  // Purpose: destructor
  // Postconditions: root is set to NULL, size is set to 0, and memory
  // used for nodes in this tree is deallocated (all done via clear)
  ~BinaryTree( ) { clear(); }
  
  // Purpose: determine whether or not this tree is empty
  // Returns: returns true if this tree is empty; otherwise, returns false
  bool isEmpty() const { return m_size == 0; }
  
  // Purpose: accessor function for the current size of this tree (# nodes)
  // Returns: current size of this tree (# nodes)
  const unsigned int size() const { return m_size; }
 
  // Purpose: accessor function for the root of this tree 
  // Returns: root of this tree
  BNode<T>*& getRoot() { return m_root; }
  
  // Purpose: clear this tree
  // Postconditions: tree's root is set to NULL, size is set to 0, and memory
  // used for nodes in this tree is deallocated 
  void clear( )
  {
    clearStartingAtNode(m_root);
    m_root = NULL;
  }
  
  //Purpose: Recursively clears out the tree
  //Postconditions:The tree's root is set to NULL, size is set to 0, and memory
  //used for nodes in this tree is deallocated
  void clearStartingAtNode(BNode<T> *& rootPtr)
  {
    if(rootPtr != NULL)
    {
      clearStartingAtNode(rootPtr->m_left);
      clearStartingAtNode(rootPtr->m_right);
      delete rootPtr;
      rootPtr=NULL;
      m_size--;
    }
  }
  
  // Purpose: determine whether or not this tree is equivalent to a 
  // specified tree 
  // Parameters: rhs is the tree to be compared to this tree
  // Returns: if the trees are exactly the same in terms of structure and
  // content, return true; otherwise, return false
  bool operator==(const BinaryTree<T>& rhs) const {
  // Note: could instead use toStringPostorder, but
  // toStringInorder shouldn't be used here
    return(toStringPreorder() == rhs.toStringPreorder() &&
            toStringInorder() == rhs.toStringInorder() &&
            toStringPostorder() == rhs.toStringPostorder());
  }
  
  // Purpose: construct a string that specifies each node's value and count,
  // as the nodes would be encountered in an inorder traversal of this tree
  // starting from the root
  // Returns: a string that specifies each node's value and count,
  // as the nodes would be encountered in an inorder traversal of this tree
  std::string toStringInorder() const {
    std::string s = "";
    toStringInorderStartingAtNode(s, m_root);
    return(s);
  } 
  
  // Purpose:Constructs a string that specifies each node's value and count,
  // as the nodes would be encountered in an postorder traversal of this tree
  // starting from the root
  // Returns: a string that specifies each node's value and count,
  // as the nodes would be encountered in an inorder traversal of this tree
  std::string toStringPostorder() const 
  {
    std::string s = "";
    toStringPostorderStartingAtNode(s, m_root);
    return(s);
  }
                            
  // Purpose: Constructs a string that specifies each node's value and count,
  // as the nodes would be encountered in an preorder traversal of this tree
  // starting from the root
  // Returns: a string that specifies each node's value and count,
  // as the nodes would be encountered in an inorder traversal of this tree
  std::string toStringPreorder() const 
  {
    std::string s = "";
    toStringPreorderStartingAtNode(s, m_root);
    return(s);
  }
  
  private: 
  
  // Purpose: construct a string that specifies the value and count of each
  // node in this tree, in the order that the nodes would be encountered in an 
  // inorder traversal starting from the specified node
  // Parameters: string to be constructed (passed-by-reference) and
  // ptr to the node from which to start the traversal
  // Returns: a string that specifies each node's value and count,
  // as the nodes would be encountered in an inorder traversal of this tree
  // starting from the specified node
  void toStringInorderStartingAtNode(std::string& s, BNode<T>* nodePtr) const {
    if (nodePtr != NULL) {
      toStringInorderStartingAtNode(s, nodePtr->m_left);
      if (s.length() > 0) s = s + ", ";
      s = s + nodePtr->toString();
      toStringInorderStartingAtNode(s, nodePtr->m_right);
    }
  }
  
  // Purpose: Constructs a string that specifies the value and count of each
  // node in this tree, in the order that the nodes would be encountered in an 
  // postorder traversal starting from the specified node
  // Parameters: string to be constructed (passed-by-reference) and
  // ptr to the node from which to start the traversal
  // Returns: a string that specifies each node's value and count,
  // as the nodes would be encountered in a postorder traversal of this tree
  // starting from the specified node
  void toStringPostorderStartingAtNode(std::string& s, BNode<T>* nodePtr) const
  {
    if (nodePtr != NULL) 
    {
      toStringPostorderStartingAtNode(s, nodePtr->m_left);
      toStringPostorderStartingAtNode(s, nodePtr->m_right);
      if (s.length() > 0) s = s + ", ";
        s = s + nodePtr->toString();
    }
  }
  
  // Purpose: construct a string that specifies the value and count of each
  // node in this tree, in the order that the nodes would be encountered in an 
  // preorder traversal starting from the specified node
  // Parameters: string to be constructed (passed-by-reference) and
  // ptr to the node from which to start the traversal
  // Returns: a string that specifies each node's value and count,
  // as the nodes would be encountered in an preorder traversal of this tree
  // starting from the specified node
  void toStringPreorderStartingAtNode(std::string& s, BNode<T>* nodePtr) const
  {
    if (nodePtr != NULL) 
    {
      if (s.length() > 0) s = s + ", ";
        s = s + nodePtr->toString();
        toStringPreorderStartingAtNode(s, nodePtr->m_left);
        toStringPreorderStartingAtNode(s, nodePtr->m_right);
    }
  }
  
};

#endif 

