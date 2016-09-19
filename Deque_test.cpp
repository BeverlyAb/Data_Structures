// Deque_test.cpp

#include <iostream>
#include <cassert>

#include "Deque.h"

using namespace std;

main()
{
	Deque<int> d;

	d.push_back(10);
	d.push_back(20);
	assert(d.front() == 10);
	assert(d.back() == 20);			// front [10, 20] back

	d.push_front(1);				// front [3, 2, 1, 10, 20] back
	d.push_front(2);
	d.push_front(3);
	assert(d.front() == 3);
	assert(d.back() == 20);

	d.pop_back();					
	d.pop_back();
	d.pop_back();
	assert(d.front() == 3);
	assert(d.back() == 2);			// front [3, 2] back

	d.push_back(1);
	d.push_back(0);					// front [3, 2, 1, 0] back
									// 		  0  1  2  3	
	Deque<int>::iterator i;
	int counter = 3;
	for (i = d.begin(); i != d.end(); i++)	
		assert(*i == counter--);			

	for (counter = 0; counter < d.size(); counter++)	// d[counter] = 3, 2, 1, 0
		assert(d[counter] == d.size()-counter-1);		//	.s-c-1	  = 3, 2, 1, 0   

	i = d.begin() + 3;				// i = 3
	Deque<int>::iterator j(i), k;	// j = index 3 of Deque d, k is at default which is index 0 of Deque 0 
	k = j = i - 2 ;					// k = j = 1; same as j = i - 2; k = j;
	assert(*k == 2);				
    
	for (i = d.begin(); not(i == d.end()); ++i) // checks bool == 
		cout << *i << " ";
	cout << endl;

	d.erase(d.begin()+3);				// 3, 2, 1
	d.erase(d.begin(), d.begin()+2);	// 1

	assert(d.size() == 1);				// 1
	assert(d[0] == 1);					// 1

	Deque<int> c(d);
	c.front() = 3;
	assert(c.back() == 3);

	c.push_front(1);
	c.insert(c.begin(), 0);
	c.insert(c.begin()+2, 2);

	for (i = c.begin(); not(i == c.end()); ++i) // 0 1 2 3
		cout << *i << " ";
	cout << endl;

	for (counter = 0; counter < c.size(); counter++)
		assert(c[counter] == counter);

	cout << "SUCCESS\n"; 
}


