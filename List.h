/******************************************************************************
	Beverly Abadines
	Lab_5
	List.h
	2/16/15-3/2/15
	List Data Structure
*****************************************************************************/
#ifndef LIST_H 
#define LIST_H

// List.h - a doubly-linked list

#include <algorithm>

using namespace std;

// forward declaration of classes defined in this header
template <class T> class Link;
template <class T> class List_iterator;

template <class T> 
class List
{
public:
   typedef List_iterator<T> iterator;

   List();									//Constructors
   List(const List<T> & l);	
   ~List();									//Destructors

   bool empty() const;						
   unsigned int size() const; 
   T & back() const;
   T & front() const;
   void push_front(const T & x);
   void push_back(const T & x);
   void pop_front();
   void pop_back();
   iterator begin() const;
   iterator end() const;
   void insert(iterator pos, const T & x);	// insert x before pos
   void erase(iterator & pos);             	// pos must be valid after erase() returns;
   List<T> & operator=(const List<T> & l);

protected:
   Link<T> * first_link;
   Link<T> * last_link;
   unsigned int my_size;
};

template <class T> //Default Constructor
List<T>::List() // O(1)
{
	first_link = 0;
    last_link = 0;
    my_size = 0;
} //List()

template <class T> //Constructor
List<T>::List(const List & l) //O(n)
{
	first_link = 0;
    last_link = 0;
    my_size = 0;
    for (Link<T> * current = l.first_link; current != 0; current = current->next_link) {
    	push_back(current->value); // dereference
	}
} // List(l)

template <class T> // Destructor
List<T>::~List() // O(n)
{
	Link <T> * first = first_link;
	while (first != 0) {
		Link <T> * next = first->next_link;
		delete first;
		first = next;
	}
} // ~List()

template <class T> // returns true is List is empty
bool List<T>::empty() const //O(1)
{
	return my_size== 0; //first_link == 0 ;
} // empty()

template <class T> // return size
unsigned int List<T>::size() const //O(1)
{
	return my_size;
} // return size

template <class T> // returns value of last link
T & List<T>::back() const // O(1)
{
	return last_link->value;
} // back()

template <class T> // returns value of first link
T & List<T>::front() const // O(1)
{
	return first_link->value;
} // front()

template <class T> // inserts link w/ value x,at the beginning of List
void List<T>::push_front(const T & x) // O(1)
{
	Link<T> * new_link = new Link<T> (x);
	if (empty()) {
		first_link = new_link; 
		last_link = new_link;
	} else {
		first_link->prev_link = new_link;
		new_link->next_link = first_link;
		first_link = new_link;
	}		
	my_size++;

	//insert(begin(), x);
} // push_front()

template <class T> // inserts link w/ value x, at the end of List
void List<T>::push_back(const T & x) // O(1)
{
	Link<T> * new_link = new Link<T> (x);
	if (empty()) {
		first_link = last_link = new_link;
	} else {
		last_link->next_link = new_link;
		new_link->prev_link = last_link;
		last_link = new_link;
	}		
	my_size++; 
	//insert(end(), x); 
} // push_back()

template <class T> // deletes last link
void List<T>::pop_back() // O(1)
{
	if (first_link == 0) {
		return; 
	}

	Link<T>* save = last_link;
	last_link = last_link->prev_link;
	
	if (last_link != 0) {
		last_link->next_link = 0;
	 } else {
		first_link = 0;
	
	save->prev_link = 0;
	delete save;
	}
} // pop_back()

template <class T> // deletes first link
void List<T>::pop_front()
{
	if (empty()) {
		return;
	} else {
		Link <T> * save = first_link;
		first_link = first_link->next_link;
		first_link->prev_link = 0;
		delete save;
		my_size--;
	}
} // pop_front()

template <class T> // returns iterator pointing to first link
typename List<T>::iterator List<T>::begin() const // O(1)
{
	return iterator(first_link);
} // begin()

template <class T> // returns iterator pointing to 1 past last element
typename List<T>::iterator List<T>::end() const // O(1)
{
	return iterator(last_link->next_link); 
} // end()

