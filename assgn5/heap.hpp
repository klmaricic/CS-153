//PROGRAMMER: KELSEY MARICIC
//PROGRAM: heap.hpp

#ifndef HEAP_HPP
#define	HEAP_HPP

template<class T>
void Heap<T>::insert(const T& x) 
{
  BNode<T> *nodePtr = new BNode<T> (x);

  insertRecursive(BinaryTree<T>:: m_root, nodePtr, 0);

  BNode<T>* temp = nodePtr;
    
  while (temp->m_parent) 
  {
    temp->m_parent->m_count++;
    temp = temp->m_parent;
  }
    
  heapifyUp(nodePtr);
}

template<class T>
void Heap<T>::insertRecursive(BNode<T>* & rootPtr, BNode<T>* & nodePtr, int depth) 
{
  if (rootPtr == NULL) 
  {
    BinaryTree<T>:: m_size++;
    rootPtr = nodePtr;
    return;
  }

  if (rootPtr->m_left == NULL) 
  {
    BinaryTree<T>:: m_size++;
    rootPtr->m_left = nodePtr;
    nodePtr->m_parent = rootPtr;
    return;
  }

  if (rootPtr->m_right == NULL) 
  {
    BinaryTree<T>:: m_size++;
    rootPtr->m_right = nodePtr;
    nodePtr->m_parent = rootPtr;
    return;
  }

  if (isFull(rootPtr, depth)) 
  {
    BinaryTree<T>:: m_size++;
    
    BNode<T> *temp = rootPtr->m_left;
        
    while(temp->m_left != NULL)
      temp = temp->m_left;    

    temp->m_left = nodePtr;
    nodePtr->m_parent = temp;
    return;
  }

  if (!isFull(rootPtr->m_left, depth + 1)) 
  {
    insertRecursive(rootPtr->m_left, nodePtr, depth + 1);
    return;
  } 
  else 
  {
    insertRecursive(rootPtr->m_right, nodePtr, depth + 1);
    return;
  }
}

template<class T>
void Heap<T>::heapifyUp(BNode<T>* nodePtr) 
{
  if (nodePtr == NULL || nodePtr->m_parent == NULL)
    return;
    
  if (nodePtr->m_data > nodePtr->m_parent->m_data) 
  {
    T temp = nodePtr->m_data;
    nodePtr->m_data = nodePtr->m_parent->m_data;
    nodePtr->m_parent->m_data = temp;

    heapifyUp(nodePtr->m_parent);
  }
}


#endif

