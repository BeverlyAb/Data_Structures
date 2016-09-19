/******************************************************************************
	Beverly Abadines
	Lab_4
	Vector.h
	2/9/15-2/16/15
	Vector Data Structure
*****************************************************************************/
#ifndef VECTOR_H
#define VECTOR_H

// Vector.h

using namespace std;

#include <iterator>

template <class T>
class Vector
{
public:

   typedef T * iterator;

   Vector();
   Vector(unsigned int size);
   Vector(unsigned int size, const T & initial);
   Vector(const Vector<T> & v);           // copy constructor
   ~Vector();							  // destructor
	// accessors
   unsigned int capacity() const;         // return capacity of vector (in elements)
   unsigned int size() const;             // return the number of elements in the vector
   bool empty() const;					  // not an accessor 
	
   iterator begin();                      // return an iterator pointing to the first element
   iterator end();                        // return an iterator pointing to one past the last element
   T & front();                           // return a reference to the first element
   T & back();                            // return a reference to the last element
   
   // mutators
   void push_back(const T & value);       // add a new element
   void pop_back();                       // remove the last element

   void reserve(unsigned int capacity);   // adjust capacity
   void resize(unsigned int size);        // adjust size
	// operator
   T & operator[](unsigned int index);    // return reference to numbered element
   Vector<T> & operator=(const Vector<T> &);

private:
   unsigned int my_size;				 // can act like a pointer for final element (my_size - 1)
   unsigned int my_capacity;
   T * buffer;							  // buffer is a pointer that points to a type T array
};
#endif

// Default Constructor
template <class T>
Vector<T>::Vector() // O(1);
{
	my_size = 0;
	my_capacity = 0;
	buffer = 0;
} // Default

// Constructor w/ size parameter
template <class T>
Vector<T>::Vector(unsigned int size) // O(1)
{
	my_size = size;
	my_capacity = size;
	buffer = new T[my_capacity];

	for (int i = 0; i < my_size; i++) {
		buffer[i] = T();
	}
} // Constructor

// Constructor w/ size and content parameter
template <class T>
Vector<T>::Vector(unsigned int size, const T & initial) // O(n)
{
	my_size = size;
	my_capacity = size;
	buffer = new T[my_capacity];

	for (int i = 0; i < my_size; i++) {
		buffer[i] = initial;
	}
} // Constructor

// Constructor w/ vector paramter
template <class T>
Vector<T>:: Vector(const Vector<T> & v) // O(n)
{
	int size =	v.size();
	my_size = size;
	my_capacity = size;
	buffer = new T[my_capacity];

	for (int i = 0; i < size; i++) {
		buffer[i] = v.buffer[i];
	}
} // Constructor

// Destructor
template <class T> 
Vector<T>::~Vector() // O(1)
{
	// my_size = 0;		Stack memory is deleted auto. from command
	// my_capacity = 0;
	delete [] buffer;	// Only heap memory needs to be deleted
} // Destructor

// returns my_capacity
template <class T>
unsigned int Vector<T>::capacity() const // O(1)
{
	return my_capacity;
} // capacity()

// returns my_size
template <class T>
unsigned int Vector<T>::size() const // O(1)
{
	return my_size;
} // size()

// returns true if vector is empty
template <class T>
bool Vector<T>:: empty() const // O(1)
{
	return my_size == 0;
} // empty()

// returns pointer to first element
template <class T>
typename Vector<T>::iterator Vector<T>::begin() // O(1)
{
	return buffer;
} // begin()

// returns pointer to 1 past the last element
template <class T>
typename Vector<T>::iterator Vector<T>::end() // O(1) 
{
	return begin() + my_size;
} // end()

// returns value of the first element
template <class T>
T & Vector<T>::front() // O(1)
{
	return buffer[0]; // return *begin;
} // front()

// returns value of last element
template <class T>
T & Vector<T>::back() // O(1)
{
	return buffer[my_size -1]; // return *end;
} // back()

// remove last element
template <class T>
void Vector<T>::pop_back() // O(1)
{
	my_size -= 1;
	my_capacity++;
} // O(1)

// enlarge my_capacity 
template <class T>
void Vector<T>::reserve(unsigned int capacity) // O(1)
{
	if (my_capacity < capacity) {
		my_capacity = capacity;
		if (buffer == 0) {
			my_size = 0;
		} else {
			T * temp_buffer = new T[my_capacity];	// create temp buffer

			for (int i = 0; i < my_size - 1; i++) {	// copy buffer to temp
				temp_buffer[i] = buffer[i];
			}
			delete [] buffer;
			buffer = new T[my_capacity];			// create buffer w/ new capacity

			for (int i = 0; i < my_size - 1; i++) { // copy temp to buffer w/ new capacity
				buffer[i] = temp_buffer[i];
			}
			delete [] temp_buffer;
		}
	} return;// else dont change anything
} // reserve()

// shrink or grow size
template <class T>
void Vector<T>::resize(unsigned int size) // O(1)
{
	if (size > my_capacity) { // allocate memory if necessary 
		reserve(size);		  // my_capacity = size;	
	}
	my_size = size;
	my_capacity -= size;
} //resize()

// add element to end of vector
template <class T>
void Vector<T>::push_back(const T & value) // O(1)
{
	if (buffer == 0) { 					// if empty buffer
		my_capacity = 5;				// allocate space
		my_size = 0;

		delete [] buffer;	
		buffer = new T[my_capacity];	// create buffer w/ larger capacity

	} else if (my_size >= my_capacity) {// allocate space
		reserve(my_capacity + 5);
	}
	buffer[my_size++] = value;			// make last element = value, increase size AFTERWARDS
	my_capacity--;						// account for my_capacity
}

// returns value at index
template <class T> 
T & Vector<T>::operator[](unsigned int index) //O(1)
{
	return buffer[index];
} // operator[]

// sets buffer = to vector
template <class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & v) // O(n)
{
	delete [] buffer;				// start from scratch

	my_size = v.size();
	my_capacity = v.size();

	buffer = new T[my_capacity];	// allocate space according to v

	for (int i = 0; i < my_size; i++) { // copy v onto buffer
		buffer[i] = v[i];
	}
} // operator =
