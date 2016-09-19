#ifndef SET_H
#define SET_H

// Set.h - an implementation of Set using Node and Set_iterator

using namespace std;

template <class T> class Set;
template <class T> class Set_iterator;

template <class T>
class Node {
public:
	Node(): value(0), parent(0), leftChild(0), rightChild(0) { }												// Default Constructor	: O(1)
	Node(const T & x, Node * p, Node * lc, Node * rc): value(x), parent(p), leftChild(lc), rightChild(rc) { } 	// Constructor			: O(1)
    // here copy constructor and assignment op don't make too much sense!
    Node(const Node & n): value(n.value), parent(0), leftChild(0), rightChild(0) { }						  	// Copy Constructor 	: O(n)
    Node & operator=(const Node & n) { value = n.value; return *this; }											// =operator			: O(n)

	~Node() { delete leftChild; delete rightChild; } // this is very recursive, delete also calls the destructor of the object it is deleting
																												// Destructor			: O(n)
	void insert(Node<T> * newNode); // this is a helper func for Set::insert()
	Node * find(const T & x);			
	Node * merge(Node<T> * left, Node<T> * right);
protected:
	T value;
	Node * parent;
	Node * leftChild;
	Node * rightChild;

friend class Set<T>;
friend class Set_iterator<T>;
};

template <class T> // walks down the tree line and attaches Node to leaf position
void Node<T>::insert(Node<T> * newNode) // O(log n)
{ 	
	if (newNode->value <= value) {
		if (leftChild != 0 ) {
			 leftChild->insert(newNode);// recursion, reviews if it goes l or r; void, so no return 
		} else {
			newNode->parent = this;		// stick that Node at the left end side 
			leftChild = newNode;
		}
	} else { 
		if (rightChild != 0) {
			 rightChild->insert(newNode);// recursion, reviews if it goes l or r
		} else {
			newNode->parent = this;		// stick that Node at the right end side
			rightChild = newNode;
		}
	}
} //void insert(Node)

template <class T> // returns Node containing value, returns 0 if no Node exists
Node<T> * Node<T>::find(const T & x) // O(log n)
{	// returns Node
	if (x < value) { 
		if (leftChild != 0) {		
			leftChild->find(x);
		} else {
			return 0;
		}
	} else if(x == value) {
		return this; // w/o *, returning parent, leftChild, rightChild
	} else { //if (x > value) {
		if (rightChild != 0) {
			rightChild->find(x);
		} else {
			return 0;
		}
	}
} //Node * find(T)

template <class T> // Merges two subtrees that are children of a singlde node; left->value < right->value
Node<T> * Node<T>::merge(Node<T> * left, Node<T> * right) // O (log n)
{
	if (left == 0) {	// Nothing on left, nothing to merge
		return right;
	} 
		
	if (right == 0) {	// Nothing on right, nothing to merge
		return left;
	}
	
	Node<T> * child = merge(left, right->leftChild); // If there's something from both Nodes, create child 
	child->parent = right;							 // connect child and parent, with left being child and right being parent
	right->leftChild = child;
	return right;
}
//------------------------------------------------------------------------------------------		
template <class T>
class Set {
public:
	typedef Set_iterator<T> iterator;

	Set(): root(0), my_size(0) { }				// Default Constructor:	O(1)

	// the big three
	Set(const Set<T> & );	
	~Set() { delete root; }
	Set operator=(const Set & );

	bool empty() const { return root == 0; }	// returns true if Set is empty, false otherwise: O(1)
	unsigned int size() const { return my_size; }// returns my_size: O(1)
	iterator find(const T & x) const;	
	iterator insert(const T & x); 				// return an iterator to x if it already exists, otherwise insert and return an iterator to x 
	void erase(const iterator & it);
	void erase(const T & x) { root = remove(root, x); } // erases element w/ value X: O(log n)
	unsigned int count(const T & x); 			// returns 1 or 0 because this is a set, not a multi-set
	iterator begin() const; 					// for in-order traversal
	iterator end() const { return iterator(0); }// returns iterator one pass the last element: O(1)
protected:
	Node<T> * root;
	unsigned int my_size;
	Node<T> * remove(Node<T> *, const T &);
};

template <class T> // Copy Construtor
Set<T>::Set(const Set<T> & op) // O(n)
{
    root = 0;
	for (iterator i = op.begin(); i != op.end(); ++i) {
    	insert(*i);
		my_size++;
	}
} // Set Set(Set)

template <class T> //=operator
Set<T> Set<T>::operator=(const Set<T> & op) // O(n)
{
	delete root;
    root = 0;
    for (iterator i = op.begin(); i != op.end(); ++i)
   		insert(*i);
	//	my_size++; No need for this, since op should already have my_size
    return *this;
} // Set = (Set)

template <class T> // returns iterator of Node containing value of x, returns 0 if no Node exists
typename Set<T>::iterator Set<T>::find(const T & x) const // O(log n)
{
	if (empty()) { // Set is empty, same as (root == 0)
		return 0;
	} else {
		return iterator(root->find(x)); // returns iterator(Node)
	}	
} // iterator find(T)

template <class T> // return an iterator to x if it already exists, otherwise insert and return an iterator to x
typename Set<T>::iterator Set<T>::insert(const T & x) // O(log n)
{
	if(count(x) == 1) {			// Node is in Set
		return find(x);			// returns iterator of Set<T>::find(x)
	}

	Node<T> * newNode = new Node<T>(x, 0, 0, 0); // Node is not already in Set 
	if(empty()) {			
		root = newNode;
	} else {
		root->insert(newNode);	// Node<T>::insert(T)
	}

	return iterator(newNode);	
} // iterator insert(T)
	
