/*******************************************************************************
	Beverly Abadines
	Alphacase.cpp
	1/26/15-2/2/15

	Testing if a char is uppercase or lowercase and returning appropriate true or false statement, or char
*******************************************************************************/
#include <iostream>

using namespace std;

// Return true if char is uppercase and false otherwise
bool isUpper(char c)
{
    return (c >= 'A') && (c <= 'Z'); // returns 1 = True, 0 = False
} // isUpper

// Return true if char is lowercase and false otherwise
bool isLower(char c)
{
    return (c >= 'a') && (c <= 'z'); // returns 1 = True, 0 = False
} // isLower

// Returns lowercase char
char toLower(char c)
{
    if (isLower(c)) {        // if isLower is true, return c
        return c;
    } else if (isUpper(c)) { // if isUpper is true, convert c to lowercase before returning
        return c + 32;       // return (c - 'A') + 'a';
    } else {                 // c is not a valid letter of the alphabet
        return 0;            // this returns char 0, not NUL
    }
} // toLower

int main()
{
    char test, program;
    cout << "Enter a letter to test and indicate which program to run. a) isUpper b) isLower c) toLower\n";
    cin >> test >> program;

    while(!cin.eof()) {
        if (program == 'a') { // run isUpper
            if (isUpper(test)) {
                cout << test << " is an uppercase letter.\n";
            } else {
                cout << test << " is not an uppercase letter.\n";
            }
        } else if (program == 'b') { // run isLower
            if (isLower(test)) {
                cout << test << " is a lowercase letter.\n";
            } else {
                cout << test << " is not a lowercase letter\n";
            }
        } else if (program == 'c') { // run toLower
            if (toLower(test) != 0) {
                cout << test << " lowercased is " <<toLower(test) << endl;
            } else {
                cout << test << " is not a valid letter of the alphabet\n";
            }
        } else { // Do not run any of the previous programs
            cout << "You did not choose an executable program\n";
        }

        cout << " Enter letter and program: a) isLower b) isUpper c) toLower.\n";
        cin >> test >> program;
    }

    return 1;
}

