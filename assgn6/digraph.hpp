//PROGRAMMER: KELSEY MARICIC
//PROGRAM: digraph.hpp

template<class T, unsigned int A>
DirectedGraph<T, A>::DirectedGraph() 
{
  m_size = A;

  vertices.resize(m_size);
  
  for (int i = 0; i < m_size; i++) 
  {
    vertices[i] = Vertex<T > (i);
  }
  
  edgeList.resize(m_size);
}

template<class T, unsigned int A>
void DirectedGraph<T, A>::clear()
{
  edgeList.clear();
  vertices.clear();
  m_size = 0;
}

template<class T, unsigned int A>
void DirectedGraph<T, A>::checkSize(int i) const
{
  if (i >= m_size)
    throw std::out_of_range("Out of range.");
}

template<class T, unsigned int A>
void DirectedGraph<T, A>::checkSize(int i, int j) const
{
  if (i >= m_size || j >= m_size)
    throw std::out_of_range("Out of range.");
}
          

template<class T, unsigned int A>
void DirectedGraph<T, A>::addEdge(const unsigned int i,const unsigned int j, const int w) 
{
  checkSize(i,j);

  Edge e(i, j, w);
  bool d = false;
	
  for (int z = 0; z < edgeList[i].size(); z++) 
  {
    if (edgeList[i][z].isSameEdge(e)) 
    {
      d = true;
      break;
    }
  }

  if (!d)
    edgeList[i].push_back(e);
}

template<class T, unsigned int A>
void DirectedGraph<T, A>::removeEdge(const unsigned int i, const unsigned int j) 
{
  checkSize(i,j);

  for (int index = 0; index < edgeList[i].size(); index++) 
  {
    if (edgeList[i][index].isSameEdge(i, j)) 
    {
      edgeList[i].erase(edgeList[i].begin() + index);
    }
  }
}

template<class T, unsigned int A>
bool DirectedGraph<T, A>::find(const T& x) const 
{
  for (int i = 0; i < vertices.size(); i++) 
  {
    if (vertices[i].m_data == x)
      return true;
  }

    return false;
}

template<class T, unsigned int A>
T DirectedGraph<T, A>::getVertexData(const unsigned int i) const 
{
  checkSize(i);
    
  return vertices[i].m_data;
}

template<class T, unsigned int A>
void DirectedGraph<T, A>::setVertexData(const unsigned int i, const T& data) 
{
  checkSize(i);
    
  vertices[i].m_data = data;
}

template<class T, unsigned int A>
bool DirectedGraph<T, A>::isEdge(const unsigned int i, const unsigned int j) const 
{
  checkSize(i,j);

  for (int index = 0; index < edgeList[i].size(); index++) 
  {
    if (edgeList[i][index].isSameEdge(i, j))
      return true;
  }
   
  return false;
}

template<class T, unsigned int A>
int DirectedGraph<T, A>::getEdgeWeight(const unsigned int i, const unsigned int j) const 
{
  checkSize(i,j);

  for (int index = 0; index < edgeList[i].size(); index++) 
  {
    if (edgeList[i][index].isSameEdge(i, j))
      return edgeList[i][index].m_weight;
  }
  
  return 0;
}

template<class T, unsigned int A>
void DirectedGraph<T, A>::setEdgeWeight(const unsigned int i,const unsigned int j, const int w) 
{
  checkSize(i,j);

  for (int index = 0; index < edgeList[i].size(); index++) 
  {
    if (edgeList[i][index].isSameEdge(i, j)) 
    {
      edgeList[i][index].m_weight = w;
      break;
    }
  }
}

template<class T, unsigned int A>
int DirectedGraph<T, A>::vertexOutDegree(const unsigned int i) const 
{
  checkSize(i);

  int correction = 0;
  for (int j = 0; j < edgeList[i].size(); j++) 
  {
    for (int k = 0; k < edgeList[i].size(); k++) 
    {
      if (edgeList[i][j].isSameEdge(edgeList[i][k].m_u, edgeList[i][k].m_v) && k != j)
        correction += 1;
    }
  }

  return edgeList[i].size() - correction / 2;
}

