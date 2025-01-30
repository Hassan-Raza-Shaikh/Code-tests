#include <iostream>
using namespace std;

int main() 
{

    // Assumed Color List:
    // Red = 1;
    // Green = 2;
    // Blue = 3;
    // Grey = 4;
    // Orange = 5;

    int num1, num2,colour1,colour2;

    int numberToColor[36] = 
    {
        2,1,3,5,4,2,
        2,4,5,3,1,2,
        1,3,5,4,2,1,
        1,2,4,5,3,1,
        3,5,4,2,1,3,
        3,1,2,4,5,3  
    };
    
    input:

    cout << "Enter first number b/w 1 and 36: ";
    cin >> num1;
    cout << "Enter second number b/w 1 and 36: ";
    cin>> num2;

    if (num1 < 1 || num1 > 36 || num2 < 1 || num2 > 36) 
    {
        cout << "Invalid input! Please enter numbers between 1 and 36." << endl;
        goto input;
    }

    
    colour1 = numberToColor[num1 - 1];
    colour2 = numberToColor[num2 - 1];

    
    if (colour1 == colour2) 
    {
        cout << "The two numbers have the same color!" << endl;
    } 
    else 
    {
        cout << "The two numbers have different colors." << endl; 
    }

    return 0;
}