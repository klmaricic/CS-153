/* test_digraph.cpp
  Jennifer Leopold
  Test cases for the directed graph
 */

#include "digraph.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
using namespace std;

// NOTE: Each may test multiple (different) functions

TEST(DIGRAPHTest, DefaultConstructor)
{
  DirectedGraph<string, 0> g;
  ASSERT_EQ(0, g.size());
  ASSERT_TRUE(g.isEmpty());
  ASSERT_FALSE(g.find("42"));
}

TEST(DIGRAPHTest, ClearWhenEmpty)
{
  DirectedGraph<int, 0> g;
  g.clear();
  ASSERT_EQ(0, g.size());
}

TEST(DIGRAPHTest, TwoVerticesNoEdges)
{
  DirectedGraph<string, 2> g;
  g.setVertexData(0, "cat");
  g.setVertexData(1, "dog");
  ASSERT_EQ(2, g.size());
  ASSERT_FALSE(g.isEdge(0,0));
  ASSERT_FALSE(g.isEdge(1,1));
  ASSERT_EQ("cat", g.getVertexData(0));
  ASSERT_EQ("dog", g.getVertexData(1));
  ASSERT_TRUE(g.find("cat"));
  ASSERT_TRUE(g.find("dog"));
  ASSERT_FALSE(g.find("rabbit"));
  ASSERT_THROW(g.getVertexData(500), std::out_of_range);
  ASSERT_THROW(g.isEdge(500,1), std::out_of_range);
  ASSERT_THROW(g.isEdge(1,500), std::out_of_range);
  ASSERT_THROW(g.isEdge(500,500), std::out_of_range);
}

TEST(DIGRAPHTest, TwoVerticesOneUnweightedEdge)
{
  DirectedGraph<int, 2> g;
  ASSERT_EQ(2, g.size());
  g.addEdge(0, 1);
  ASSERT_TRUE(g.isEdge(0,1));
  ASSERT_FALSE(g.isEdge(1,0));
  ASSERT_EQ(1, g.getEdgeWeight(0,1));
}

TEST(DIGRAPHTest, TwoVerticesOneWeightedEdge)
{
  DirectedGraph<int, 2> g;
  ASSERT_EQ(2, g.size());
  g.addEdge(0, 1, 5);
  ASSERT_TRUE(g.isEdge(0,1));
  ASSERT_FALSE(g.isEdge(1,0));
  ASSERT_EQ(5, g.getEdgeWeight(0,1));
}

TEST(DIGRAPHTest, ManyVerticesWeightedEdges)
{
  const int n = 100;
  DirectedGraph<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++) {
    g.addEdge(i, n - i - 1, i * 2 + 1);
    ASSERT_TRUE(g.isEdge(i, n - i - 1));
    ASSERT_EQ(i * 2 + 1, g.getEdgeWeight(i, n - i - 1));
  }
}

TEST(DIGRAPHTest, RemoveEdgesWhenManyVerticesWeightedEdges)
{
  const int n = 100;
  DirectedGraph<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++)
    g.addEdge(i, n - i - 1, i * 2 + 1);
  for (int i = 0; i < n; i++) {
    g.removeEdge(i, n - i - 1);
    ASSERT_FALSE(g.isEdge(i, n - i - 1));
  }
}

TEST(DIGRAPHTest, ClearWhenManyVertices)
{
  const int n = 100;
  DirectedGraph<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++)
    g.addEdge(i, n - i - 1, i * 2 + 1);
  g.clear();
  ASSERT_EQ(0, g.size());
}

