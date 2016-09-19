// another_test.cpp

#include <iostream>
#include <cassert>

#include "Deque.h"

using namespace std;

main()
{
	Deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(4);
	d.push_back(5);
	d.push_back(6);	// 10,20, 30, 4, 5, 6
	
	assert(d.front() == 10);
	assert(d.back() == 6);	
	
	Deque<int>::iterator i;
	i = d.begin();
	cout << "d before erase\n";
	for (i = d.begin(); i != d.end(); i++)	{
		cout << *i << " ";
	} 
	cout << endl;
	i = d.begin();
	d.erase(i);	// 20, 30, 4, 5, 6
	assert(d.size() == 5);
	cout << "d after erase\n";	
	for (i = d.begin(); i != d.end(); i++)	{
		cout << *i << " ";
	} 
	cout << endl;	

	Deque<int> e;
	Deque<int>::iterator j;
	j = e.begin();
	e.push_back(3);
	e.push_back(2);
	e.push_back(1);
	e.push_back(0);		// 3, 2, 1, 0
	
	cout << "e before erase\n";	
	for (j = e.begin(); j != e.end(); j++)	{
		cout << *j << " ";
	} 
	cout << endl;

	e.erase(e.begin() + 3);	// 3, 2, 1
	cout << "e after 1st erase\n";	
	for (j = e.begin(); j != e.end(); j++)	{
		cout << *j << " ";
	} 
	cout << endl;
	
	e.erase(e.begin(), e.begin() + 2); // 1
	assert(e.back() == 1);
	assert(e.size() == 1);
	cout << "d after 2nd erase\n";	
	for (j = e.begin(); j != e.end(); j++)	{
		cout << *j << " ";
	} 
	cout << endl;
	
}
