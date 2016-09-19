/*****************************************************************************************
	Beverly Abadines
	Deque.h	(Deque Data Structure)
	3/9/15
****************************************************************************************/	
#ifndef DEQUE_H
#define DEQUE_H

// Deque.h - an implementation of double-ended queue

#include <vector>

using namespace std;

template <class T> class DequeIterator;

template <class T>
class Deque 
{
public:
	typedef DequeIterator<T> iterator;
	
	Deque(): vecOne(), vecTwo() { } //Default Constructor O(1) 
	Deque(const unsigned int size, const T& initial): vecOne(size/2, initial), vecTwo(size-(size/2), initial) { } // Constructor given size and initial value O(n)
	Deque(const Deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { } // Copy Constructor: given Deque O(n)
    ~Deque() { } // destructors for vecOne and vecTwo are automatically called O(1)
                     // never call a destructor explicitly
  
 	Deque & operator=(const Deque<T> & d);	// operators
	T & operator[](unsigned int);

	T & front();							// Accesors (except empty())
	T & back();
	bool empty();
	int size();
	iterator begin();
	iterator end();

	void push_front(const T & value);		// Mutators
	void push_back(const T & value);
	void pop_front();
	void pop_back();
	void erase(const iterator &);
	void erase(const iterator &, const iterator &);
	void insert(const iterator &, const T &);
protected:
	vector<T> vecOne;
	vector<T> vecTwo;
};

template <class T> // sets vectors equal to d's vectors
Deque<T> & Deque<T>::operator=(const Deque<T> & d) // O(1)
{
	//~Deque();
	vecOne = d.vecOne;
	vecTwo = d.vecTwo;
	return *this;
} // =(d)
	
template <class T> // returns value at given index of Deque
T & Deque<T>::operator[](unsigned int index) // O(1)
{
	int n = vecOne.size();
	if (!vecOne.empty()) {
		if (index < n) {
			return vecOne[(n - 1) - index];
		} else {
			return vecTwo[index - n];
		}
	} else {
		return vecTwo[index];
	}
} // [](index)

template <class T> // returns value at the beginning of Deque
T & Deque<T>::front() // O(1) 
{
	if (vecOne.empty()) {
		return vecTwo.front();
	} else {
		return vecOne.back();
	}
} // front()

template <class T> // returns value at the end ( index = size() -1 )of Deque
T & Deque<T>::back() // O(1)
{
	if (vecTwo.empty()) {
		return vecOne.front();
	} else {
		return vecTwo.back();
	}
} // back()

template <class T> // returns true if both vectors are empty
bool Deque<T>::empty() // O(1)
{
	return vecOne.empty() && vecTwo.empty();
} // empty()

template <class T> // returns number of elements in Deque
int Deque<T>::size() // O(1)
{
	return (vecOne.size() + vecTwo.size());
} // size()

template <class T> // returns iterator at beginning of Deque
typename Deque<T>::iterator Deque<T>::begin()  // O(1)
{
	return iterator(this, 0); //DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { }
} // begin()

template <class T> // returns iterator one past last element of Deque
typename Deque<T>::iterator Deque<T>::end() // O(1)
{
	return iterator(this, size());
} // end()

template <class T> // inserts value at the beginning of Deque
void Deque<T>::push_front(const T & value) // O(n)
{
	vecOne.push_back(value);
} // push_front(value)

template <class T> //inserts value at the end of Deque
void Deque<T>::push_back(const T & value) // O(n)
{
	vecTwo.push_back(value);
} // push_back(value)

template <class T> // removes 1st element 
void Deque<T>::pop_front() // O(1)
{
	vecOne.pop_back();
} //pop_back()

template <class T> // removes last element
void Deque<T>::pop_back() // O(1)
{
	if (!vecTwo.empty()) {
		vecTwo.pop_back();
	} else {
		vecOne.erase(vecOne.begin());
	}
} // pop_back()

template <class T> // removes element at it_e
void Deque<T>::erase(const iterator & it_e) // O(n)
{
	int index = it_e.index;	// set index as the position of it_e
	int n = vecOne.size();
	
	if (index < n) {	// position is w/in vecOne
		vecOne.erase(vecOne.begin() + ((n - 1) - index)); // obj.erase(itr);
	} else {
		vecTwo.erase(vecTwo.begin() + (index - n));
	}
} // erase(it_e)

template <class T> // removes element from it_1 to one before it_2
void Deque<T>::erase(const iterator & it_1, const iterator & it_2) // O(n)
{
	int index1 = it_1.index; // want to deal w/ int, not itr
	int index2 = it_2.index;	
	int n1 = vecOne.size();
	int n2 = vecTwo.size();

	if ((index1 >= n1) && (index2 < n2)) {	// w/in vecTwo 
		vecTwo.erase((vecTwo.begin() + index1 - ((n1 / 2) + (n1 / 2))), (vecTwo.begin() +index2 - ((n1 /2) + (n1 / 2))));
	} else if ((index1 < n1) && (index2 <= n1)) { // w/in vecOne
		vecOne.erase((vecOne.begin() + ((n1 / 2) + (n1 / 2)) - index2), (vecOne.begin() + ((n1 / 2) + (n1 / 2) - index1)));
	} else  if (index1 < n1 && index2 > n1 && index2 < size()) { //Overlaps btwn 2 vectors
		vecOne.erase(vecOne.begin(), vecOne.begin() + (n1 - 1 - index1));
		vecTwo.erase(vecTwo.begin(), (vecTwo.begin() + index2 - (n1 /2 + n1 / 2))); 	
	} else if (index1 >= size() || index2 > size() || index1 < 0 || index2 < 0) { // itr are not w/in range of Deque
		return;
	}
} // erase(it_1, it_2)

template <class T> // inserts value one before it_r
void Deque<T>::insert(const iterator & it_r, const T & value) // O(n)
{
	int index = it_r.index;	// set index as the position of it_e
	int n = vecOne.size();
		
	if (index == 0) { // end of vecOne
		push_front(value); 
	} else if (index == size()) { // end of VecTwo
		push_back(value);
	} else if (((index < n)) && (index != 0)) { // somewhere in vecOne
		vecOne.insert(vecOne.begin() + ((n - 1) - index), value); // obj.insert(itr, val);
	} else if ((index >= n) && (index < size())){ // somewhere in vecTwo
		vecTwo.insert(vecTwo.begin() + (index - n), value);	
	} else if (index > size() || index < 0 ){ // itr not w/in range of Deque
		return;
	}
} // insert(itr, value)

/****************************************************************************************/

template <class T>
class DequeIterator {
	friend class Deque<T>;
	typedef DequeIterator<T> iterator;
public:
	DequeIterator(): theDeque(0), index(0) { } // Default Constructor O(1)
	DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { } // Constructor given pointer and index O(1)
	DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { } // Copy Constructor given iterator O(1)