TEST(DIGRAPHTest, ReferenceEdgeOutOfRange)
{
  DirectedGraph<int, 10> g;
  ASSERT_THROW(g.isEdge(50,50), std::out_of_range);
  ASSERT_THROW(g.isEdge(0,50), std::out_of_range);
  ASSERT_THROW(g.isEdge(50,0), std::out_of_range);
  ASSERT_THROW(g.addEdge(50,50), std::out_of_range);
  ASSERT_THROW(g.addEdge(0,50), std::out_of_range);
  ASSERT_THROW(g.addEdge(50,0), std::out_of_range);
  ASSERT_THROW(g.removeEdge(50,50), std::out_of_range);
  ASSERT_THROW(g.removeEdge(0,50), std::out_of_range);
  ASSERT_THROW(g.removeEdge(50,0), std::out_of_range);
  ASSERT_THROW(g.getEdgeWeight(50,50), std::out_of_range);
  ASSERT_THROW(g.getEdgeWeight(0,50), std::out_of_range);
  ASSERT_THROW(g.getEdgeWeight(50,0), std::out_of_range);
  ASSERT_THROW(g.setEdgeWeight(50,50, 2), std::out_of_range);
  ASSERT_THROW(g.setEdgeWeight(0,50, 2), std::out_of_range);
  ASSERT_THROW(g.setEdgeWeight(50,0, 2), std::out_of_range);
  ASSERT_THROW(g.getVertexData(50), std::out_of_range);
  ASSERT_THROW(g.setVertexData(50, 42), std::out_of_range);
  ASSERT_THROW(g.vertexInDegree(500), std::out_of_range);
  ASSERT_THROW(g.vertexOutDegree(500), std::out_of_range);
}

TEST(DIGRAPHTest, IsSimpleWhenEmpty)
{
  DirectedGraph<int, 0> g;
  ASSERT_TRUE(g.isSimple());
}

TEST(DIGRAPHTest, IsSimpleWhenNonEmpty)
{
  DirectedGraph<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(2,3);
  ASSERT_TRUE(g.isSimple());
}

TEST(DIGRAPHTest, IsSimpleWhenLoop)
{
  DirectedGraph<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,1); g.addEdge(2,3);
  ASSERT_FALSE(g.isSimple());
}

TEST(DIGRAPHTest, IsSimpleWhenParallelEdges)
{
  DirectedGraph<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,0); g.addEdge(2,3);
  ASSERT_FALSE(g.isSimple());
}

TEST(DIGRAPHTest, IsCompleteWhenEmpty)
{
  DirectedGraph<int, 0> g;
  ASSERT_TRUE(g.isComplete());
}

TEST(DIGRAPHTest, IsCompleteWhenNonEmptyMissingEdges)
{
  DirectedGraph<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(3,2);
  ASSERT_FALSE(g.isComplete());
}

TEST(DIGRAPHTest, IsCompleteWhenNonEmptyNoMissingEdges)
{
  DirectedGraph<int, 4> g;
  g.addEdge(0,1); g.addEdge(0,2); g.addEdge(0,3);
  g.addEdge(2,1); g.addEdge(3,2); g.addEdge(1,3);
  ASSERT_TRUE(g.isComplete());
}

TEST(DIGRAPHTest, IsCompleteWhenLoop)
{
  DirectedGraph<int, 3> g;
  g.addEdge(0,1); g.addEdge(1,1); g.addEdge(2,1);
  ASSERT_FALSE(g.isComplete());
}

TEST(DIGRAPHTest, IsCompleteWhenParallelEdges)
{
  DirectedGraph<int, 3> g;
  g.addEdge(0,1); g.addEdge(1,0); g.addEdge(2,1);
  ASSERT_FALSE(g.isComplete());
}

TEST(DIGRAPHTest, VertexDegreeWhenNoEdges)
{
  DirectedGraph<int, 2> g;
  ASSERT_EQ(0, g.vertexInDegree(0)); ASSERT_EQ(0, g.vertexOutDegree(0));
  ASSERT_EQ(0, g.vertexInDegree(1)); ASSERT_EQ(0, g.vertexOutDegree(1));
  ASSERT_EQ(0, g.graphDegree());
}

TEST(DIGRAPHTest, VertexDegreeWhenEdges)
{
  const int n = 100;
  DirectedGraph<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n-2; i++) {
    g.addEdge(i, n - i - 1);
    if (i < 50)
      g.addEdge(i, 99);
    else if (i > 50) g.addEdge(i, 98);
  }
  ASSERT_EQ(0, g.vertexInDegree(0)); ASSERT_EQ(1, g.vertexOutDegree(0));
  ASSERT_EQ(0, g.vertexInDegree(1)); ASSERT_EQ(2, g.vertexOutDegree(1));
  for (int i = 2; i < n-2; i++) {
    ASSERT_EQ(1, g.vertexInDegree(i));
    if (i != 50)
      ASSERT_EQ(2, g.vertexOutDegree(i));
    else ASSERT_EQ(1, g.vertexOutDegree(i));
  }
  ASSERT_EQ(48, g.vertexInDegree(98)); ASSERT_EQ(0, g.vertexOutDegree(98));
  ASSERT_EQ(50, g.vertexInDegree(99)); ASSERT_EQ(0, g.vertexOutDegree(99)); 
  ASSERT_EQ(388, g.graphDegree());
}


