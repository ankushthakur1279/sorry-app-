#include <iostream>
#include <vector>
using namespace std;


void decimalToBinary(int n) {
    vector<int>  binaryNum(32,0);
    
    while (n > 0) {
        binaryNum.push_back(n % 2);
        n = n / 2;
    }
    
    for (int i = binaryNum.size() - 1; i >= 0; i--) {
        cout << binaryNum[i];
    }
    cout << std::endl;
}

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    
    cout << "Binary representation: ";
    decimalToBinary(decimalNumber);
    
    return 0;
}