//Kelsey Maricic
//bst.hpp

template<class T>
bool BST<T>:: find(const T& x) const
{
  return(findStartingAtNode(x, BinaryTree<T>:: m_root));
}

template<class T>
bool BST<T>:: findStartingAtNode(const T& x, BNode<T> *nodePtr) const
{
  if(nodePtr == NULL)
    return false;
  else if(nodePtr->m_data == x)
    return true;
  else if(x < nodePtr->m_data)
    return(findStartingAtNode(x, nodePtr->m_left));
  else
    return(findStartingAtNode(x, nodePtr->m_right)); 
}

template<class T>
void BST<T>:: insert(const T& x)
{
  if(BinaryTree<T>::m_root == NULL)
  {
    BinaryTree<T>::m_root = new BNode<T>(x, NULL, NULL);
    BinaryTree<T>:: m_size++;
    return;
  }
  
  insertStartingAtNode(x, BinaryTree<T>::m_root);
}

template<class T>
void BST<T>:: insertStartingAtNode(const T& x, BNode<T>*& nodePtr)
{
  int t;
  
  if(x < nodePtr->m_data)
    t = -1;
  else if(x > nodePtr->m_data)
    t = 1;
  else
    t = 0;
    
  switch(t)
  {
    case -1:
      if(nodePtr->m_left == NULL)
      {
        nodePtr->m_left = new BNode<T>(x, NULL, NULL);   
        BinaryTree<T>::m_size++;
      }
      else
        insertStartingAtNode(x, nodePtr->m_left);
      break;
    case 0:
      nodePtr->m_count++;
      break;
    case 1:
      if(nodePtr->m_right == NULL)
      {
        nodePtr->m_right = new BNode<T>(x, NULL, NULL);
        BinaryTree<T>::m_size++;
      }
      else
        insertStartingAtNode(x, nodePtr->m_right);
      break;
  }
}

template<class T>
bool BST<T>:: operator==(const BST<T>& rhs)const
{
  return (BinaryTree<T>:: operator==(rhs));  
}
