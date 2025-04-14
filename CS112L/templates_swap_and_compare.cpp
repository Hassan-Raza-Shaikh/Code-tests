#include<iostream>
using namespace std;

template<typename T>
void swapandcompare(T &a, T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
    cout<<"After swapping a = "<<a<<" b = "<<b<<endl;

    if(a>b)
    {
        cout<<"a is greater than b"<<endl;
    }
    else if(a<b)
    {
        cout<<"a is less than b"<<endl;
    }
    else
    {
        cout<<"a is equal to b"<<endl;
    }
}

int main()
{
    float a,b;
    a=10.5;
    b=5.5;
    swapandcompare(a,b);
    return 0;
}