//Kelsey Maricic
//3/4/12
//stack.hpp
//implementation of a stack class

template<class T>
Stack<T>::Stack(const Stack<T> & other)
{
  *this = other;
}

template <class T>
unsigned int Stack<T>:: size()
{
  return LinkedList<T>:: size();
}

template <class T>
void Stack<T>:: clear()
{
  LinkedList<T>:: clear();
}

template <class T>
bool Stack<T>:: isEmpty()
{
  return LinkedList<T>:: isEmpty();
}

template <class T>
const T& Stack<T>:: top()
{
  if(!LinkedList<T>:: isEmpty())
    return LinkedList<T>:: m_head->m_data;
  
  throw std::length_error("stack is empty");
}

template <class T>
void Stack<T>:: push(const T& x)
{
  LinkedList<T>:: insertAtHead(x);
}

template <class T>
void Stack<T>:: pop()
{
  LinkedList<T>:: removeAtHead();
}

template <class T>
Stack<T>& Stack<T>:: operator=(const Stack<T>& rhs)
{
  LinkedList<T>:: operator=(rhs);
  return *this;
}

template <class T>
bool Stack<T>:: operator==(const Stack<T>& rhs) const
{
  return LinkedList<T>:: operator==(rhs);
}