template <class T> // inserts link with value x, 1 before iterator 
void List<T>::insert(iterator pos, const T & x) // O(1)
{
	if (pos == begin()) {
		push_front(x);
	} else if (pos == end()) {
		push_back(x);
	} else {
		Link<T> * new_link = new Link<T> (x);
		Link<T> * current  = pos.current_link;

		new_link->next_link = current;
		new_link->prev_link = current->prev_link;
		current->prev_link = new_link;
		current = new_link->prev_link;
		current->next_link = new_link;
	}	
	my_size++;
} // insert(pos, x)

template <class T> // deletes link at iterator, iterator is set to next link
void List<T>::erase(iterator & pos) // O(1) 
{
	if (!empty()) {
		Link<T> *next = pos.current_link->next_link;
		pos.current_link->prev_link->next_link = pos.current_link->next_link;
		pos.current_link->next_link->prev_link = pos.current_link->prev_link;
		delete pos.current_link;
		pos.current_link = next;
		my_size--;
	}
	return;
} // erase(pos)

template <class T> // Overloads = to set List to l
List <T> & List<T>::operator=(const List<T> & l) // O(n)
{
	//~List();
	for (Link<T> * current = l.first_link; current != 0; current = current->next_link) {
    	push_back(current->value); // dereference
	}
	return *this;
} // =(l)

template <class T> 
class Link 
{
private:
   Link(const T & x): value(x), next_link(0), prev_link(0) {}
                
   T value;     
   Link<T> * next_link;
   Link<T> * prev_link;

   friend class List<T>;
   friend class List_iterator<T>;
};

template <class T> class List_iterator
{
public:
   typedef List_iterator<T> iterator;

   List_iterator(Link<T> * source_link): current_link(source_link) { } // *current_link = *source_link
   List_iterator(): current_link(0) { }
   List_iterator(List_iterator<T> * source_iterator): current_link(source_iterator.current_link) { }

   T & operator*();  // dereferencing operator
   iterator & operator=(const iterator & rhs);
   bool operator==(const iterator & rhs) const;
   bool operator!=(const iterator & rhs) const;
   iterator & operator++();  // pre-increment, ex. ++it
   iterator operator++(int); // post-increment, ex. it++
   iterator & operator--();  // pre-decrement
   iterator operator--(int); // post-decrement

protected:
   Link<T> * current_link;

   friend class List<T>;
};

template <class T> // returns value at iterator
T & List_iterator<T>::operator*() //O(1)
{
	return current_link->value;
} // *()

template <class T> // sets iterator to rhs 
List_iterator<T> & List_iterator<T>::operator=(const iterator & rhs) // O(1)
{
	current_link = rhs.current_link;
} // =(rhs)

template <class T> // returns true if iterator Link<T> as rhs
bool List_iterator<T>::operator==(const iterator & rhs) const // O(1)
{
	return current_link == rhs.current_link;
} // ==(rhs)

template <class T> //returns true if iterator does not point to same Link<T> as rhs
bool List_iterator<T>::operator!=(const iterator & rhs) const //O(1)
{
	return current_link != rhs.current_link;
} // !=(rhs)

template <class T> // INCREMENT iterator FIRST, then return value
List_iterator<T> & List_iterator<T>::operator++() // O(1)
{
        current_link = current_link->next_link;
        return *this;
} // ++()

template <class T> // RETURN value at iterator FIRST, then increment iterator
List_iterator<T> List_iterator<T>::operator++(int) // O(1)
{
	List_iterator<T> clone = current_link; 	//STUDY THIS
	current_link = current_link->next_link;
	return clone;
} // ++(int)

template <class T> // DECREMENT iterator FIRST, then return value
List_iterator<T> & List_iterator<T>::operator--() // O(1)
{
	current_link = current_link->prev_link;
	return *this;
} // --()

template <class T> // RETURN value at iterator FIRST, then decrement iterator
List_iterator<T> List_iterator<T>::operator--(int) // )(1)
{
	List_iterator<T> clone = current_link; 	//STUDY THIS
	current_link = current_link->prev_link;
	return clone;
} // --(int)
#endif
