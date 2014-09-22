/*  node.h
    Definition of a node class for a doubly linked list
    Nathan Eloe & Jennifer Leopold
 */

#ifndef NODE_H
#define NODE_H

#include <cstdlib>

template <class T>
class Node
{
  public:
    Node<T> *m_next, *m_prev;   // ptrs to 'next' and 'previous' nodes
    T m_data;                   // data value
    
    // Purpose: default constructor
    // Postconditions: data value set to default for type T, next and previous
    // pointers set to NULL
    Node(): m_next(NULL), m_prev(NULL), m_data() {}
    
    // Purpose: copy constructor
    // Parameters: cpy is Node that is to be copied
    // Postconditions: next and previous ptrs and data set to those of cpy
    Node(const Node<T>& cpy) : 
      m_next(cpy.m_next), m_prev(cpy.m_prev), m_data(cpy.m_data) { }
    
    // Purpose: parameterized constructor
    // Parameters: data, prev, and next are values for respective member vars
    // in Node; default values for prev and next are NULL
    // Postconditions: next and previous ptrs and data set to specified parameter
    // values
    Node(const T& data, Node<T>* prev=NULL, Node<T>* next=NULL):
      m_data(data), m_prev(prev), m_next(next) {}
};

#endif
