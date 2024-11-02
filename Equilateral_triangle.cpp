#include<iostream>
using namespace std;

int main()
{
    
    float i,j,k,rows;

    cout<<"Enter the number of rows of the triangle: ";
    cin>>rows;
    int n=rows-1;
    for(i=1;i<=rows;i++)
    {
        for(k=n;k>=1;k--)
        {
            cout<<" ";
        }
            
        for(j=1;j<=i;j=j+0.5)
        {
            cout<<"*";
        }
        
        n--;
        cout<<endl;
    }
    
    return 0;
}