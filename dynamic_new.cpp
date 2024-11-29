#include<iostream>
using namespace std;

int main()
{
    int x =10;
    int *p= &x;

    int *z= new int();
    cout<<z<<endl;
    *z = 5;
    cout<<*z<<endl;
    cout<<z<endl;          // not running this line specifically.

    return 0;
}