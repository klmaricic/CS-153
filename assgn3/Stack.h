//Kelsey Maricic
//3/4/12
//stack.h 
//Definition of a class for a stack

#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include "linkedList.h"

template <class T>
class Stack : protected LinkedList<T>
{
  public:
    //Purpose: default constructor
    //Post conditions: current size set to 0, top
    //pointers set to NULL
    Stack() {}
    
    //Purpose: copy constructor
    //Parameters:cpy is stack that is to be copied
    //Post conditions: this stack contains same data values, in the same
    //order, as in cpy
    Stack(const Stack<T>& cpy);
    
    //Purpose: destructor
    //Post conditions: current size is now 0, stack copntains no data
    //and all memory deallocated(via clear())
    ~Stack() {}
    
    //Purpose: accessor function for the current # data values in stack
    //Returns: current size of the stack
    unsigned int size();
    
    //Purpose: effectively empties the stack
    //Post conditions: current size set to 0,head ptr set to NULL,
    //and all dynamically allocated memory for nodes deallocated
    void clear();
    
    //Purpose: determines wether the stack is empty
    //Returns: true if stack is empty. Otherwise it returns false
    bool isEmpty();
    
    //Purpose: returns value of top data value in the stack
    //Returns: value of top data value in the stack
    const T& top();
    
    //Purpose: puts the data value x at the top of the stack
    //Parameters: x is data value to be inserted
    //Postconditions: current size of stack incremented by 1,
    //head pointer now points to a node with data value x, the new node's
    //next ptr points to what was previously the first in the stack, and
    //its prev ptr points to NULL
    void push(const T& x);
    
    //Purpose: removes the data value at the beginning of the stack
    //Post conditions: current size of the stack decremented by 1, head 
    //pointer now points to whatever the removed node's next ptr was pointing
    //at, and that node's prev ptr is NULL
    //Exceptions: if the stack is empty, then throw std::length_error
    void pop();
    
    // Purpose: performs a deep copy of the data from rhs into this stack
    // Parameters: rhs is stack to be copied
    // Returns: *this
    // Postconditions: this stack contains same data values (in the same order)
    // as are in rhs; any memory previously used by this stack has been
    // deallocated                    
    Stack<T>& operator=(const Stack<T>& rhs);
    
    // Purpose: determines whether this stack is identical to rhs stack in
    // terms of data values and their order in the stack
    // Parameters: rhs is stack to be compared to this stack
    // Returns: true if stacks are identical; otherwise, false            
    bool operator==(const Stack<T>& rhs) const;
};

#include "Stack.hpp"

#endif
  
    
    



