/*******************
	Beverly Abadines
	Lab2.cpp	
	SelectionSort.cpp
 	1/26/15 - 2/2/15
	
	Implementing and executing algorithms designed to re-arrange vectors of "total elements" sizes and calculating which O(n^2) time complexities has the smallest constant, c, and therefore runs the fastest.  
********************/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// selection_sort: Sort integers in vector in non-decreasing order by establishing the correct value of the lowest position first
void selection_sort(vector <int> &v) {
	for (int i = 0; i <  v.size() - 1; i++) { // loops = n
    	for (int j = i + 1; j < v.size(); j++) { // loops = n - 1
        	if (v[i] > v[j]) {
            	swap(v[i], v[j]);
        	}
    	}
	}
} // selection_sort

// Creates a vector of int with a total number of "total_elements" and calls selection_sort (&v)
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

		selection_sort(create_vector); // Order the values
		
		for(int i = 0; i < create_vector.size(); i++) { // Print Values
			cout << create_vector[i] << endl;
		}		        
} // Vector and selection_sort




