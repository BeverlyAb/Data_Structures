/******************************************************************************************
	Beverly Abadines
	HW1.cpp
	1/14/15; updated 9/18/16
	Return the average and variance of an array of "ARRAY_SIZE" floats
*******************************************************************************************/
#include <iostream>
#include <cmath>		// pow
#define ARRAY_SIZE 5	// 5 is arbitrarily the amount of floats

using namespace std;

	float average(float container[]) { // Calculates and returns the average of numbers in an array 		
		float average_value = 0;

		for(int i = 0; i < ARRAY_SIZE; i++) {
			average_value += container[i];
		}
		average_value /= ARRAY_SIZE;
		return average_value;
	} //average
		
	float variance(float container[]) { // Calculates and returns the variance of numbers in an array
		float variance_value = 0;
		float average_value = average(container);

		for(int i = 0; i < ARRAY_SIZE; i++) {
			variance_value += (pow(container[i] - average_value, 2));
		} 
		variance_value /= (ARRAY_SIZE - 1);
		return variance_value;
	} // variance

	void populateArray(float container[]) { // Populates array with user inputted floats; +10 is buffer
		float input = 0;		
		int counter = 0;
		cout << "Enter your values one by one.\n";
		cin >> input;
		
		while(counter < (ARRAY_SIZE - 1)) {
			container[counter++] = input; 
			cin >> input;
		}
		container[counter] = input; 
	} // populateArray

	void display(float container[]) { // Displays all the floats in array
		cout << "Your values are:\n";

		for(int i = 0; i < ARRAY_SIZE; i++) {
			cout << container[i] << endl;
		}
	} // display
		
int main()
{ 
	float test[ARRAY_SIZE + 1];	//+1 for buffer of the array size
	populateArray(test);
	display(test); 	
	
	// Print average and variance of array
	float average_value = average(test);
	float variance_value = variance(test);
	cout << endl << "Average: " << average_value << " Variance: " << variance_value << endl;
}//average_value and variance_value
			
