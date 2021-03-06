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
	assert(d.back() == 20);

	d.push_front(1);
	d.push_front(2);
	d.push_front(3);
	assert(d.front() == 3);
	assert(d.back() == 20);

	d.pop_back();
	d.pop_back();
	d.pop_back();
	assert(d.front() == 3);
	assert(d.back() == 2);

	d.push_back(1);
	d.push_back(0);

	Deque<int>::iterator i;
	int counter = 3;
	for (i = d.begin(); i != d.end(); i++)
		assert(*i == counter--);	// 3 2 1 0

	for (counter = 0; counter < d.size(); counter++)
		assert(d[counter] == d.size()-counter-1);

	i = d.begin() + 3;				// i = 3
	Deque<int>::iterator j(i), k, l;// j = i =3, k = default, which is index of 0, Deque of 0
	k  = j = i - 2;					// k = index 0 of Deque d, j = index 1 of d
	//assert(l == );
	//assert(k == d.begin());			// k index 0, want k index of 1
	//assert(i == d.begin() + 3);		// i never changed 
	//assert(j == d.begin() + 1);		// j = i - 2 = 1
	cout << "*i = " << *i << endl;
	cout << "*j = " << *j << endl;	
	cout << "*k = " << *k << endl;	// *k = 3
	// assert(*k == 2);

	cout << "Deque d\n";
	for (i = d.begin(); not(i == d.end()); ++i)
		cout << *i << " ";
	cout << endl;

	d.erase(d.begin()+3);
	d.erase(d.begin(), d.begin()+2);
	assert(d.size() == 1);
	assert(d[0] == 1);

	Deque<int> c(d);
	c.front() = 3;
	assert(c.back() == 3);

	c.push_front(1);
	c.insert(c.begin(), 0);
	c.insert(c.begin()+2, 2);

		
	cout << "Deque C\n";
	for (i = c.begin(); not(i == c.end()); ++i)
		cout << *i << " ";
	cout << endl;

	for (counter = 0; counter < c.size(); counter++)
		assert(c[counter] == counter);

//	cout << "SUCCESS\n";
}
