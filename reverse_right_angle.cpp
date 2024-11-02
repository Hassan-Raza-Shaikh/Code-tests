#include<iostream>
using namespace std;

void printpattern(int n)
{
    int i,j;

    for(i=n;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            cout<<j;
             if(j != i)
             { cout<<"-"; }
        }
        cout<<endl;
    }
}

int main()
{
    int num;
    cout<<"Enter the number of rows of triangle: "<<endl;
    cin>>num;
    cout<<"------------------------------------------------------"<<endl;

    printpattern(num);
    
    return 0;
}