/* linkedList.hpp
   Implementation of a doubly linked list class
   Nathan Eloe & Jennifer Leopold
 */

template <class T>
void LinkedList<T>::insertAtHead(const T& ins)
{
  Node<T>* temp = m_head;
  m_head = new Node<T>(ins,NULL,temp);
  if (temp)
    temp->m_prev=m_head;
  else
    m_tail=m_head;
  m_size++;
}

template <class T>
void LinkedList<T>::insertAtTail(const T& ins)
{
  Node<T>* temp = m_tail;
  m_tail = new Node<T>(ins,temp,NULL);
  if (temp)
    temp->m_next=m_tail;
  else
    m_head=m_tail;
  m_size++;
}

template <class T>
bool LinkedList<T>::find(const T& f) const
{
  Node<T>* temp = m_head;
  while (temp)
  {
    if (temp->m_data==f)
      return true;
    temp=temp->m_next;
  }
  return false;
}

template <class T>
bool LinkedList<T>::removeFirstOccurrence(const T& rem)
{
  Node<T>* temp = m_head;
  while (temp)
  {
    if (temp->m_data==rem)
    {
      if (temp->m_prev)
        temp->m_prev->m_next=temp->m_next;
      if (temp->m_next)
        temp->m_next->m_prev=temp->m_prev;
      if (m_head == temp)
        m_head=temp->m_next;
      if (m_tail == temp)
        m_tail=temp->m_prev;
      delete temp;
      m_size--;
      return true;
    }
    temp=temp->m_next;
  }
  return false;
}

template <class T>
unsigned int LinkedList<T>::removeAllOccurrences (const T& rem)
{
  unsigned int count=0;
  while (removeFirstOccurrence(rem))
    count++;
  return count;
}

template <class T>
void LinkedList<T>::clear()
{
  while (m_head!=m_tail)
  {
    m_head=m_head->m_next;
    delete m_head->m_prev;
  }
  delete m_head;
  m_head=NULL;
  m_tail=NULL;
  m_size=0;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
  if (this==&rhs)
    return *this;
  clear();
  Node<T>* it = rhs.m_head;
  while (it)
  {
    insertAtTail(it->m_data);
    it=it->m_next;
  }
}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>&rhs) const
{
  if (m_size != rhs.m_size) return(false);

  Node<T> *temp1 = m_head, *temp2=rhs.m_head;
  while (temp1 != NULL)
  {
    if (temp1->m_data != temp2->m_data)
      return false;
    temp1 = temp1->m_next;
    temp2 = temp2->m_next;
  }
  return(true);
}

template <class T>
void LinkedList<T>::removeAtHead()
{
    if (m_head)
        removeFirstOccurrence(m_head->m_data);
    else throw std::length_error("list is empty");
}

template <class T>
void LinkedList<T>::removeAtTail()
{
    if (m_tail)
    {
        if (m_tail->m_prev)
        {
            m_tail=m_tail->m_prev;
            delete m_tail->m_next;
            m_tail->m_next=NULL;
        }
        else
        {
            delete  m_tail;
            m_tail=NULL;
            m_head=NULL;
        }
        m_size--;
    }
    else
        throw std::length_error("list is empty");
}


