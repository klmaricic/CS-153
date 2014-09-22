//PROGRAMMER: KELSEY MARICIC
//PROGRAM: Vertex.h

#ifndef VERTEX_H
#define VERTEX_H
using namespace std;

template <class T>
class Vertex 
{
  public:
    T m_data;
    int m_vertNum;

    Vertex(int num= -1, T data= T()) 
    {
      m_vertNum = num;
      m_data = data;
    }
};
#endif
