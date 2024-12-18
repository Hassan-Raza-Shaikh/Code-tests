#include<iostream>
#include<string>
using namespace std;

int main()
{
    int x[4]={1,2,3,4};

    //both display address of first index

    cout<<x<<endl;                            
    cout<<&x<<endl;

    //pointers store only address type, so no questions

    return 0;
}