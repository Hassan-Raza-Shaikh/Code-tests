#include<iostream>
using namespace std;

enum direction
{
    north=1,
    south=2,
    east=3,
    west=4
};

int main()
{
    direction d;
    int c;
    cout<<"Enter the direction (1-4): 1-North, 2-South, 3-East, 4-West: ";
    cin>>c;
    d=static_cast<direction>(c);
    switch(d)
    {
        case north:
            cout<<"You are going North"<<endl;
            break;
        case south:
            cout<<"You are going South"<<endl;
            break;
        case east:
            cout<<"You are going East"<<endl;
            break;
        case west:
            cout<<"You are going West"<<endl;
            break;
        default:
            cout<<"Invalid direction"<<endl;
    }
    return 0;
}