// Stack_test.cpp
// uses c++ string, vector, and list
#include <iostream>
#include <cassert>
#include "Stack.h"

#include <string>
#include <vector>
#include <list>


using namespace std;

int main()
{
   Stack<int, vector> s1;
   assert(s1.size() == 0);	
   assert(s1.empty());

   s1.push(16);
   assert(s1.size() == 1);	//  front/back[16]
   assert(s1.top() == 16);

   s1.pop();
   assert(s1.size() == 0); 	// front/back [0]

   s1.push(11);				// front/back [11] 
   assert(s1.size() == 1);
   assert(s1.top() == 11);

   s1.push(22);				// front/back [22, 11] 
   assert(s1.size() == 2);
   assert(s1.top() == 22);

   s1.push(33);				// front/back [33, 22, 11]
   assert(s1.size() == 3);
   assert(s1.top() == 33);

   s1.pop();				// front/back [22, 11]
   assert(s1.size() == 2);
   assert(s1.top() == 22);

   Stack<string, list> s2;	// front/back [de, abc]
   s2.push("abc");
   s2.push("de");
   s2.pop();				// front/back [abc]
   assert(s2.top() == "abc");

   cout << "SUCCESS\n";
}