	T & operator*();
	iterator & operator++(); 	// pre-increment
	iterator operator++(int); 	// post-increment
	iterator & operator--(); 	// pre -decrement
	iterator operator--(int);	// post- decrement
	bool operator==(const iterator & r);
	bool operator!=(const iterator & r);
	bool operator<(const iterator & r);
	T & operator[](unsigned int i);
	iterator operator=(const iterator & r); 
	iterator operator+(int i);
	iterator operator-(int i);
protected:
	Deque<T> * theDeque;		// pointer to Deque<T>
	int index;					// index is just a number, not an iterator
};
template <class T> // returns value of Deque at index 
T & DequeIterator<T>::operator*()
{
	return (* theDeque)[index]; // theDeque points to a more than 1 element bc it points to a deque, which contains more than 1 element as oppose to a buffer
}//	O(1)							// go through all positions in theDeque w/ (* theDeque)

template <class T> // INCREMENT iterator FIRST, then return value (pre)
typename DequeIterator<T>::iterator & DequeIterator<T>::operator++() // O(1) 
{
	++index;
	return *this; 
} // ++()

template <class T> // RETURN value at iterator FIRST, then increment iterator (post)
typename DequeIterator<T>::iterator DequeIterator<T>::operator++(int) // O(1)
{
	DequeIterator<T>::iterator clone(theDeque, index);
	index++;
	return clone;
} // ++(int)

template <class T> // DECREMENT iterator FIRST, then return value (pre)
typename DequeIterator<T>::iterator & DequeIterator<T>::operator--() // O(1)
{
	--index;
	return *this;
} // --()

template <class T> // RETURN value at iterator FIRST, then decrement iterator (post)
typename DequeIterator<T>::iterator DequeIterator<T>::operator--(int) // O(1)
{
	DequeIterator<T>::iterator clone(theDeque, index);
	index--;
	return clone;
} // --(int)

template <class T> // returns true if iterator shares the same Deque and index
bool DequeIterator<T>::operator==(const iterator & r) // O(1)	 	r is an iterator
{
	return ((theDeque == r.theDeque) && (index == r.index)); 	// theDeque is compared to whichever deque r is pointing to 
} // == (itr r)													// index is compared to the position of r

template <class T> // returns true if iterator does not share same Deque or index
bool DequeIterator<T>::operator!=(const iterator & r) // O(1)
{
	return ((theDeque != r.theDeque) || (index != r.index)); // not of (bool ==) DeMorgan
} // !=(itr r)

template <class T> // returns true if iterator shares same Deque and index is less than 
bool DequeIterator<T>::operator<(const iterator & r) // O(1)
{
	return ((theDeque == r.theDeque) && (index < r.index));
} // <(itr r)

template <class T> // returns value of Deque at index
T & DequeIterator<T>::operator[](unsigned int i) // O(1)
{
	return (* theDeque)[index + 1];
} // [](i)

template <class T> // Sets theDeque and index to whichever deque and index iterator is pointing to
typename DequeIterator<T>::iterator DequeIterator<T>::operator=(const iterator & r) // O(1)
{
	theDeque = r.theDeque; 	// Deque<T>
	index = r.index;		// int
	return *this;
} // =(itr r)

template <class T> // return following iterator from offset, i 
typename DequeIterator<T>::iterator DequeIterator<T>::operator+(int i) //O(1)
{
	return iterator(theDeque, index + i);	// Calls Constructor
} // +(int)

template <class T> // return prior iterator from offset, i
typename DequeIterator<T>::iterator DequeIterator<T>::operator-(int i) // O(1)
{
	return iterator(theDeque, index - i);	// Calls Constructor
} // -(int)
#endif

