/******************************************************************************
	Beverly Abadines
	Lab_3
	String.cpp
	2/2/15-2/9/15
	String Data Structure
******************************************************************************/
#ifndef STRING_H
#define STRING_H
#include <iostream>

using namespace std;

class String 
{
        int size;
        char * buffer;
public:
        String(); // default constructor
        String(const String & source); // implicit  = explicit parameter
        String(const char * alpha); 
        ~String();
		
		// accessors
		int length();

		// operators 
		char & operator[](int);	
		String & operator =(const String &);
		String & operator +=(const String &);
		friend ostream & operator<<(ostream &, const String &); 
	
		// friends
     	friend bool operator==(const String & , const String &);
        friend bool operator<=(const String &, const String &);
        friend bool operator<(const String &, const String &);
       
};
#endif
