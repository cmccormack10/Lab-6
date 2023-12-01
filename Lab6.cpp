#include "Lab6.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//constructor
BinaryConverter::BinaryConverter() {};

//destructor
BinaryConverter::~BinaryConverter() {}


// Prints the binary number and the result of its decimal
// Pre: none
void BinaryConverter::printResult(int decimal, string binaryNumber) {
    cout << setw(30) << left << binaryNumber << setw(15) << right << decimal << '\n';
}
// Post: Outputs binary and its decimal equivalent

// Checks if the binary is a valid binary digit
// Pre: Takes character as an input
bool BinaryConverter::validBinary(char c) {
	return (c == '0' || c == '1' || c == ' ' || c == '\r') && (c != '\n');
}
// Post: Returns true given the set inputs


// Function to convert Binary to decimal (given checks and flags) and print the result to the screen
// Pre: Takes in an ifstream object from a file opened in the main file
void BinaryConverter::decimalConverter(ifstream& inFile) {
    char c;
    int decimal = 0;
    bool leadingSpaces = true;
    string binaryNumber;
    bool isValid = true;  // Flag to indicate whether the current binary number is valid

    while (inFile.get(c)) {

        // Skips leading spaces 
        if (leadingSpaces) {
            if (c == ' ') {
                continue;
            }
            else {
                leadingSpaces = false;
            }
        }

        // Process valid binary integers
        if (c == '0' || c == '1') {
            if (isValid) {
                decimal = decimal * 2 + (c - '0');
                binaryNumber += c; // Adds chars to a string to easily print to a screen 
            }
        }

        // Handles the End of line
        else if (c == '\n') {
            if (isValid) {
                printResult(decimal, binaryNumber);
            }
            else {
                cout << "Bad digit on input\n";
            }
            decimal = 0;
            leadingSpaces = true;
            binaryNumber.clear();
            isValid = true;  // Reset the flag for the next binary number
        }

        // Invalid blank spaces inside of binary number
        else if (c == ' ') {
            isValid = false;  // Set the flag to indicate an invalid binary number
        }

        // Invalid characters outside binary numbers 
        else {
            cout << "Bad digit on input\n";
            while (inFile.get(c) && c != '\n') {
            }
            decimal = 0;
            leadingSpaces = true;
            binaryNumber.clear();
            isValid = true;  // Reset the flag for the next binary number
        }

    }
    // When file is ended it will still print the result if there isn't a \n to show the binary number is done
    if (isValid) {
        printResult(decimal, binaryNumber);
    }

    inFile.close();
}
// Post: Reads in number from a file, converts to a decimal, and prints to the console. 
// Post: If an input is invalid, it is marked and printed as an error