TEST(DIGRAPHTest, BFSWhenEmpty)
{
  DirectedGraph<int, 0> g;
  int visited[1];
  ASSERT_THROW(g.bfs(0, visited), std::out_of_range);
}

TEST(DIGRAPHTest, BFSWhenSingleVertexNoEdges)
{
  DirectedGraph<int, 1> g;
  int visited[1];
  g.bfs(0, visited);
  ASSERT_EQ(0, visited[0]);
}

TEST(DIGRAPHTest, BFSWhenSingleVertexOneEdge)
{
  DirectedGraph<int, 1> g;
  int visited[1];
  g.addEdge(0,0);
  g.bfs(0, visited);
  ASSERT_EQ(0, visited[0]);
}

TEST(DIGRAPHTest, BFSWhenNotEmptySomeEdgesStartingFrom0)
{
  DirectedGraph<int, 5> g;
  int visited[5];
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(0,3); 
  g.addEdge(2,1); // note: makes a cycle from vertex 0 to vertex 2!
  g.addEdge(4,3); // note: no way to get to vertex 4!
  g.bfs(0, visited);
  ASSERT_EQ(0, visited[0]);
  ASSERT_EQ(1, visited[1]); ASSERT_EQ(1, visited[3]);
  ASSERT_EQ(2, visited[2]);
  ASSERT_EQ(NOT_YET_VISITED, visited[4]);
}

TEST(DIGRAPHTest, BFSWhenNotEmptySomeEdgesNotStartingFrom0)
{
  DirectedGraph<int, 5> g;
  int visited[5];
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(1,3); 
  g.addEdge(2,4); g.addEdge(3,4);
  g.bfs(1, visited);
  ASSERT_EQ(NOT_YET_VISITED, visited[0]);
  ASSERT_EQ(0, visited[1]);
  ASSERT_EQ(1, visited[2]); ASSERT_EQ(1, visited[3]);
  ASSERT_EQ(2, visited[4]);
}

TEST(DIGRAPHTest, DFSWhenEmpty)
{
  DirectedGraph<int, 0> g;
  int visited[1];
  ASSERT_THROW(g.dfs(0, visited), std::out_of_range);
}

TEST(DIGRAPHTest, DFSWhenSingleVertexNoEdges)
{
  DirectedGraph<int, 1> g;
  int visited[1];
  g.dfs(0, visited);
  ASSERT_EQ(0, visited[0]);
}

TEST(DIGRAPHTest, DFSWhenSingleVertexOneEdge)
{
  DirectedGraph<int, 1> g;
  int visited[1];
  g.addEdge(0,0);
  g.dfs(0, visited);
  ASSERT_EQ(0, visited[0]);
}

TEST(DIGRAPHTest, DFSWhenNotEmptySomeEdgesStartingFrom0)
{
  DirectedGraph<int, 5> g;
  int visited[5];
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(2,3); 
  g.addEdge(2,0); // note: makes a cycle from vertex 0 to vertex 2
  g.addEdge(4,3); // note: no way to get to vertex 4
  g.dfs(0, visited);
  for (int i = 0; i < 4; i++)
    ASSERT_EQ(i, visited[i]);
  ASSERT_EQ(NOT_YET_VISITED, visited[4]);
}

TEST(DIGRAPHTest, DFSWhenNotEmptySomeEdgesNotStartingFrom0)
{
  DirectedGraph<int, 5> g;
  int visited[5];
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(2,3); 
  g.addEdge(2,0); // note: makes a cycle from vertex 0 to vertex 2
  g.addEdge(4,3); // note: no way to get to vertex 4
  g.dfs(1, visited);
  ASSERT_EQ(0, visited[1]);
  ASSERT_EQ(1, visited[2]);
  ASSERT_EQ(2, visited[3]);
  ASSERT_EQ(2, visited[0]);
  ASSERT_EQ(NOT_YET_VISITED, visited[4]);
}


