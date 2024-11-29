#include<iostream>
using namespace std;

int main()
{
//    int x[5]={11,22,33,44,55};

//    int *p=x;   //because in array name simple is array

//    cout<<&x<<endl;
//    cout<<x<<endl;
//    cout<<x[1]<<endl;
//    cout<<&x[1]<<endl;  //+4 in end shows that int has 4 bytes of allocated space

//    cout<<p<<endl;
//    cout<<*p<<endl; //value of 0 index
//    cout<<*p+1<<endl;  //value of zero index + 1
//    cout<<*(p+1)<<endl; //value of 1st index      or *(x+1)

int x=10;
int *p=&x;
cout<<"Address part: p= "<<p<<endl;
cout<<"Value part: *p= "<<*p<<endl;
cout<<"Address of p: &p= "<<&p<<endl;

int y[4]={11,22,33,44};
int *k=y;                //name of array is already pointer
cout<<"Address part: k= "<<k<<endl;
cout<<"Address of k: &k= "<<&k<<endl;
cout<<"Value of k: k= "<<k[1]<<" and y ="<<y[1]<<endl;
cout<<"Value part: *k= "<<*k<<endl;

    return 0;
}