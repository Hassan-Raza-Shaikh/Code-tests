#include<iostream>
using namespace std;

void value()
{
    int s=5;
    cout<<s<<endl;
}

void refrence(int &s)
{
    s=s+10;
}

int main()
{
    //pass by refrence

    int x=2;
    int &y =x;
    cout<<x<<endl;
    cout<<y<<endl;
    x=x+5;
    cout<<x<<endl;
    cout<<y<<endl;

    //pass by value

    int s=10;
    cout<<s<<endl;
    value();
    cout<<s<<endl;

    //pass by refrence

    int a=10;
    cout<<a<<endl;
    refrence(a);
    cout<<a<<endl;

    return 0;
}