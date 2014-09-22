//PROGRAMMER: KELSEY MARICIC
//PROGRAM: Edge.h

#ifndef EDGE_H
#define	EDGE_H

using namespace std;

class Edge 
{
  public:
    int m_u, m_v, m_weight;
    
    Edge(int u, int v, int weight = 1) 
    {
      m_u = u;
      m_v = v;
      m_weight = weight;
    }
    
    bool isSameEdge(int u, int v) const 
    {
      return m_u == u && m_v == v;
    }
    
    bool isSameEdge(Edge other) const 
    {
        return m_u == other.m_u && m_v == other.m_v;
    }
};



#endif	/* EDGE_H */

