/* test_list.cpp
   Tests for the linked list class
   Nathan Eloe & Jennifer Leopold
 */

#include <gtest/gtest.h>
#include "linkedList.h"
#include "node.h"

//For readability, we're going to define an ASSERT_NULL macro
#define ASSERT_NULL ASSERT_FALSE
#define ASSERT_NOT_NULL ASSERT_TRUE


TEST(LinkedListTest, DefaultConstructor)
{
  LinkedList <int> a;
  ASSERT_EQ(0,a.size()) << "\n** Bad DefaultConstructor\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad DefaultConstructor\n";
  ASSERT_NULL(a.getTailPtr()) << "\n** Bad DefaultConstructor\n";
}

TEST(LinkedListTest, CopyConstructor)
{
  LinkedList<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  LinkedList<int> b(a);
  ASSERT_EQ(a.size(), b.size()) << "\n** Bad CopyConstructor\n";
  //Make sure lists match in both directions
  Node<int>* currA = a.getHeadPtr();
  Node<int>* currB = b.getHeadPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->m_data,currB->m_data)
            << "\n** Bad CopyConstructor Forwards\n";
    currA=currA->m_next;
    currB=currB->m_next;
  }
  currA = a.getTailPtr();
  currB = b.getTailPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->m_data,currB->m_data)
            << "\n** Bad CopyConstructor Backwards\n";
    currA=currA->m_prev;
    currB=currB->m_prev;
  }
}

TEST(LinkedListTest, CopyConstructorEmpty)
{
  LinkedList <int> a;
  LinkedList <int> b(a);
  ASSERT_NULL(b.getHeadPtr())<< "\n** Bad CopyConstructorEmpty\n";
  ASSERT_NULL(b.getTailPtr())<< "\n** Bad CopyConstructorEmpty\n";
  ASSERT_EQ(0,b.size())<< "\n** Bad CopyConstructorEmpty\n";
}

TEST(LinkedListTest, ClearWhenEmpty)
{
  LinkedList<int> a;
  a.clear();
  ASSERT_EQ(0,a.size())<< "\n** Bad ClearWhenEmpty\n";
  ASSERT_NULL(a.getHeadPtr())<< "\n** Bad ClearWhenEmpty\n";
  ASSERT_NULL(a.getTailPtr())<< "\n** Bad ClearWhenEmpty\n";
}

TEST(LinkedListTest, ClearWhenNotEmpty)
{
  LinkedList<int> a;
  for (int i=0; i<100; i++)
    a.insertAtHead(i);
  a.clear();
  ASSERT_EQ(0,a.size()) << "\n** Bad ClearWhenNotEmpty\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad ClearWhenNotEmpty\n";
  ASSERT_NULL(a.getTailPtr()) << "\n** Bad ClearWhenNotEmpty\n";
}

TEST(LinkedListTest, InsertOneAtHead)
{
  LinkedList <int> a;
  a.insertAtHead(1);
  ASSERT_EQ(1,a.size()) << "\n** Bad InsertOneAtHead\n";
  ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad InsertOneAtHead\n";
  ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad InsertOneAtHead\n";
  ASSERT_NULL(a.getHeadPtr()->m_next);
  ASSERT_NULL(a.getHeadPtr()->m_prev);
  ASSERT_EQ(1,a.getHeadPtr()->m_data) << "\n** Bad InsertOneAtHead\n";
  ASSERT_EQ(1,a.getTailPtr()->m_data) << "\n** Bad InsertOneAtHead\n";
}

TEST(LinkedListTest, InsertManyAtHead)
{
  LinkedList <int> a;
  a.insertAtHead(1);
  for (int i=2; i<100; i++)
  {
    a.insertAtHead(i);
    ASSERT_EQ(i,a.size()) << "\n** Bad InsertManyAtHead\n";
    ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad InsertManyAtHead\n";
    ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad InsertManyAtHead\n";
    ASSERT_NULL(a.getTailPtr()->m_next);
    ASSERT_EQ(i,a.getHeadPtr()->m_data) << "\n** Bad InsertManyAtHead\n";
    ASSERT_EQ(1,a.getTailPtr()->m_data) << "\n** Bad InsertManyAtHead\n";
    ASSERT_EQ(i-1,a.getHeadPtr()->m_next->m_data);
  }
}

