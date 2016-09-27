/*******************
Beverly Abadines
insertion_sort.cpp
1/29/2015
********************/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// insertion_sort: Sort integers in vector in non-decreasing order by comparing two consecutive positions
void insertion_sort(vector <int> &v) {
	int elem;
	int j;
	for (int i = 1; i < v.size(); i++) { // loops = n - 1    	
		for (elem = v[i], j = i - 1; j >= 0 && elem < v[j]; j-- ) { // Declaring two ints in for loop; must be SAME type (ex. int); loops = n
        		v[j + 1] = v[j]; // can be written as v[i]  
       		}	
		v[j + 1] = elem;    	
	}
} //insertion_sort

// Creates a vector of int with a total number of "total_elements" and calls insertion_sort(&v)
int main()
{
	int total_elements;
        cout << "Number of total int?\n";
        cin >> total_elements;        
		    
	vector <int> create_vector;
        srand(time(0)); // set random seed
	
	for (int i = 0; i < total_elements; i++) { // fill vector with total_elements numbers
        	create_vector.push_back(rand() % 1000000); // numbers 0 - 999999
        }
	insertion_sort(create_vector); // Order the values
	
	for(int i = 0; i < create_vector.size(); i++) { // Print Values
		cout << create_vector[i] << endl;
	}		        
} // Vector and insertion_sort

