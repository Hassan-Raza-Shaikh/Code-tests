#include<iostream>
using namespace std;

struct coordinates 
{
    int x,y;
};

int main()
{
    coordinates point1;    // this could also be written like struct coordinates point1; , again struct keyword in main is not necessary
    coordinates point2;    // instance can be one or many, it can also be an array

    point1.x=0;
    point1.y=0;
    point2.x=5;
    point2.y=5;

    cout<<"Point 1 coordinates are : ("<<point1.x<<","<<point1.y<<")"<<endl;
    cout<<"Point 2 coordinates are : ("<<point2.x<<","<<point2.y<<")"<<endl;
}