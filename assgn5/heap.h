/* heap.h
   Jennifer Leopold
   Class definition for a max-heap
 */
#ifndef HEAP_H
#define HEAP_H

#include "bnode.h"
#include "binaryTree.h"
#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class Heap : public BinaryTree<T> 
{

// Note: Duplicates handled as separate nodes (i.e., not handling 
// dups with Bnode<T>::m_count; instead that is being used to
// store # nodes in subtree rooted by that node (including the 
// node itself))

public:
  // Purpose: default constructor
  // Postconditions: (see BinaryTree default constructor)
  Heap() {
    // automatically calls default constructor for BinaryTree
  }

  // Purpose: destructor
  // Postconditions: (see BinaryTree default destructor)
  ~Heap( ) { 
    // automatically calls BinaryTree destructor
  }
  
  // Purpose: determine the height of the subtree rooted by
  // rootPtr 
  // Parameters: rootPtr is a pointer to the root of the subtree 
  // for which we want to determine height
  // Returns: height of the subtree rooted by rootPtr 
  unsigned int height(BNode<T>* rootPtr) const {
    unsigned int h = 0;
    BNode<T> *temp = rootPtr;
    while (temp != NULL) {
      h++;
      temp = temp->m_left;
    }
    return(h);
  }
  
  // Purpose: determine whether or not the tree rooted by rootPtr
  // is full 
  // Parameters: rootPtr is pointer to the tree to be tested and
  // depth is the rootPtr node's depth in the tree (e.g., m_root 
  // is at depth 0)
  // Returns: true if the tree rooted by rootPtr is full; 
  // otherwise, false
  bool isFull(BNode<T>* rootPtr = BinaryTree<T>::m_root,
                   unsigned int depth = 0) const {
    if (rootPtr == NULL)
      return(false);  // weird case
    else return(((double) rootPtr->m_count) == 
                (pow(2.0, height(BinaryTree<T>::m_root)-depth)-1));
  }
  
  // Purpose: insert the specified value into the heap 
  // Parameters: x is the value to be inserted into the heap
  // Postconditions: x has been inserted into the tree into the
  // rightmost available position and then pushed up the tree as 
  // necessary to maintain proper heap order
  void insert(const T& x);
  // *** WRITE ME!!!
    
  // Purpose: determine whether or not this heap is equivalent to
  // a specified heap 
  // Parameters: rhs is the heap to be compared to this heap
  // Returns: if the heaps are exactly the same in terms of 
  // structure and content, return true; otherwise, return false
  bool operator==(const Heap<T>& rhs) const {
    return(BinaryTree<T>::operator ==(rhs));
  }
 
private:
  // Purpose: push the node pointed to by nodePtr up the heap as
  // far as necessary, repeatedly swapping with the parent if this node
  // has a higher value
  // Parameters: nodePtr is pointer to the node to be moved up the tree 
  // Postconditions: the nodePtr's node's value has been pushed up 
  // the tree as necessary to maintain proper heap order
  void heapifyUp(BNode<T>* nodePtr);
  // *** WRITE ME!!!
  
  void insertRecursive(BNode<T>* & rootPtr, BNode<T>* & nodePtr, int depth);
};

#include "heap.hpp"

#endif // heap.h