TEST(LinkedListTest, InsertOneAtTail)
{
  LinkedList <int> a;
  a.insertAtTail(1);
  ASSERT_EQ(1,a.size()) << "\n** Bad InsertOneAtTail\n";
  ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad InsertOneAtTail\n";
  ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad InsertOneAtTail\n";
  ASSERT_NULL(a.getHeadPtr()->m_next);
  ASSERT_NULL(a.getHeadPtr()->m_prev);
  ASSERT_EQ(1,a.getHeadPtr()->m_data) << "\n** Bad InsertOneAtTail\n";
  ASSERT_EQ(1,a.getTailPtr()->m_data) << "\n** Bad InsertOneAtTail\n";
}

TEST(LinkedListTest, InsertManyAtTail)
{
  LinkedList <int> a;
  a.insertAtTail(1);
  for (int i=2; i<100; i++)
  {
    a.insertAtTail(i);
    ASSERT_EQ(i,a.size()) << "\n** Bad InsertManyAtTail\n";
    ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad InsertManyAtTail\n";
    ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad InsertManyAtTail\n";
    ASSERT_NULL(a.getHeadPtr()->m_prev);
    ASSERT_EQ(i,a.getTailPtr()->m_data) << "\n** Bad InsertManyAtTail\n";
    ASSERT_EQ(1,a.getHeadPtr()->m_data) << "\n** Bad InsertManyAtTail\n";
    ASSERT_EQ(i-1,a.getTailPtr()->m_prev->m_data);
  }
}

TEST(LinkedListTest, RemoveFirstOnly)
{
  LinkedList <int> a;
  a.insertAtHead(1);
  ASSERT_TRUE(a.removeFirstOccurrence(1)) << "\n** Bad RemoveFirstOnly\n";
  ASSERT_EQ(0,a.size()) << "\n** Bad RemoveFirstOnly\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad RemoveFirstOnly\n";
  ASSERT_NULL(a.getTailPtr()) << "\n** Bad RemoveFirstOnly\n";
}

TEST(LinkedListTest, RemoveFirstNotInList)
{
  LinkedList<int> a;
  ASSERT_FALSE(a.removeFirstOccurrence(1)) 
          << "\n** Bad RemoveFirstNotInList\n";
}

TEST(LinkedListTest, RemoveFirstHead)
{
  LinkedList<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  for (int i=9; i>=0; i--)
  {
    ASSERT_TRUE(a.removeFirstOccurrence(i)) << "\n** Bad RemoveFirstHead\n";
    ASSERT_EQ(i, a.size()) << "\n** Bad RemoveFirstHead\n";
    if (i>0)
    {
      ASSERT_EQ(i-1, a.getHeadPtr()->m_data) << "\n** Bad RemoveFirstHead\n";
      ASSERT_NULL(a.getHeadPtr()->m_prev);
    }
    else if (i==0)
    {
      ASSERT_NULL(a.getHeadPtr()) << "\n** Bad RemoveFirstHead\n";
      ASSERT_NULL(a.getTailPtr()) << "\n** Bad RemoveFirstHead\n";
    }
  }
}

TEST(LinkedListTest, RemoveFirstTail)
{
  LinkedList<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  for (int i=0; i<10; i++)
  {
    ASSERT_TRUE(a.removeFirstOccurrence(i)) << "\n** Bad RemoveFirstTail\n";
    ASSERT_EQ(9-i, a.size()) << "\n** Bad RemoveFirstTail\n";
    if (i<9)
    {
      ASSERT_EQ(i+1, a.getTailPtr()->m_data);
      ASSERT_NULL(a.getTailPtr()->m_next);
    }
    else if (i==0)
    {
      ASSERT_NULL(a.getHeadPtr()) << "\n** Bad RemoveFirstTail\n";
      ASSERT_NULL(a.getTailPtr()) << "\n** Bad RemoveFirstTail\n";
    }
  }
}

TEST(LinkedListTest, RemoveFirstMiddle)
{
  LinkedList<int> a;
  for (int i=0; i<10; i++)
    a.insertAtTail(i);
  ASSERT_TRUE(a.removeFirstOccurrence(5)) << "\n** Bad RemoveFirstMiddle\n";
  ASSERT_EQ(9,a.size()) << "\n** Bad RemoveFirstMiddle\n";
  int i=0;
  Node<int>* currA = a.getHeadPtr();
  while (currA)
  {
    ASSERT_EQ(i,currA->m_data) << "\n** Bad RemoveFirstMiddle\n";
    currA=currA->m_next;
    i++;
    if (i==5)
      i++;
  }
}

