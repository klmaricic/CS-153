//Name: Kelsey Maricic
//program: linkedList.hpp

template <class T>
void LinkedList<T>:: clear()
{
  while(m_head != NULL)
    removeAtHead();
  m_size = 0;
  m_head = NULL;
  m_tail = NULL;
}

template <class T>
bool LinkedList<T>:: find(const T& x) const
{
  Node<T> *current = m_head;

  while(current != NULL)
  {
    if(current->m_data == x)
      return true;
    current = current->m_next;
  }
  return false;
    
}

template <class T>
void LinkedList<T>:: insertAtHead(const T& x)
{
  Node<T> *temp = new Node<T>(x, NULL, m_head);
  
  if(m_size == 0)
  {
    m_head = temp;
    m_tail = temp;
  }
  else
  {
    m_head->m_prev = temp;
    m_head = temp;
  }
  
  m_size ++;
}

template <class T>
void LinkedList<T>:: insertAtTail(const T& x)
{
  Node<T> *temp = new Node<T>(x, m_tail);
  
  if(m_size == 0)
  {
    m_head = temp;
    m_tail = temp;
  }
  else
  {
    m_tail->m_next = temp;
    m_tail = temp;
    
  }
  
  m_size++;
}

template <class T>
void LinkedList<T>:: removeAtHead()
{
  if(m_size == 0)
    throw std::length_error("length error");
  
  if(m_size >= 2)
  {  
    Node<T> *temp = m_head->m_next;
    if(temp != NULL)
      temp->m_prev = NULL;
    delete m_head;
    m_head = temp;
  }
  else
  {
    delete m_head;
    m_head = NULL;
    m_tail = NULL;
  }
  
  m_size--;
}

template <class T>
void LinkedList<T>:: removeAtTail()
{
  if(m_size == 0)
    throw std::length_error("length error");
    
    if(m_size >= 2)
    {
      Node<T> *temp = m_tail->m_prev;
      temp->m_next = NULL;
      delete m_tail;
      m_tail = temp;
    }
    else
    {
      delete m_tail;
      m_head = NULL;
      m_tail = NULL;
    }
      m_size--;  
}

template <class T>
bool LinkedList<T>:: removeFirstOccurrence(const T& x)
{
  Node<T> *current = m_head;

  for(; current != NULL; current = current->m_next)//
  {
    if(current->m_data == x)
    {
      if(current == m_head) {
        removeAtHead();
      } else if(current == m_tail) {
        removeAtTail();
      } else {
        Node<T> *temp = current->m_prev;
        temp->m_next = current->m_next;
        temp->m_next->m_prev = temp;
        delete current;
        m_size--;
     }
      
      return true;
    }
    
    //current = current->m_next;
  }
  return false;     
}

template <class T>
unsigned int LinkedList<T>:: removeAllOccurrences(const T& x)
{
  int i = 0;
  while(removeFirstOccurrence(x))
    i++;
    
  return i;
}

template <class T>
LinkedList<T>& LinkedList<T>:: operator=(const LinkedList<T>& rhs)
{
  if(this == &rhs)
    return *this;
    
  clear();
  Node<T> *temp =  rhs.m_head;
  while(temp != NULL)
  {
    insertAtTail(temp->m_data);
    temp = temp->m_next;
  }  
  
  return *this;
}

template<class T>
bool LinkedList<T>:: operator==(const LinkedList<T>& rhs) const
{

  if(m_size != rhs.m_size)
    return false;
  
  Node<T> *current = m_head;
  Node<T> *rhsCurrent = rhs.m_head;
  for(int i = 0; i < m_size; i++)
  {
    if(current->m_data != rhsCurrent->m_data)
      return false;
      
    current = current->m_next;
    rhsCurrent = rhsCurrent->m_next;
  }
  
  return true;     
}
