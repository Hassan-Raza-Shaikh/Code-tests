#include <iostream>
#include <bitset>
using namespace std;

unsigned int toGrayCode(unsigned int num) 
{
    return num ^ (num >> 1);  // XOR with the number right-shifted by 1 bit
}

int main() 
{
    unsigned int num;

    cout << "Enter a non-zero 16-bit integer: ";
    cin >> num;

    // Validating
    if (num == 0 || num > 65535) 
    {
        cout << "Please enter a valid 16-bit integer (1 to 65535)." << endl;
        return 1;
    }

    // Binary representation of the number
    cout << "Binary representation of " << num << " is: "
         << bitset<16>(num) << endl;

    // Number Conversation to Gray code
    unsigned int grayCode = toGrayCode(num);

    cout << "Gray code for " << num << " is: "
         << bitset<16>(grayCode) << endl;

    return 0;
}