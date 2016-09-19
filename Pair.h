#ifndef PAIR_H
#define PAIR_H

// Pair.h

using namespace std;

template < class T1, class T2 >
class Pair
{
public:
   Pair(): first(), second() {}	// only key matters for comparison
   Pair(const T1 & first, const T2 & second): first(first), second(second) { } // O(1)

   bool operator==(const Pair & rhs) const { return first == rhs.first; }	// O(1)
   bool operator<=(const Pair & rhs) const { return first <= rhs.first; }	// O(1)
   bool operator<(const Pair & rhs) const { return first < rhs.first; }		// O(1)
   bool operator>(const Pair & rhs) const { return first > rhs.first; }		// O(1)

   T1 first;	// index, key
   T2 second;	// value
};

#endif
