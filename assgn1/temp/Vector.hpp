//Programmer: Kelsey Maricic
//PROGRAM: Vector.hpp
//DATE: 2/17/12

#include<stdexcept>

template<class T>
void Vector<T>:: clear()
{
  if(m_data != NULL)
  {
    m_size = 0;
    m_max_size = 0;
    delete[] m_data;
    m_data = NULL;
  }
}

template<class T>
void Vector<T>:: push_back(const T& x)
{
  if(m_size == 0)
  {
    m_data = new T[2];
    m_max_size = 2;
  }
  
  else if(m_size = m_max_size)
  {
    T* temp;
    m_max_size *= 2;
    temp = new T[m_max_size];
    
    for(int i =0; i <  m_max_size; i++)
      temp[i] = m_data[i];
    
    delete[] m_data;
    m_data = temp;
  }
    
  m_data[m_size] = x;
  m_size++;
}

template<class T>
void Vector<T>:: remove(const T& x)
{
  int i = -1;
  while(i < m_size && m_data[i] != x)
    i++;
    
  if(i != -1)
  {
    for(int j = i; j < m_size-1; j++)
      m_data[j] = m_data[j+1];  
     
    m_size--;
  } 
    
  if(m_size <= m_max_size)
  {
    m_max_size = m_max_size/2;
    T* temp;
    temp = new T[m_max_size];
    
    for(int i = 0; i < m_size; i++)
      temp[i] = m_data[i];
    
    delete[] m_data;  
    m_data = temp;
  }
}

template<class T>
void Vector<T>:: pop_back()
{
  if(m_size ==0)
    throw std:: length_error("length error");
    
  m_size--;
    
  if(m_size/ m_max_size <= .25)
  {
    m_max_size /= 2;
    
    T* temp;
    temp = new T[m_max_size];
         
    for(int i = 0; i < m_size; i++)
    temp[i] = m_data[i];
                   
    delete[] m_data;
    m_data = temp;
  }    
}

template<class T>
T& Vector<T>:: operator[](unsigned int i)
{ 
  if(i<0 || i>=m_size)
    throw std:: out_of_range("i<0 or i>=m_size");
    
  return m_data[i];
}

template<class T>
const T& Vector<T>:: operator[](unsigned int i) const
{
  if(i<0 || i>=m_size)
    throw std:: out_of_range("i<0 or i>=m_size");
      
  return m_data[i];
}
        
template<class T>
Vector<T>& Vector<T>:: operator=(const Vector<T>& rhs)
{
  if(&rhs == this)
    return(*this);
  else
  {
    clear();
    m_size = rhs.m_size;
    m_max_size = rhs.m_max_size;
    m_data = new T[m_max_size];
    
    for(int i = 0; i < m_max_size; i++)
      m_data[i] = rhs.m_data[i];
  }
}
