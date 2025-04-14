#include<iostream>
using namespace std;

template<typename T>
T add(T a, T b)
{
    return a+b;
}

int main()
{
    float a,b;
    a=10.5;
    b=5.5;
    float s=add(a,b);
    cout<<s;

    return 0;
}