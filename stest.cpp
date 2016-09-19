// test.cpp - a simple test program for Stack.h

#include <iostream>
#include <vector>
#include "Stack.h"

using namespace std;

main()
{
	Stack<int> s;      		// uses List as the default container
	s.push(5);				// front/back [5]
	s.push(6);				// front/back [6, 5]
	cout << s.top() << endl;// should return 6

	Stack<double, vector> v;// uses Vector as the container
	v.push(1.5);			// front/back [1.5]
	v.push(2.3);			// front/back [2.3, 1.5]
	v.pop();				// front/back [1.5]
	cout << v.top() << endl;// should return 1.5
}
