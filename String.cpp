/********************************************************************************
	Beverly Abadines
	Lab_3
	String.cpp
	2/2/15-2/9/15
	String Data Structure
*********************************************************************************/
#include "String.h"
#include <cstring>

using namespace std;

// Default Constructor
String::String()
{
	size = 0;
	buffer = 0; 
} // String()

// Constructor w/ String parameter
String::String(const String & source)
{
	size = source.size;
	buffer = new char[size];

	for (int i = 0; i < size; i++) {
		buffer[i] = source.buffer[i];
	}
} // String(const String&)

// Constructor w/ char parameter
String::String(const char * alpha)
{
	size = strlen(alpha);
	buffer = new char[size];

	for (int i = 0; i < size; i++) {
		buffer[i] = alpha[i];
	}
} //String(const char *)

// destructor
String::~String() 
{ 
	delete [] buffer;
	//size = 0;
} // ~String()

// Returns size
int String::length()
{
	return size;
} //length()
	
// Returns char of String at nth position 
char & String::operator[](int n) 
{
	return buffer[n];
} // char & operator[](int n)

// Implicit parameter equals size of explicit parameter and has char in same positions 
String & String::operator =(const String & source)
{
	delete [] buffer;
	size = source.size;
	buffer = new char[size];

	for (int i = 0; i < source.size; i++) {
		buffer[i] = source.buffer[i];
	}
	
	return *this;
} // String & operator=(const String&)

// Augments implicit with chars from explicit
String & String::operator +=(const String & source)
{
	size += source.size;	// Accomodate enough space to hold initial char and source char
	char * outbuffer = new char[size];	// Temporary buffer 
	int j = 0;

	for(int i = 0; i < size - source.size; i++) { // Copy buffer onto outbuffer
		outbuffer[i] = buffer[i];
	}	
	delete [] buffer;			// Delete buffer
	buffer = new char[size];	// Create buffer of (accomodated) size  

	for(int i = 0; i < size - source.size; i++) { 	// Copy outbuffer onto buffer until initial size (aka size before accomodation - 1)
		buffer[i] = outbuffer[i];
	}	

	for (int i = size - source.size; i < size; i++) {	// Copy source onto buffer from initial size to accomodated size
		buffer[i] = source.buffer[j];
		j++;
	}
	
	return *this;	//Return content of pointer 
} // String & operator += (const String&)

// cout the contents of String
ostream & operator<<(ostream & output, const String & source)
{
	for (int i = 0; i < source.size; i++) {
		output << source.buffer[i];
	}
	
	return output;
} // ostream & << (ostream &, const String&)



// Returns true if the value of 1st parameter is the same as 2nd, and false otherwise
bool operator ==(const String & source1, const String & source2)
{
	int i = 0;
		
	while (source1.buffer[i] != '\0' && source1.buffer[i] == source2.buffer[i]) {
		i++;
	}	// increments i if all values up until the end of 1st parameter is the same as the 2nd
		
	if ((source1.buffer[i] - source2.buffer[i]) == 0) { // compares value of the last position, which is at most position at source1.size 
		return true;
	} else {
		return false;
	}
} // bool operator==(const String&, const String&)

// Returns true if the value of 1st parameter is less than or equal as 2nd, and false otherwise
bool operator<=(const String & source1, const String & source2)
{
	int i = 0;
	
	while (source1.buffer[i] != '\0' && source1.buffer[i] == source2.buffer[i]) {
		i++;
	}
		
	if ((source1.buffer[i] - source2.buffer[i]) <= 0) {
		return true;
	} else {
		return false;
	}
} // bool operator<=(const String &, const String&)

// Returns true if the value of 1st parameter is less than 2nd, and false otherwise
bool operator<(const String & source1, const String & source2)
{
	int i = 0;
	
	while (source1.buffer[i] != '\0' && source1.buffer[i] == source2.buffer[i]) {
		i++;
	}
		
	if ((source1.buffer[i] - source2.buffer[i]) < 0) {
		return true;
	} else {
		return false;
	}
} // bool operator<(const String &, String &)

