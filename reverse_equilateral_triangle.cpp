#include<iostream>
using namespace std;

int main()
{
    
    float i,j,k,rows;

    cout<<"Enter the number of rows of the triangle: ";
    cin>>rows;
    int n=0;
    for(i=rows;i>=1;i--)
    {
        for(k=1;k<=n;k++)
        {
            cout<<" ";
        }
            
        for(j=1;j<=i;j=j+0.5)
        {
            cout<<"*";
        }
        
        n++;
        cout<<endl;
    }


    return 0;
}