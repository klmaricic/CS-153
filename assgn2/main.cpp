/* file main.cpp
 * author Nathan Eloe (nwe5g8@mst.edu)
 * brief The generic gtest runner
 */
#include <iostream>
#include "linkedList.h"

using namespace std;

int main() {
	LinkedList<int> list;

	for(int i = 0; i < 100; i++)	
		list.insertAtTail(1);
	for(int i = 0; i < 100; i++)
		list.removeAtHead();
}
