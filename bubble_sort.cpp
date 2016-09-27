/*******************
Beverly Abadines
bubble_sort.cpp
 1/29/2015
********************/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// bubble_sort: Sort integers in vector in non-decreasing order by establishing the correct value of the highest position first
void bubble_sort(vector <int> &v) {
	for (int i = v.size() - 1; i > 0; i--) {
    		for (int j = 0; j < i; j++) {
        		if (v[j] > v[j + 1]) {
            			swap(v[j], v[j + 1]);
			}
		}
	}
} // bubble_sort

// Creates a vector of int with a total number of "total_elements" and calls bubble_sort(&v)
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
	bubble_sort(create_vector); // Order the values
	
	for(int i = 0; i < create_vector.size(); i++) { // Print Values
		cout << create_vector[i] << endl;
	}		        
} // Vector and bubble_sort




