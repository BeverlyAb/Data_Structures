/*		Beverly Abadines
		3/21/15
		// Priority_queue.h  -- a priority_queue implemented as a heap
*/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H



#include <vector>

using namespace std;

template <class T> 
class Priority_queue {
public:
   Priority_queue() : c() { }
   Priority_queue(const Priority_queue & p): c(p.c) { }
   Priority_queue & operator=(const Priority_queue & p) { c = p.c; return *this; }
   // vector destructor is automatically called when an obj of type Priority_queue is destroyed

   bool empty() { return c.empty(); }
   unsigned int size() { return c.size(); }
   void push(const T & x);
   void pop(); 
   T & top() { return c.front(); }
private:
   vector<T> c;
};

template <class T>
void Priority_queue<T>::push(const T & x)
{
	c.push_back(x);										// c[size() - 1]
	unsigned int i = size() - 1;
	T temp = x;
		while (i != 0 && c[i] > c[((i - 1) / 2)]) { 	// child > parent		
			c[i] = c[((i - 1) / 2)];
			c[((i - 1) / 2)] = temp;
			i = (i - 1)/ 2;			
			temp = c[i];
		}
	return;
}

template <class T>
void Priority_queue<T>::pop()
{
	c[0] = c[size() - 1];
	T temp = c[0];
	unsigned int i = 0;
	c.pop_back();	

	while((i != size() - 1 && (c[i] < c[2*i + 1])) || ((i != size() - 1 && (c[i] < c[2*i + 2])))) {	// parent to children
		if (c[2*i + 1] >= c[2*i + 2]) {
			c[i] = c[2*i + 1];
			c[2*i + 1] = temp;
			i =  2*i + 1;			
			temp = c[i]; 
		} else {
			c[i] = c[2*i + 2];
			c[2*i + 2] = temp;
			i = 2*i + 2;			
			temp = c[i];
		}
	}

	return;

}
#endif

