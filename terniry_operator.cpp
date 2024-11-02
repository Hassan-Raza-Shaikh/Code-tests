#include<iostream>
using namespace std;

int main()
{
    int num_1,num_2,check;
    cout<<"Input the first number: "<<endl;
    cin>>num_1;
    cout<<"Input the second number: "<<endl;
    cin>>num_2;

    check=(num_1>num_2)? num_1:num_2;

    cout<<"The largest number is: "<<check;

    return 0;
}