TEST(LinkedListTest, RemoveAllNotInList)
{
  LinkedList<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_EQ(0,a.removeAllOccurrences(11)) << "\n** Bad RemoveAllNotInList\n";
  ASSERT_EQ(10,a.size()) << "\n** Bad RemoveAllNotInList\n";
  ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad RemoveAllNotInList\n";
  ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad RemoveAllNotInList\n";
}

TEST(LinkedListTest, RemoveAllAllInList)
{
  LinkedList<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(1);
  ASSERT_EQ(10,a.removeAllOccurrences(1)) << "\n** Bad RemoveAllAllInList\n";
  ASSERT_EQ(0,a.size()) << "\n** Bad RemoveAllAllInList\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad RemoveAllAllInList\n";
  ASSERT_NULL(a.getTailPtr()) << "\n** Bad RemoveAllAllInList\n";
}

TEST(LinkedListTest, RemoveAllSomeInList)
{
  LinkedList<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i%2);
  ASSERT_EQ(5,a.removeAllOccurrences(1)) << "\n** Bad RemoveAllSomeInList\n";
  ASSERT_EQ(5,a.size()) << "\n** Bad RemoveAllSomeInList\n";
  ASSERT_EQ(0,a.getHeadPtr()->m_data) << "\n** Bad RemoveAllSomeInList\n";
  ASSERT_EQ(0,a.getTailPtr()->m_data) << "\n** Bad RemoveAllSomeInList\n";
}

TEST(LinkedListTest, IsEmptyWhenEmpty)
{
  LinkedList<int>a;
  ASSERT_TRUE(a.isEmpty()) << "\n** Bad IsEmptyWhenEmpty\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad IsEmptyWhenEmpty\n";
  ASSERT_NULL(a.getTailPtr()) << "\n** Bad IsEmptyWhenEmpty\n";
}

TEST(LinkedListTest, IsEmptyWhenNotEmpty)
{
  LinkedList<int>a;
  a.insertAtHead(1);
  ASSERT_FALSE(a.isEmpty()) << "\n** Bad IsEmptyWhenNotEmpty\n";
  ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad IsEmptyWhenEmpty\n";
  ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad IsEmptyWhenEmpty\n";
}

TEST(LinkedListTest, AssignmentOperator)
{
  LinkedList<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  LinkedList<int> b;
  b=a;
  ASSERT_EQ(a.size(), b.size()) << "\n** Bad AssignmentOperator\n";
  //Make sure the head and tail match
  ASSERT_EQ(a.getHeadPtr()->m_data, b.getHeadPtr()->m_data) 
          << "\n** Bad AssignmentOperator\n";
  ASSERT_EQ(a.getTailPtr()->m_data, b.getTailPtr()->m_data) 
          << "\n** Bad AssignmentOperator\n";
  Node<int>* currA = a.getHeadPtr();
  Node<int>* currB = b.getHeadPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->m_data,currB->m_data) 
            << "\n** Bad AssignmentOperator Forwards\n";
    currA=currA->m_next;
    currB=currB->m_next;
  }
  currA = a.getTailPtr();
  currB = b.getTailPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->m_data,currB->m_data)
            << "\n** Bad AssignmentOperator Backwards\n";
    currA=currA->m_prev;
    currB=currB->m_prev;
  }
}

TEST(LinkedListTest, AssignmentOperatorSelfAssignment)
{
  LinkedList<int>a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  a=a;
  //Make sure we didn't delete ourselves :/
  ASSERT_EQ(9,a.getHeadPtr()->m_data) 
          << "\n** Bad AssignmentOperatorSelfAssignment\n";
  ASSERT_EQ(0,a.getTailPtr()->m_data) 
          << "\n** Bad AssignmentOperatorSelfAssignment\n";
}

TEST(LinkedListTest, EqualityAreEqual)
{
  LinkedList<int>a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  LinkedList<int>b(a);
  ASSERT_TRUE(b==a) << "\n** Bad EqualityAreEqual\n";
  ASSERT_TRUE(a==b) << "\n** Bad EqualityAreEqual\n";
  Node<int>* currA = a.getHeadPtr();
  Node<int>* currB = b.getHeadPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->m_data,currB->m_data) 
            << "\n** Bad EqualityAreEqual Forwards\n";
    currA=currA->m_next;
    currB=currB->m_next;
  }
  currA = a.getTailPtr();
  currB = b.getTailPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->m_data,currB->m_data)
            << "\n** Bad EqualityAreEqual Backwards\n";
    currA=currA->m_prev;
    currB=currB->m_prev;
  }
}

