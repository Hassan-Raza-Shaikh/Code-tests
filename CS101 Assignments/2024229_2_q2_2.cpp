#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 16; i++) 
    {
        if (i < 15) 
        {
            int k = i / 3;
            int a;

            
            for (int x = 0; x < (25 - k * 5); x++) 
            {
                cout << " ";
                a = x;
            }

            cout << "*";

            int y = i % 3;
            if (y == 0) 
            {
                cout << "*****";
            } 
            else 
            { 
                cout << "     "; 
            }

            for (int f = 0; f < (24 - a); f++) 
            {
                cout << " ";
            }

            cout << "*";
        } 
        else 
        {

            for (int h = 0; h < 32; h++) 
            {
                cout << "*";
            }
        }

        cout << endl;
    }

    return 0;
}