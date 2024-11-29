#include<iostream>
using namespace std;

int main()
{
    int x=5;                //initialization and decleration is a bit different if done together.
    int *p;
    p=&x;      //p will store address so without & decleration not possible
    //or int *p=&x;
    cout<<"Address of p P "<<p<<endl;
    cout<<"value of p *P "<<*p<<endl;
    cout<<"Address of x &X "<<&x<<endl;

    cout<<"Change the value of *P,Enter new value: "<<endl;
    cin>>*p;
    cout<<"Value of x X "<<x<<endl;
    cout<<"value of p *P "<<*p<<endl;
    cout<<"Address of x &X "<<&x<<endl;

    return 0;
}