TEST(LinkedListTest, EqualityAreSame)
{
  LinkedList<int>a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_TRUE(a==a) << "\n** Bad EqualityAreSame\n";
  ASSERT_EQ(0, a.getTailPtr()->m_data) << "\n** Bad EqualityAreSame Tail\n";
  ASSERT_EQ(9, a.getHeadPtr()->m_data) << "\n** Bad EqualityAreSame Head\n";
}

TEST(LinkedListTest, EqualityAreNotTheSame)
{
  LinkedList<int>a,b;
  for (int i=0; i<10; i++)
  {
    a.insertAtHead(i);
    b.insertAtHead(i+1);
  }
  ASSERT_FALSE(a==b) << "\n** Bad EqualityAreNotTheSame\n";
  ASSERT_FALSE(b==a) << "\n** Bad EqualityAreNotTheSame\n";
  ASSERT_EQ(0, a.getTailPtr()->m_data) 
          << "\n** Bad EqualityAreNotTheSame a Tail\n";
  ASSERT_EQ(1, b.getTailPtr()->m_data) 
          << "\n** Bad EqualityAreNotTheSame b Tail\n";
}

TEST(LinkedListTest, EqualityEmptyNonEmpty)
{
  LinkedList<int>a,b;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_FALSE(b==a) << "\n** Bad EqualityEmptyNonEmpty\n";
  ASSERT_EQ(0, a.getTailPtr()->m_data) 
          << "\n** Bad EqualityEmptyNonEmpty a Tail\n";
  ASSERT_NULL(b.getHeadPtr()) << "\n** Bad EqualityEmptyNonEmpty b Head\n";
  ASSERT_NULL(b.getTailPtr()) << "\n** Bad EqualityEmptyNonEmpty b Tail\n";
}

TEST(LinkedListTest, EqualityNonEmptyEmpty)
{
  LinkedList<int>a,b;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_FALSE(a==b) << "\n** Bad EqualityNonEmptyEmpty\n";
  ASSERT_NULL(b.getHeadPtr()) << "\n** Bad EqualityNonEmptyEmpty b Head\n";
  ASSERT_NULL(b.getTailPtr()) << "\n** Bad EqualityNonEmptyEmpty b Tail\n";
}

TEST(LinkedListTest, RemoveAtHeadThrowsException)
{
  LinkedList<int> a;
  ASSERT_THROW(a.removeAtHead(),std::length_error);
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}

TEST(LinkedListTest, RemoveAtHeadRemoveOne)
{
  LinkedList<int> a;
  a.insertAtHead(0);
  a.removeAtHead();
  ASSERT_EQ(0,a.size());
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}

TEST(LinkedListTest, RemoveAtHeadRemoveMany)
{
  LinkedList<int> a;
  for (int i=0; i<100; i++)
    a.insertAtTail(i);
  for (int i=0; i<100; i++)
  {
    a.removeAtHead();
    ASSERT_FALSE(a.find(i));
    ASSERT_EQ(100-i-1,a.size());
    for (int j=i+1; j<100; j++)
      ASSERT_TRUE(a.find(j));
  }
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}

TEST(LinkedListTest, RemoveAtTailThrowsException)
{
  LinkedList<int> a;
  ASSERT_THROW(a.removeAtTail(),std::length_error);
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}

TEST(LinkedListTest, RemoveAtTailRemoveOne)
{
  LinkedList<int> a;
  a.insertAtHead(0);
  a.removeAtTail();
  ASSERT_EQ(0,a.size());
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}

TEST(LinkedListTest, RemoveAtTailRemoveMany)
{
  LinkedList<int> a;
  for (int i=0; i<100; i++)
    a.insertAtHead(i);
  for (int i=0; i<100; i++)
  {
    a.removeAtTail();
    ASSERT_FALSE(a.find(i));
    ASSERT_EQ(100-i-1,a.size());
    for (int j=i+1; j<100; j++)
      ASSERT_TRUE(a.find(j));
  }
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}
