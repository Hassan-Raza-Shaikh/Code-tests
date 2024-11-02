#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    float a,b,c,s;
    float area;
    cout<<"Enter the first side of the triangel:"<<endl;
    cin>>a;
    cout<<"Enter the second side of the triangel:"<<endl;
    cin>>b;
    cout<<"Enter the third side of the triangel:"<<endl;
    cin>>c;
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<"The area of the triangle is:"<<area;

    return 0;
}