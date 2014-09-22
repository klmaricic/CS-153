/* test_bst.cpp
   Nathan Eloe
   Test cases for the BST class
 */

#include "bst.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
using namespace std;

TEST (BSTTest, DefaultConstructor)
{
  BST<int> b;
  ASSERT_EQ(0, b.size());
}

TEST (BSTTest, GetRootEmpty)
{
  BST<int> b;
  ASSERT_FALSE(b.getRoot());
}

TEST (BSTTest, GetRootNonEmpty)
{
  BST<int> b;
  b.insert(1);
  ASSERT_TRUE(b.getRoot());
  ASSERT_EQ(1,b.getRoot()->m_data);
}

TEST (BSTTest, FindTreeEmpty)
{
  BST<int> b;
  ASSERT_FALSE(b.find(1));
}

TEST (BSTTest, FindValInTree)
{
  BST<int> b;
  b.insert(1);
  ASSERT_TRUE(b.find(1));
}

TEST (BSTTest, FindValNotInTree)
{
  BST<int> b;
  b.insert(2);
  ASSERT_FALSE(b.find(1));
}

TEST (BSTTest, InsertSingle)
{
  BST<int> b;
  b.insert(5);
  ASSERT_EQ(1, b.size());
  ASSERT_EQ(5,b.getRoot()->m_data);
  ASSERT_STREQ(b.toStringInorder().c_str(),b.toStringPreorder().c_str());
  ASSERT_STREQ(b.toStringPreorder().c_str(),b.toStringPostorder().c_str());
}

TEST (BSTTest, InsertMultipleNoDups)
{
  BST<int> b;
  b.insert(5); b.insert(4); b.insert(10);
  b.insert(7); b.insert(3);
  ASSERT_EQ(5, b.size());
  ASSERT_STREQ("3 (1), 4 (1), 5 (1), 7 (1), 10 (1)",
               b.toStringInorder().c_str());
  ASSERT_STREQ("5 (1), 4 (1), 3 (1), 10 (1), 7 (1)",
               b.toStringPreorder().c_str());
  ASSERT_STREQ("3 (1), 4 (1), 7 (1), 10 (1), 5 (1)",
               b.toStringPostorder().c_str());
}

TEST (BSTTest, InsertMultipleDups)
{
  BST<int> b;
  b.insert(5); b.insert(4); b.insert(10);
  b.insert(7); b.insert(3); 
  b.insert(5); b.insert(4); b.insert(10);
  ASSERT_EQ(5, b.size());
  ASSERT_STREQ("3 (1), 4 (2), 5 (2), 7 (1), 10 (2)",
               b.toStringInorder().c_str());
  ASSERT_STREQ("5 (2), 4 (2), 3 (1), 10 (2), 7 (1)",
               b.toStringPreorder().c_str());
  ASSERT_STREQ("3 (1), 4 (2), 7 (1), 10 (2), 5 (2)",
               b.toStringPostorder().c_str());
}

TEST (BSTTest, EqualityNoDups)
{
  BST<int> b1;
  b1.insert(5); b1.insert(4); b1.insert(10);
  b1.insert(7); b1.insert(3); 
  ASSERT_EQ(5, b1.size());
 
  BST<int> b2;
  b2.insert(5); b2.insert(4); b2.insert(10);
  b2.insert(7); b2.insert(3); 
  ASSERT_EQ(5, b2.size());
  
  ASSERT_TRUE(b1 == b2);
}

TEST (BSTTest, InequalityNoDupsDifferentValues)
{
  BST<int> b1;
  b1.insert(5); b1.insert(4); b1.insert(10);
  b1.insert(7); b1.insert(3); 
  ASSERT_EQ(5, b1.size());
  
  BST<int> b2;
  b2.insert(5); b2.insert(4); b2.insert(10);
  b2.insert(3); b2.insert(17);
  ASSERT_EQ(5, b2.size());
  
  ASSERT_FALSE(b1 == b2);
}

TEST (BSTTest, EqualityDups)
{
  BST<int> b1;
  b1.insert(5); b1.insert(4); b1.insert(10);
  b1.insert(7); b1.insert(3); 
  b1.insert(5); b1.insert(10);
  ASSERT_EQ(5, b1.size());
  
  BST<int> b2;
  b2.insert(5); b2.insert(4); b2.insert(10);
  b2.insert(7); b2.insert(3);
  b2.insert(5); b2.insert(10);
  ASSERT_EQ(5, b2.size());
  
  ASSERT_TRUE(b1 == b2);
}

TEST (BSTTest, InequalityDups)
{
  BST<int> b1;
  b1.insert(5); b1.insert(4); b1.insert(10);
  b1.insert(7); b1.insert(3); 
  b1.insert(5); b1.insert(10);
  ASSERT_EQ(5, b1.size());
  
  BST<int> b2;
  b2.insert(5); b2.insert(4); b2.insert(10);
  b2.insert(7); b2.insert(3);
  b2.insert(5);
  ASSERT_EQ(5, b2.size());
  
  ASSERT_FALSE(b1 == b2);
}

TEST (BSTTest, InequalityNoDupsDifferentStructure)
{
  BST<int> b1;
  b1.insert(5); b1.insert(4); b1.insert(10);
  b1.insert(7); b1.insert(3); 
  ASSERT_EQ(5, b1.size());
  BST<int> b2;
  b2.insert(5); b2.insert(7); b2.insert(10);
  b2.insert(3); b2.insert(4); 
  ASSERT_EQ(5, b1.size());
  
  ASSERT_FALSE(b1==b2);
}

TEST (BSTTest, InequalityDupsDifferentStructure)
{
  BST<int> b1;
  b1.insert(5); b1.insert(4); b1.insert(10);
  b1.insert(7); b1.insert(3); b1.insert(7);
  ASSERT_EQ(5, b1.size());
  
  BST<int> b2;
  b2.insert(5); b2.insert(4); b2.insert(10);
  b2.insert(3); b2.insert(7); b1.insert(7);
  ASSERT_EQ(5, b1.size());
  
  ASSERT_FALSE(b1==b2);
}

TEST (BSTTest, IsEmptyEmpty)
{
  BST<int> b1;
  ASSERT_TRUE(b1.isEmpty());
}

TEST (BSTTest, IsEmptyNotEmpty)
{
  BST<int> b1;
  b1.insert(1);
  ASSERT_FALSE(b1.isEmpty());
}
