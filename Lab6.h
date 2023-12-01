#ifndef Lab6_h
#define Lab6_h

#include <string>
#include <fstream>

using namespace std;

class BinaryConverter {
public:
	BinaryConverter();
	~BinaryConverter();


	void decimalConverter(ifstream& inFile);

private:
	void printResult(int decimal, string binaryNumber);
	bool validBinary(char c);
};


#endif