// non-recursive erase(itr), erase(elem) can be written in terms of this erase
template <class T>
void Set<T>::erase(const iterator & it) // O(log n)
{
	if (root != 0 and it != end()) {	// STUDY THIS!!
		Node<T> * p = it.n;
		if (p != 0) {
			Node<T> * left = p ->leftChild;
			Node<T> * right = p -> rightChild;
			Node<T> * left_slide = right;
			if (right != 0) {
				// left slide
				while (left_slide -> leftChild)
					left_slide = left_slide -> leftChild;
				// connect the subtrees after left slide
				left_slide -> leftChild = left;
				if (left != 0)
					left -> parent = left_slide;
				// now connect right subtree to by pass p
				right -> parent = p -> parent;
				if (p -> parent)
					if (p -> parent -> leftChild == p)
						p -> parent -> leftChild = right;
					else p -> parent -> rightChild = right;
				else // p was root
					root = right;
			} else {
				if (left == 0) {
					if (p -> parent)
						if (p -> parent -> leftChild == p)
							p -> parent -> leftChild = 0;
						else p -> parent -> rightChild = 0;
					else // p was root
						root = 0; 
				} else {
					left -> parent = p -> parent;
					if (p -> parent)
						if (p -> parent -> leftChild == p)
							p -> parent -> leftChild = left;
						else p -> parent -> rightChild = left;
					else // p was root
						root = left;
				}
			}
			p -> leftChild = 0;
			p -> rightChild = 0;
			delete p;
			my_size--;
		}
	}
} // void erase (itr)

template <class T> // returns 1 or 0 according to if Node w/ value exists (for set)
unsigned int Set<T>::count(const T & x) // O(log n)
{
	if (find(x) == end()) {
		return 0;
	} else {
		return 1;
	}
} // int count(T)

template <class T> // returns iterator to left most node
typename Set<T>::iterator Set<T>::begin() const // O(log n)
{
	if (empty()) { 
		return 0;
	}

	Node<T> * tobegin = root;

	while (tobegin && tobegin->leftChild) { // keep going down the tree until it reaches the very left
		tobegin = tobegin->leftChild;		// left slide
	}
	return iterator(tobegin);	
} // iterator begin()

template <class T> // erases all Nodes with value testElement; applies merge and returns last Node after merge
Node<T> * Set<T>::remove(Node<T> * current, const T & testElement) // O(log n)
{
	if (current != 0) {
		Node<T> * pa = current->parent;
		if (testElement < current->value) 		// go left
			current->leftChild = remove(current->leftChild, testElement); 	// recursion
		else if (testElement > current->value)	// go right
			current->rightChild = remove(current->rightChild, testElement);	// recursion
		else {  								// found testElement
			Node<T> * result = current->merge(remove(current->leftChild, testElement), current->rightChild); // merge lc of removed element w/ rc 
			// the following two lines are necessary since delete calls Node destructor
			current->leftChild = 0; 
			current->rightChild = 0;
			delete current;
			my_size--;
			if (result)
				result->parent = pa;
			return result;
		}
	}
	return current;
} // Node remove(Node, T)

//-------------------------------------------------------------------------------------
template <class T>
class Set_iterator {
public:
	Set_iterator(): n(0) { }										// Default Constructor: O(1)
	Set_iterator(Node<T> * newNode): n(newNode) { }					// Constructor:			O(1)

	bool operator==(Set_iterator it) const { return n == it.n; }	// returns true if it points to n, false otherwise:	O(1)
	bool operator!=(Set_iterator it) const { return n != it.n; }	// opposite of operator == : O(1)
	Set_iterator & operator++(); // inorder traversal, pre-increment 
	Set_iterator operator++(int); // inorder traversal, post-increment
	Set_iterator & operator--();
	Set_iterator operator--(int);
	T & operator*() { return n->value; }							// returns value of n: O(1)
	Set_iterator & operator=(Set_iterator<T> it) { n = it.n; return *this; } // sets n = to the node it is pointing to, O(1)
protected:
	Node<T> * n;
friend class Set<T>;
};

template <class T> // pre. INCREMENT first, then RETURNs value
typename Set_iterator<T>::Set_iterator & Set_iterator<T>::operator++() // O(log n)
{
	if (n->rightChild) { 		// rightChild != 0
		n = n->rightChild;
	
		while (n && n->leftChild) {	// left slide from rightChild
			n = n->leftChild;
		}
	} else {			//
		Node<T> * child = n;
		n = n->parent;
		while(n && n->rightChild == child) {
			child = n;
			n = n->parent;
		}
	}
	return *this;
} //operator++() 	  	

template <class T> // pre. DECREMENT first, then RETURNs value
typename Set_iterator<T>::Set_iterator & Set_iterator<T>::operator--() // O(log n)
{
	if (n->leftChild) { 		// leftChild != 0
		n = n->leftChild;
	
		while (n && n->rightChild) {	// right slide from leftChild
			n = n->rightChild;
		}
	} else {			//
		Node<T> * child = n;
		n = n->parent;
		while(n && n->leftChild == child) {
			child = n;
			n = n->parent;
		}
	}
	return *this;
} //operator++() 	 

template <class T> // post. RETURN value, then DECREMENT
typename Set_iterator<T>::Set_iterator Set_iterator<T>::operator--(int) // O(log n)
{
	Set_iterator<T>  clone = n;	
	operator--(); // decrement normally
	return clone;
} // operator--(int)

template <class T> // post. RETURN value, then INCREMENT
typename Set_iterator<T>::Set_iterator Set_iterator<T>::operator++(int) // O(log n)
{
	Set_iterator<T>  clone = n;	
	operator++(); // increment normally
	return clone;
} // operator++(int)
#endif
