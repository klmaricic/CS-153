/* test_heap_remove.cpp
   Nathan Eloe
   Test cases only for the removeRoot function in the Heap class
 */

#include "heap.h"
#include "BNode.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

bool isSorted(vector<int> v)
{
  for (int i=0; i<v.size()-1; i++)
    if (v[i]>v[i+1])
      return false;
  return true;
}

TEST (MaxHeapTest, RemoveEmpty)
{
  Heap<int> h;
  ASSERT_FALSE(h.removeRoot());
}

TEST (MaxHeapTest, RemoveWhen1)
{
  Heap<int> h;
  h.insert(42);
  ASSERT_TRUE(h.removeRoot());
  ASSERT_EQ(0, h.size());
  ASSERT_EQ(0, h.height(h.getRoot()));
}

TEST (MaxHeapTest, RemoveWhen2)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  ASSERT_TRUE(h.removeRoot());
  ASSERT_EQ(1, h.size());
  ASSERT_EQ(1, h.height(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, RemoveWhen3)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  h.insert(24);
  ASSERT_TRUE(h.removeRoot());
  ASSERT_EQ(2, h.size());
  ASSERT_EQ(2, h.height(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, RemoveWhen4)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  h.insert(24);
  h.insert(10);
  ASSERT_TRUE(h.removeRoot());
  ASSERT_EQ(3, h.size());
  ASSERT_EQ(2, h.height(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, RemoveWhen5)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  h.insert(24);
  h.insert(10);
  h.insert(12);
  ASSERT_TRUE(h.removeRoot());
  ASSERT_EQ(4, h.size());
  ASSERT_EQ(3, h.height(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, RemoveWhen6)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  h.insert(24);
  h.insert(10);
  h.insert(12);
  h.insert(20);
  ASSERT_TRUE(h.removeRoot());
  ASSERT_EQ(5, h.size());
  ASSERT_EQ(3, h.height(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, RemoveWhenMany)
{
  Heap<int> h;
  int n = 8;
  for (int i = n; i > 0; i--)
    h.insert(i);
  ASSERT_TRUE(h.removeRoot()); 
  ASSERT_EQ(n-1, h.size());
  ASSERT_EQ(3, h.height(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, RemovePreservesHeapness)
{
  srand(time(NULL));
  Heap<int> h;
  vector<int> v;
  for (int i=0; i<1000; i++)
    h.insert(random());
  //we're dealing with a max heap, so the values should
  //come off in descending order (reverse sorted)
  v.push_back(h.getRoot()->m_data);
  while (h.size()>0)
  {
    v.insert(v.begin(),h.getRoot()->m_data);
    h.removeRoot();
  }
  ASSERT_TRUE(isSorted(v));
}

