#include<iostream>

using namespace std;

int main()
{
    float km,CD70,GC125;
    cout<<"Enter the distance to be travelled in kilometers:"<<endl;
    cin>>km;
    CD70=(1/50.2)*km;
    GC125=(1/40.5)*km;
    cout<<"Petrol required for CD70 is:"<<CD70<<" litres"<<endl;
    cout<<"Petrol required for GC125 is:"<<GC125<<" litres"<<endl;

    return 0;
}