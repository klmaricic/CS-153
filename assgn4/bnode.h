/* bnode.h
   Jennifer Leopold
   A node class for a binary tree
 */

#ifndef BNODE_H
#define BNODE_H

#include <cstdlib>
#include <string>
#include <sstream>

template <class T>
class BNode {
public:
  T m_data;                    // data value
  unsigned int m_count;        // # occurrences of m_data 
  BNode<T> *m_left, *m_right;  // left and right child ptrs

public:
  // Purpose: default constructor
  // Postconditions: left and right child ptrs set to NULL,
  // data set to default value for type T, and count set to 1
  BNode() : m_left(NULL), m_right(NULL), m_data(), m_count(1) { }
  
  // Purpose: parameterized constructor
  // Parameters: specified values for data, left and right child
  // ptrs, and count (respectively)
  // Postconditions: data, left and right child ptrs, and count
  // are set to the specified (or default) values
  BNode(const T& data, BNode<T>* leftLink=NULL, 
        BNode<T>* rightLink=NULL, const unsigned int num = 1) :
      m_left(leftLink), m_right(rightLink), 
      m_data(data), m_count(num) { }
  
  // Purpose: determine whether or not this node is a leaf
  // Returns: true if this node is a leaf; otherwise, returns
  // false
  bool isLeaf( ) const { 
    return((m_left == NULL) && (m_right == NULL)); 
  }
  
  // Purpose: construct a string containing this node's data
  // value and count
  // Returns: a string consisting of this node's data value and
  // its count; e.g., if this node's value is 42 and its
  // count is 3, the returned string will be "42 (3)"
  std::string toString() const {
    std::stringstream ss;
    ss << m_data << " (" << m_count << ")";
    return(ss.str());
  }
};

#endif
