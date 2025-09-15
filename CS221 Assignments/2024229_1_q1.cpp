#include<iostream>
using namespace std;

struct UniverseCoordinate
{
    int s_number;
    int x_position;
    int y_position;
    bool is_snake;
};

int main()
{
    UniverseCoordinate u1;
    u1.s_number=1;
    u1.x_position=1; 
    u1.y_position=2;
    u1.is_snake=true;

    cout<<"Snake number: "<<u1.s_number<<endl;
    cout<<"Found at position "<<u1.x_position<<","<<u1.y_position<<endl;

    return 0;
}