#include <iostream>
using namespace std;


void printBinary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}


void floatToBinary(float num) {
    
    unsigned int binaryRepresentation = *(reinterpret_cast<unsigned int*>(&num));

   
    unsigned int sign = (binaryRepresentation >> 31) & 1;  
    unsigned int exponent = (binaryRepresentation >> 23) & 0xFF; 
    unsigned int mantissa = binaryRepresentation & 0x7FFFFF;  

    // Print IEEE 754 representation
    cout << "\nIEEE 754 Representation (32-bit Floating Point):\n";
    cout << "Sign: " << sign << " | ";
    cout << "Exponent: ";
    printBinary(exponent, 8);
    cout << " | Mantissa: ";
    printBinary(mantissa, 23);
}

// Function to show interpretations in signed/unsigned formats
void integerInterpretations(float num) {
    int intRepresentation = *(reinterpret_cast<int*>(&num));
    unsigned int uintRepresentation = *(reinterpret_cast<unsigned int*>(&num));

    cout << "\nInterpretation as Integer (Bitwise Treating as 32-bit Integer):\n";
    cout << "Unsigned Representation: ";
    printBinary(uintRepresentation, 32);

    cout << "Signed Representation:   ";
    printBinary(intRepresentation, 32);

    // One's Complement (flip all bits if negative)
    if (intRepresentation < 0) {
        int onesComplement = ~(-intRepresentation);
        cout << "One’s Complement:       ";
        printBinary(onesComplement, 32);
    }

    // Two’s Complement (flip bits and add 1)
    cout << "Two’s Complement:       ";
    printBinary(intRepresentation, 32);

    // Biased Representation (Excess-127 for float exponent)
    int excessK = (intRepresentation + 127);
    cout << "Excess-K (Bias 127):    ";
    printBinary(excessK, 32);
}

int main() {
    float num;
    cout << "Enter a floating-point number: ";
    cin >> num;

    floatToBinary(num);
    integerInterpretations(num);

    return 0;
}