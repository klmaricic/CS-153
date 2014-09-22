/*  test_stack.h
    Test cases for stack
    Nathan Eloe & Jennifer Leopold
 */

#include "Stack.h"
#include <gtest/gtest.h>
#include <stdexcept>

TEST (GraderStackTest, DefaultConstructor)
{
  // Create stack with default constructor
  // Test whether size is 0 and isEmpty is true
  Stack<int> s;
  ASSERT_EQ(0,s.size());
  ASSERT_TRUE(s.isEmpty());
}

TEST (GraderStackTest, PushPushesToTopSingle)
{
  // Create stack with default constructor
  // Push one data value
  // Test whether size is 1, isEmpty is false, and
  // whether top is the value you pushed
  Stack<int> s;
  s.push(1);
  ASSERT_EQ(1,s.top());
  ASSERT_EQ(1,s.size());
  ASSERT_FALSE(s.isEmpty());
}

TEST (GraderStackTest, PushPushesToTopMulti)
{
  // Create stack with default constructor
  // Push multiple data values
  // After each push, test whether size is # values pushed
  // to that point, and whether top is the most recently pushed value
  Stack<int> s;
  for (int i=0; i<1000; i++)
  {
    s.push(i);
    ASSERT_EQ(i,s.top());
    ASSERT_EQ(i+1,s.size());
  }
}

TEST (GraderStackTest, TopThrowsExceptionEmpty)
{
  // Create stack with default constructor
  // Test whether exception is thrown when top is called
  Stack<int> s;
  ASSERT_THROW(s.top(),std::length_error);
}

TEST(GraderStackTest, PopThrowExceptionEmpty)
{
  // Create stack with default constructor
  // Test whether exception is thrown when pop is called
  Stack<int> s;
  ASSERT_THROW(s.pop(),std::length_error);
}

TEST(GraderStackTest, PopRemovesOnly)
{
  // Create stack with default constructor
  // Push one value, then pop
  // Test whether resulting size is 0
  Stack<int> s;
  s.push(1);
  s.pop();
  ASSERT_EQ(0,s.size());
}

TEST(GraderStackTest, PopRemovesTop)
{
  // Create stack with default constructor
  // Push multiple data values
  // For each value in stack, test if top is the value most recently pushed
  // Then pop, and test whether size of stack is one less than before
  Stack<int> s;
  for (int i=0; i<1000; i++)
    s.push(i);
  for (int i=999;i>=0; i--)
  {
    ASSERT_EQ(i,s.top());
    s.pop();
    ASSERT_EQ(i,s.size());
  }
}

TEST(GraderStackTest, ClearWhenEmpty)
{
  // Create stack with default constructor
  // Call clear
  // Test whether size is 0 and isEmpty is true
  Stack<int> s;
  s.clear();
  ASSERT_EQ(0,s.size());
  ASSERT_TRUE(s.isEmpty());
}

TEST(GraderStackTest, ClearWhenNotEmpty)
{
  // Create stack with default constructor
  // Push some values onto stack
  // Call clear
  // Test whether size is 0 and isEmpty is true
  Stack<int> s;
  for (int i=0; i<100; i++)
    s.push(i);
  s.clear();
  ASSERT_EQ(0,s.size());
  ASSERT_TRUE(s.isEmpty());
}

TEST (GraderStackTest, AssignmentToEmpty)
{
  // Create stack S1 with default constructor
  // Push multiple data values onto stack S1
  // Create a second stack S2 with default constructor
  // Set S1 = S2
  // Test whether size of S1 is now 0
  Stack<int> s1;
  for (int i=0; i<100; i++)
    s1.push(i);
  ASSERT_EQ(100,s1.size());
  Stack<int> s2;
  s1 = s2;
  ASSERT_EQ(0,s1.size());
}

TEST (GraderStackTest, AssignmentToNonEmpty)
{
  // Create stack S1 with default constructor
  // Push multiple data values onto stack S1
  // Create a second stack S2 with default constructor
  // Set S2 = S1
  // Test whether size of stack S1 is now size of stack S2
  // For each value in stack S1, test whether its top is same as the top
  // of stack S2, then pop a value from each stack and repeat 
  // (until the two stacks are empty)
  Stack<int> s1;
  for (int i=0; i<10; i++)
    s1.push(i);
  Stack<int> s2;
  s2=s1;
  ASSERT_EQ(s1.size(), s2.size());
  for (int i = 0; i < 10; i++)
  {
      ASSERT_EQ(s1.top(), s2.top());
      s1.pop(); s2.pop();
  }
}

TEST(GraderStackTest, AssignmentSelf)
{
  // Create stack with default constructor
  // Push multiple data values onto that stack
  // Assign stack to itself
  // Test whether size is same as before
  // For each value in stack, test whether its top is what it should be
  // (based on the values that you pushed), then pop it, and repeat 
  // (until stack is empty)
  Stack<int> a;
  for (int i=0; i<10; i++)
    a.push(i);
  a=a;
  ASSERT_EQ(10, a.size());
  for (int i = 9; i >= 0; i--)
  {
      ASSERT_EQ(i, a.top());
      a.pop();
  }
}

TEST(GraderStackTest, EqualityAreEqual)
{
  // Create stack with default constructor
  // Push multiple data values onto that stack
  // Create second stack with copy constructor (copying from first stack)
  // Test whether first stack == second stack, and vice-versa
  Stack<int>a;
  for (int i=0; i<10; i++)
    a.push(i);
  Stack<int>b(a);
  ASSERT_TRUE(b==a);
  ASSERT_TRUE(a==b);
}

TEST(GraderStackTest, EqualityAreSame)
{
  // Create stack with default constructor
  // Push multiple data values onto that stack
  // Test whether stack == itself
  Stack<int> a;
  for (int i=0; i<10; i++)
    a.push(i);
  ASSERT_TRUE(a==a);
}

TEST(GraderStackTest, EqualityAreNotTheSame)
{
  // Create two stacks with default constructor
  // Push multiple data values into first stack
  // Push same number of data values into second stack, but use
  // different values
  // Test whether first stack == second stack, and vice-versa
  Stack<int> a,b;
  for (int i=0; i<10; i++)
  {
    a.push(i);
    b.push(i+1);
  }
  ASSERT_FALSE(a==b);
  ASSERT_FALSE(b==a);
}

TEST(GraderStackTest, EqualityEmptyNonEmpty)
{
  // Create two stacks with default constructor
  // Push multiple data values into first stack
  // Test whether first stack == second stack, and vice-versa
  Stack<int> a,b;
  for (int i=0; i<10; i++)
    a.push(i);
  ASSERT_FALSE(a==b);
  ASSERT_FALSE(b==a);
}


