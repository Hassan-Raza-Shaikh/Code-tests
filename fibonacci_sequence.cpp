#include<iostream>
using namespace std;

void fibonacci(int n)
{
    // if(n==1)
    //     return 1;

    int a=0;
    int b=1;
    int nextterm=0;
    for(int i=1;i<=n;i++)
    {
        nextterm=nextterm+a;
        cout<<nextterm<<"\t";
        a=b;
        b=nextterm;
        
    }
}

int main()
{
    int nth;
    cout<<"Enter the number of terms till which you want to print sequence: "<<endl;
    cin>>nth;

    if(nth<=0)
        cout<<"Invalid no. of terms! "<<endl;

    else
    {
        fibonacci(nth);
    }

    return 0;
}