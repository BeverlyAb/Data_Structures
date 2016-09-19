/************************************************************************************
Beverly Abadines
Stack.h
3/1/2015
***********************************************************************************/ 

#ifndef STACK_H
#define STACK_H

//#include "../L5/List.h"
#include <list>
using namespace std;

//Use the following line for STL containers.
template <class T, template <class T, class = allocator<T> > class Container = list>
//template <class T, template <class T> class Container = List>
class Stack
{
public:
   //We don't need a constructor or destructor because the Container has/should have one
   //Stack(): container() { }
   //~Stack() { ~container(); }
   bool empty() const { return container.empty();};
   unsigned int size() const { return container.size();};
   void push(const T & x) { container.push_back(x); };
   void pop() { container.pop_back(); };
   T & top() {container.back(); };

private:
   Container<T> container;
};
#endif

