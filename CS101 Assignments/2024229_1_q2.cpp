#include<iostream>

using namespace std;

int main()
{
    float radius,area,circumference;
    cout<<"Enter the radius of the sphere"<<endl;
    cin>>radius;
    area=4*(3.14)*pow(radius,2);
    circumference=(4/3)*3.14*pow(radius,3);
    cout<<"The Area is:"<<area<<endl<<"The Circumference is:"<<circumference;


    return 0;
}