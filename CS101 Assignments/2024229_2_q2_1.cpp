#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string word = "tsebsicisbest";
    int len = word.length();
    int mid = len / 2;

    for (int i = 0; i < mid; i++) 
    {
        for (int j = 0; j < mid - i; j++) 
        {
            cout << "  ";
        }

        
        cout << word[mid - i];

        if (i != 0) {
            for (int j = 0; j < 2 * i - 1; j++) 
            {
                cout << "  ";
            }
            
            cout << " " << word[mid + i];
        }

        cout << endl;
    }

    for (int i = 0; i < len; i++) 
    {
        cout << word[i] << " "; 
    }
    cout << endl;

    return 0;
}