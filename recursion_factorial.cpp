#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n==0 || n==1)
    {
        return 1;        //base case
    }
    else
    {
        return n*factorial(n-1);          //recursive case
    }
}

int main()
{
    int num,fact;
    cout<<"Enter a number: "<<endl;
    cin>>num;
    fact=factorial(num);
    cout<<fact;

    return 0;
}