/*  test_stack.h
    Test cases for stack
    Nathan Eloe & Jennifer Leopold
 */

#include "Stack.h"
#include <gtest/gtest.h>
#include <stdexcept>

TEST (StackTest, DefaultConstructor)
{ 
  // Create stack with default constructor
  // Test whether size is 0 and isEmpty is true
  Stack<int> s;
  
  ASSERT_EQ(0, s.size());
  ASSERT_TRUE(s.isEmpty());
}

TEST (StackTest, PushPushesToTopSingle)
{
  // Create stack with default constructor
  // Push one data value
  // Test whether size is 1, isEmpty is false, and
  // whether top is the value you pushed
  Stack<int> s;
  
  s.push(12);
  ASSERT_EQ(1, s.size());
  ASSERT_FALSE(s.isEmpty());
  ASSERT_EQ(12,s.top());
}

TEST (StackTest, PushPushesToTopMulti)
{
  // Create stack with default constructor
  // Push multiple data values
  // After each push, test whether size is # values pushed
  // to that point, and whether top is the most recently pushed value
  Stack<int> s;
  
  s.push(7);
  ASSERT_EQ(1, s.size());
  ASSERT_EQ(7, s.top());
  
  s.push(4);
  ASSERT_EQ(2, s.size());
  ASSERT_EQ(4, s.top());
  
  s.push(6);
  ASSERT_EQ(3, s.size());
  ASSERT_EQ(6, s.top());
  
  s.push(23);
  ASSERT_EQ(4, s.size());
  ASSERT_EQ(23, s.top());
}

TEST (StackTest, TopThrowsExceptionEmpty)
{
  // Create stack with default constructor
  // Test whether exception is thrown when top is called
  Stack<int> s;
  
  ASSERT_THROW(s.top(), std::length_error);
}

TEST(StackTest, PopThrowExceptionEmpty)
{
  // Create stack with default constructor
  // Test whether exception is thrown when pop is called
  Stack<int> s;
  
  ASSERT_THROW(s.pop(), std::length_error);
}

TEST(StackTest, PopRemovesOnly)
{
  // Create stack with default constructor
  // Push one value, then pop
  // Test whether resulting size is 0
  Stack<int> s;
  
  s.push(5);
  s.pop();
  ASSERT_EQ(0, s.size());
}

TEST(StackTest, PopRemovesTop)
{
  // Create stack with default constructor
  // Push multiple data values
  // For each value in stack, test if top is the value most recently pushed
  // Then pop, and test whether size of stack is one less than before
  Stack<int> s;
  
  s.push(4);
  ASSERT_EQ(4, s.top());
  
  s.push(23);
  ASSERT_EQ(23, s.top());
  
  s.push(12);
  ASSERT_EQ(12, s.top());
  
  s.pop();
  ASSERT_EQ(2, s.size());
}

TEST(StackTest, ClearWhenEmpty)
{
  // Create stack with default constructor
  // Call clear
  // Test whether size is 0 and isEmpty is true
  Stack<int> s;
  
  s.clear();
  ASSERT_EQ(0, s.size());
  ASSERT_TRUE(s.isEmpty());
}

TEST(StackTest, ClearWhenNotEmpty)
{
  // Create stack with default constructor
  // Push some values onto stack
  // Call clear
  // Test whether size is 0 and isEmpty is true
  Stack<int> s;
  
  s.push(7);
  s.push(8);
  s.push(12);
  s.push(88);
  s.push(27);
  
  s.clear();
  ASSERT_EQ(0, s.size());
  ASSERT_TRUE(s.isEmpty());
}

TEST (StackTest, AssignmentToEmpty)
{
  // Create stack S1 with default constructor
  // Push multiple data values onto stack S1
  // Create a second stack S2 with default constructor
  // Set S1 = S2
  // Test whether size of S1 is now 0
  Stack<int> s;
  
  s.push(7);
  s.push(23);
  s.push(32);
  s.push(66);
  
  Stack<int> s2;
  s = s2;
  ASSERT_EQ(0, s.size());
}

TEST (StackTest, AssignmentToNonEmpty)
{
  // Create stack S1 with default constructor
  // Push multiple data values onto stack S1
  // Create a second stack S2 with default constructor
  // Set S2 = S1
  // Test whether size of stack S1 is now size of stack S2
  // For each value in stack S1, test whether its top is same as the top
  // of stack S2, then pop a value from each stack and repeat 
  // (until the two stacks are empty)
  Stack<int> s;
  
  s.push(33);
  s.push(78);
  s.push(45);
  s.push(898);
  
  Stack<int> s2;
  
  s2 = s;
  ASSERT_EQ(s.size(), s2.size());
  ASSERT_EQ(s.top(), s2.top());
  
  s.pop();
  s2.pop();
  ASSERT_EQ(s.top(), s2.top());
  
  s.pop();
  s2.pop();
  ASSERT_EQ(s.top(), s2.top());
  
  s.pop();
  s2.pop();
  ASSERT_EQ(s.top(), s2.top());
  
  s.pop();
  s2.pop();
}

TEST(StackTest, AssignmentSelf)
{
  // Create stack with default constructor
  // Push multiple data values onto that stack
  // Assign stack to itself
  // Test whether size is same as before
  // For each value in stack, test whether its top is what it should be
  // (based on the values that you pushed), then pop it, and repeat 
  // (until stack is empty)
  Stack<int> s;

  s.push(23);
  s.push(8);
  s.push(76);
  
  s = s;
  
  ASSERT_EQ(3, s.size());
  ASSERT_EQ(76, s.top());
  s.pop();
  ASSERT_EQ(8, s.top());
  s.pop();
  ASSERT_EQ(23, s.top());
  s.pop();
}

TEST(StackTest, EqualityAreEqual)
{
  // Create stack with default constructor
  // Push multiple data values onto that stack
  // Create second stack with copy constructor (copying from first stack)
  // Test whether first stack == second stack, and vice-versa
  Stack<int> s;
  
  s.push(89);
  s.push(23);
  s.push(978);
  
  Stack<int> s2(s);
  ASSERT_TRUE(s == s2);
  ASSERT_TRUE(s2 == s);
}

TEST(StackTest, EqualityAreSame)
{
  // Create stack with default constructor
  // Push multiple data values onto that stack
  // Test whether stack == itself
  Stack<int> s;
  
  s.push(99);
  s.push(56);
  s.push(2);
  
  ASSERT_TRUE(s == s);
}

TEST(StackTest, EqualityAreNotTheSame)
{
  // Create two stacks with default constructor
  // Push multiple data values into first stack
  // Push same number of data values into second stack, but use
  // different values
  // Test whether first stack == second stack, and vice-versa
  Stack<int> s;
  Stack<int> s2;
  
  s.push(98);
  s.push(34);
  s.push(9);
  
  s2.push(45);
  s2.push(8);
  s2.push(12);
  
  ASSERT_FALSE(s == s2);
  ASSERT_FALSE(s2 == s);
}

TEST(StackTest, EqualityEmptyNonEmpty)
{
  // Create two stacks with default constructor
  // Push multiple data values into first stack
  // Test whether first stack == second stack, and vice-versa
  Stack<int> s;
  Stack<int> s2;
  
  s.push(34);
  s.push(84365);
  s.push(76);
  
  ASSERT_FALSE(s == s2);
  ASSERT_FALSE(s2 == s);
}


