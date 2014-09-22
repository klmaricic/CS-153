/* test_bst.cpp
   Nathan Eloe
   Test cases only for the remove function in the BST class
 */

#include "bst.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
using namespace std;


TEST (BSTTest, RemoveSingle)
{
  BST<int> b;
  b.insert(5);
  ASSERT_EQ(1, b.size());
  b.remove(5);
  ASSERT_EQ(0, b.size());
}

TEST (BSTTest, RemoveSingleWhenDups)
{
  BST<int> b;
  b.insert(5);
  b.insert(5);
  ASSERT_EQ(1, b.size());
  b.remove(5);
  ASSERT_EQ(1, b.size());
}

TEST (BSTTest, RemoveMultipleNoDups)
{
  BST<int> b;
  b.insert(5); b.insert(4); b.insert(10);
  b.insert(7); b.insert(3);
  ASSERT_EQ(5, b.size());
  b.remove(5);
  ASSERT_EQ(4, b.size());
  ASSERT_STREQ("3 (1), 4 (1), 7 (1), 10 (1)", b.toStringInorder().c_str());
  ASSERT_STREQ("4 (1), 3 (1), 10 (1), 7 (1)", b.toStringPreorder().c_str());
  ASSERT_STREQ("3 (1), 7 (1), 10 (1), 4 (1)", b.toStringPostorder().c_str());
}

TEST (BSTTest, RemoveLeaf)
{
    BST<int>b;
    b.insert(5); b.insert(4); b.insert(10);
    b.remove(4);
    ASSERT_EQ(2,b.size());
    ASSERT_FALSE(b.find(4));
}

TEST(BSTTest, RemoveInternalRightChild)
{
    BST<int> b;
    b.insert(5);
    b.insert(10);
    b.remove(5);
    ASSERT_EQ(10,b.getRoot()->m_data);
}

TEST(BSTTest, RemoveInternalLeftChild)
{
    BST<int> b;
    b.insert(10);
    b.insert(5);
    b.remove(10);
    ASSERT_EQ(5,b.getRoot()->m_data);
}

TEST(BSTTest, RemoveInternalTwoChildren)
{
    BST<int> b;
    b.insert(5);
    b.insert(3);
    b.insert(10);
    b.remove(5);
    ASSERT_EQ(3,b.getRoot()->m_data);
}

TEST(BSTTest,RemoveInternalPromoteGrandchild)
{
    BST<int> b;
    b.insert(5);
    b.insert(3);
    b.insert(10);
    b.insert(4);
    b.remove(5);
    ASSERT_EQ(4,b.getRoot()->m_data);
}
