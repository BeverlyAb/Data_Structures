/************************************************************************************
Beverly Abadines
Queue.h
3/1/2015
***********************************************************************************/ 
#ifndef QUEUE_H
#define QUEUE_H



#include "../L5/List.h"

using namespace std;

//Use the following line for STL containers.
//template <class T, template <class T, class = allocator<T> > class Container = list>
template <class T, template <class T> class Container = List>
class Queue
{
public:
   //We don't need a constructor or destructor because the Container has/should have one
   //Queue(): container() { }
   //~Queue() { ~container(); }
   bool empty() const { return container.empty();};			// returns true if Queue is empty(); O(1)
   unsigned int size() const { return container.size();};	// returns my_size;  O(1)
   void push(const T & x) { container.push_back(x); };		// inserts value x, at the back of Queue; O(1)
   void pop() { container.pop_front(); };					// deletes value at the front of Queue; O(1)
   T & back() { container.back(); };						// returns value at the back of Queue; O(1)
   T & front() { container.front(); };						// returns value at the front of Queue; O(1)

private:
   Container<T> container;
};
#endif
