#include <iostream>
#include <string>
using namespace std;


void printBinary(int num) {
    string binary = "";
    for (int i = 31; i >= 0; --i) {

        binary += ((num >> i) & 1) ? '1' : '0';

    }
    cout << "Binary: " << binary << std::endl;
}

void printSigned(int num) {
    cout << "Signed: " << num << std::endl;
}

void printUnsigned(int num) {
    unsigned int unsignedNum = static_cast<unsigned int>(num);
    cout << "Unsigned: " << unsignedNum << std::endl;
}

void printOnesComplement(int num) {
    int onesComplement = ~num;
    string binary = "";
    for (int i = 31; i >= 0; --i) {
        binary += ((onesComplement >> i) & 1) ? '1' : '0';
    }
    cout << "One's Complement: " << binary << std::endl;
}

void printTwosComplement(int num) {
    int twosComplement = ~num + 1;
    string binary = "";
    for (int i = 31; i >= 0; --i) {
                binary += ((twosComplement >> i) & 1) ? '1' : '0';
            }
}
void printBiased(int num, int bias) {
    int biased = num + bias;
    string binary = "";
    for (int i = 31; i >= 0; --i) {
        binary += ((biased >> i) & 1) ? '1' : '0';
    }
    cout << "Biased (bias = " << bias << "): " << binary << std::endl;
}


int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    printBinary(num);
    printSigned(num);
    printUnsigned(num);
    printOnesComplement(num);
    printTwosComplement(num);
    printBiased(num, 127);

    return 0;
}