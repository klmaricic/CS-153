/* digraph.h
   Jennifer Leopold
   Class definition for a directed graph
 */
#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <stdexcept>
#include <iostream>
#include <queue>             // useful for BFS
#include <vector>
#include "Vertex.h"
#include "Edge.h"
using namespace std;

#define NOT_YET_VISITED -1   // to be used for BFS and DFS

template <class T, unsigned int N>
class DirectedGraph {
private:
    vector<int> getAllNeighbors(int n) const;
    
    unsigned int m_size;   // This should be initialized to the value N
    vector< vector<Edge> > edgeList;
    vector<Vertex<T> > vertices;
    
    
public:
  // Purpose: default constructor
  // Postconditions: initializes the data structure to have N vertices (m_size),
  // no edges, and a data value for each vertex (initialized to the default
  // value for type T)
  DirectedGraph(); 
  
  // Purpose: destructor
  // Postconditions: removes all edges and deallocates all dynamically 
  // allocated memory associated with the data structure (via clear)
  ~DirectedGraph() { clear(); } 
  
  // Purpose: accessor for m_size (i.e., the number of vertices in the graph)
  // Returns: the number of vertices in the graph 
  unsigned int size() { return m_size; } 
  
  // Purpose: determine whether or not this graph is empty
  // Returns: returns true if this graph is empty; otherwise, returns false
  bool isEmpty() const { return m_size == 0; } 
  
  // Purpose: clear this graph
  // Postconditions: removes all edges and deallocates all dynamically 
  // allocated memory associated with the data structure 
  void clear(); 
  
  // Purpose: determine whether there is a vertex with a specified data value
  // Parameters: x is the data value to be found
  // Returns: true if there is a vertex with data value x; otherwise, false
  bool find(const T& x) const; 
  
  // Purpose: add edge(i,j) with weight w
  // Parameters: i is source vertex, j is destination vertex, w is weight
  // (note: default value for weight is 1)
  // Postconditions: edge (i, j) is added to the graph with weight w
  // Exceptions: if i or j >= # vertices in this graph, then throw
  // an out_of_range error
  void addEdge(const unsigned int i, 
               const unsigned int j, const int w = 1);
  
  // Purpose: remove edge(i,j) 
  // Parameters: i is source vertex, j is destination vertex
  // Postconditions: edge (i, j) is removed from the graph 
  // Exceptions: if i or j >= # vertices in this graph, then throw
  // an out_of_range error
  void removeEdge(const unsigned int i, const unsigned int j);
  
  // Purpose: determine whether there is an edge (i,j) 
  // Parameters: i is source vertex, j is destination vertex
  // Returns: true if there is an edge (i,j); otherwise, false 
  // Exceptions: if i or j >= # vertices in this graph, then throw
  // an out_of_range error
  bool isEdge(const unsigned int i, const unsigned int j) const;
  
  // Purpose: get the weight associated with edge (i,j) 
  // Parameters: i is source vertex, j is destination vertex
  // Returns: the weight associated with edge (i,j); if no such edge exists,
  // return 0
  // Exceptions: if i or j >= # vertices in this graph, then throw
  // an out_of_range error
  int getEdgeWeight(const unsigned int i, const unsigned int j) const;
  
  // Purpose: set the weight associated with edge (i,j) 
  // Parameters: i is source vertex, j is destination vertex, w is the value
  // to be associated with edge (i,j)
  // Postconditions: the weight associated with edge (i,j) has been set to w
  // Exceptions: if i or j >= # vertices in this graph, then throw
  // an out_of_range error
  void setEdgeWeight(const unsigned int i, 
                     const unsigned int j, const int w);
  
  // Purpose: get the data associated with vertex i 
  // Parameters: i is the specified vertex
  // Returns: the data associated with vertex i
  // Exceptions: if i >= # vertices in this graph, then throw
  // an out_of_range error
  T getVertexData(const unsigned int i) const;
  
  // Purpose: set the data associated with vertex i 
  // Parameters: i is the specified vertex, data is the specified data value
  // Postconditions: the data value associated with vertex i has been 
  // set to data
  // Exceptions: if i >= # vertices in this graph then throw
  // an out_of_range error
  void setVertexData(const unsigned int i, const T& data);
  
  // Purpose: determine the # edges coming in to vertex i 
  // Parameters: i is the specified vertex
  // Returns: the # edges coming in to vertex i
  // Exceptions: if i >= # vertices in this graph, then throw
  // an out_of_range error
  int vertexInDegree(const unsigned int i) const;
  
  // Purpose: determine the # edges coming out of vertex i 
  // Parameters: i is the specified vertex
  // Returns: the # edges coming out of vertex i
  // Exceptions: if i >= # vertices in this graph, then throw
  // an out_of_range error
  int vertexOutDegree(const unsigned int i) const;
  
  // Purpose: determine the degree of this graph 
  // Returns: the sum of the inDegree and outDegree of every vertex 
  // in this graph
  int graphDegree() const;
  
  // Purpose: determine whether this graph is simple (i.e., contains no
  // parallel edges (e.g., (u, v) and (v, u)), and no loops (e.g., (u, u))) 
  // Returns: true if this graph is simple; otherwise, false 
  bool isSimple() const; 
  
  // Purpose: determine whether this graph is complete (i.e., is simple and
  // there is an edge (u, v) or (v, u) for every pair of vertices u and v)
  // Returns: true if this graph is complete; otherwise, false 
  bool isComplete() const; 

  // Purpose: perform a breadth-first search (BFS) on this graph starting at 
  // specified vertex
  // Parameters: start is the vertex from which the breadth-first search should
  // begin; visited is a 1D array of size N (essentially passed by reference
  // since it is an array); upon termination of this function, visited[i]
  // should be an integer indicating when vertex i was visited (e.g., 
  // visited[start] = 0, if there is an edge (start, u) then visited[u] = 1, 
  // etc.); if a vertex v is never visited in a bfs beginning at start, then
  // visited[v] should be set to NOT_YET_VISITED (which is #define'd in 
  // digraph.h)
  // Exceptions: if start >= # vertices in this graph, then throw
  // an out_of_range error
  void bfs(const unsigned int start, int visited[]) const; 
  
  // Purpose: perform a depth-first search (DSF) on this graph starting at 
  // specified vertex
  // Parameters: start is the vertex from which the depth-first search should
  // begin; visited is a 1D array of size N (essentially passed by reference
  // since it is an array); upon termination of this function, visited[i]
  // should an integer indicating when vertex i was visited (e.g., 
  // visited[start] = 0; if there is an edge (start, u) then visited[u] = 1;
  // if there is an edge (u, v) then visited[v] = 2, etc.); if a vertex
  // v is never visited in a dfs beginning at start, then
  // visited[v] should be set to NOT_YET_VISITED (which is #define'd in 
  // digraph.h)
  // Exceptions: if start >= # vertices in this graph, then throw
  // an out_of_range error
  void dfs(const unsigned int start, int visited[]) const;
  
  void checkSize(int i) const;
  
  void checkSize(int i, int j) const; 
};

#include "digraph.hpp"

#endif // DIRECTED_GRAPH.h

