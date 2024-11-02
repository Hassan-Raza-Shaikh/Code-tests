#include <iostream>
using namespace std;

int main() {
    int height = 5;

    
    for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < height - i - 1; j++) {
            cout << " ";
        }

        
        if(i%2==0)
        {
            cout<<"*";
        }
        else
        {
            cout<<"-";
        }
         

        
        for (int j = 0; j < (2 * i - 1); j++) 
        {
            
            if (i == 0 || j == 0 || j == (2 * i - 2)) 
            {
                cout << " ";
                if(i%2==0)
                {
                    cout<<"-";
                }
                else
                {
                    cout<<"*";
                }
            } 
            else 
            {
                cout << " ";
            }
        }

        
        if (i > 0) {
            cout << " ";
            if(i%2==0)
            {
                cout<<"*";
            }
            else
            {
                cout<<"-";
            }
        }

        
        cout << endl;
    }

    return 0;
}