template<class T, unsigned int A>
int DirectedGraph<T, A>::vertexInDegree(const unsigned int i) const 
{
  checkSize(i);

  std::vector<Edge> edges;

  int numDuplicates = 0;

  for (int j = 0; j < edgeList.size(); j++) 
  {
    for (int k = 0; k < edgeList[j].size(); k++) 
    {
      if (edgeList[j][k].m_v == i) 
        edges.push_back(edgeList[j][k]);
    }
  }

  for (int j = 0; j < edges.size(); j++) 
  {
    for (int k = 0; k < edges.size(); k++) 
    {
      if (edges[j].isSameEdge(edges[k]) && k != j)
        numDuplicates += 1;
    }
  }
  
  if (numDuplicates != 0)
    numDuplicates /= 2;

  return edges.size() - numDuplicates;
}

template<class T, unsigned int A>
int DirectedGraph<T, A>::graphDegree() const 
{
  int total = 0;

  for (int i = 0; i < m_size; i++) 
  {
    total += vertexInDegree(i);
    total += vertexOutDegree(i);
  }

  return total;
}

template<class T, unsigned int A>
bool DirectedGraph<T, A>::isSimple() const 
{
  for (int i = 0; i < edgeList.size(); i++) 
  {
    for (int j = 0; j < edgeList[i].size(); j++) 
    {
      if (edgeList[i][j].isSameEdge(i, i)) 
        return false;
    }
  }

  std::vector<Edge> allEdges;
    
  for (int i = 0; i < edgeList.size(); i++) 
  {
    for (int j = 0; j < edgeList[i].size(); j++) 
      allEdges.push_back(edgeList[i][j]);
  }

  for (int i = 0; i < allEdges.size(); i++) 
  {
    for (int j = 0; j < allEdges.size(); j++) 
    {
      if (allEdges[i].m_u == allEdges[j].m_v && allEdges[i].m_v == allEdges[j].m_u)
        return false;
    }
  }

  return true;
}

template<class T, unsigned int A>
bool DirectedGraph<T, A>::isComplete() const 
{
  if (!isSimple())
    return false;

  for (int i = 0; i < m_size; i++) 
  {
    for (int j = 0; j < m_size; j++) 
    {
      if ((j != i) && !(isEdge(i, j) || isEdge(j, i)))
        return false;
    }
  }

  return true;
}

template<class T, unsigned int A>
void DirectedGraph<T, A>::dfs(const unsigned int start, int visited[]) const 
{
  checkSize(start);

  visited[ start ] = true;
  std::vector<int> neighbors = getAllNeighbors(start);

  int n;
  for (int i = 0; i < neighbors.size(); i++) 
  {
    n = neighbors[i];
        
    if (visited[n] == false)
      dfs(n, visited);
  }
}

template<class T, unsigned int A>
void DirectedGraph<T, A>::bfs(const unsigned int start, int visited[]) const 
{
  checkSize(start);
  queue<int> q;

	int stepNumber = 0;
  
	for(int i = 0; i < m_size; i++)
		visited[i] = -1;

  int f;  
  visited[start] = stepNumber;
  stepNumber++;
  q.push(start);
  vector<int> neighbors;
  
  while (!q.empty()) 
  {
    int w;
    f = q.front();
    q.pop();
    neighbors = getAllNeighbors(f);
        
    for (int z = 0; z < neighbors.size(); z++)
      w = neighbors[z];
        
    if (visited[w] == -1) 
    {
      visited[w] = stepNumber;
      stepNumber++;
      q.push(w);
    }
  }
}

template<class T, unsigned int A>
std::vector<int> DirectedGraph<T, A>::getAllNeighbors(int n) const 
{
  std::vector<int> ret(1);
  
  for (int j = 0; j < edgeList[n].size(); j++) 
    ret.push_back(edgeList[n][j].m_v);

  return ret;
}

