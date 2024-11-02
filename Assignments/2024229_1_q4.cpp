#include<iostream>

using namespace std;

int main()
{
    int years,months,days;
    cout<<"Enter age in years:"<<endl;
    cin>>years;
    months=years*12;
    cout<<"Age in months is:"<<months<<endl;
    days=months*30;
    cout<<"Age is days is:"<<days<<endl;
    return 0;
}