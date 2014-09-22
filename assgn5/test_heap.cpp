/* test_heap.cpp
   Nathan Eloe
   Test cases for the Heap class
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

bool maxHeapnessHolds(BNode<int>* n)
{
  if (n==NULL) //odd case, whatevs
    return true;
  if (n->m_left == NULL && n->m_right == NULL)
    return true;
  if (n->m_left == NULL)
    return n->m_data>=n->m_right->m_data && maxHeapnessHolds(n->m_right);
  if (n->m_right == NULL)
    return n->m_data>=n->m_left->m_data && maxHeapnessHolds(n->m_left);
  return n->m_data >= n->m_left->m_data && maxHeapnessHolds(n->m_left) &&
    n->m_data >= n->m_right->m_data && maxHeapnessHolds(n->m_right);
}

TEST (MaxHeapTest, DefaultConstructor)
{
  Heap<int> h;
  ASSERT_EQ(0, h.size());
  ASSERT_EQ(0, h.height(h.getRoot()));
  ASSERT_FALSE(h.isFull(h.getRoot()));
}

TEST (MaxHeapTest, SingleInsert)
{
  Heap<int> h;
  h.insert(42);
  ASSERT_EQ(1, h.size());
  ASSERT_EQ(1, h.height(h.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
  ASSERT_TRUE(h.isFull(h.getRoot()));
}

TEST (MaxHeapTest, Insert2NoSwap)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  ASSERT_EQ(2, h.size());
  ASSERT_EQ(2, h.height(h.getRoot()));
  ASSERT_FALSE(h.isFull(h.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
}

TEST (MaxHeapTest, Insert2Swap)
{
  Heap<int> h;
  h.insert(21);
  h.insert(42);
  ASSERT_EQ(2, h.size());
  ASSERT_EQ(2, h.height(h.getRoot()));
  ASSERT_FALSE(h.isFull(h.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, Insert3NoSwap)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  h.insert(24);
  ASSERT_EQ(3, h.size());
  ASSERT_EQ(2, h.height(h.getRoot()));
  ASSERT_TRUE(h.isFull(h.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, Insert3Swap)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  h.insert(66);
  ASSERT_EQ(3, h.size());
  ASSERT_EQ(2, h.height(h.getRoot()));
  ASSERT_TRUE(h.isFull(h.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, Insert4NoSwap)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  h.insert(24);
  h.insert(17);
  ASSERT_EQ(4, h.size());
  ASSERT_EQ(3, h.height(h.getRoot()));
  ASSERT_FALSE(h.isFull(h.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, Insert4Swap)
{
  Heap<int> h;
  h.insert(42);
  h.insert(21);
  h.insert(24);
  h.insert(66);
  ASSERT_EQ(4, h.size());
  ASSERT_EQ(3, h.height(h.getRoot()));
  ASSERT_FALSE(h.isFull(h.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, InsertMultiNoSwap)
{
  Heap<int> h;
  int n = 16;
  for (int i = n; i >= 1; i--)
    h.insert(i);
  ASSERT_EQ(n, h.size());
  ASSERT_EQ(5, h.height(h.getRoot()));
  ASSERT_FALSE(h.isFull(h.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST (MaxHeapTest, InsertMultiSwap)
{
  Heap<int> h;
  int n = 8;
  for (int i = 1; i <= n; i++)
    h.insert(i);
  //cout << h.toStringInorder() << endl;
  ASSERT_EQ(n, h.size());
  ASSERT_EQ(4, h.height(h.getRoot()));
  ASSERT_FALSE(h.isFull(h.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
  //cout << h.toStringInorder() << endl;
}

TEST(MaxHeapTest, InsertManySomeSwapSomeNot)
{
  srand(time(NULL));
  Heap<int> h;
  for (int i=0; i<10000; i++)
  {
    h.insert(random());
    ASSERT_TRUE(maxHeapnessHolds(h.getRoot()));
  }
}
