/*
    Chris McCormack
    C++ Fall 2023
    Lab 6 - Binary to Decimal Converter
    Write a C++ program that reads characters representing binary (base 2)
    numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
    numbers. There is only one binary number per input line, but an arbitrary number of blanks can
    precede the number. The program must read the binary numbers one character at a
    time. 
*/




#include "Lab6.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	BinaryConverter Converter; // Creats object called Converter
    
    // Header for formatting to console
    cout << setw(30) << left << "Binary Number" << setw(15) << right << "Decimal" << '\n';
    
    ifstream inFile("BinaryIn.dat");


    // Opens file and checks to make sure it opens 
    if (!inFile.is_open()) {
        std::cout << "Error opening file.\n";
        return 1;
    }

    Converter.decimalConverter(inFile);

    inFile.close();

    return 0;
}