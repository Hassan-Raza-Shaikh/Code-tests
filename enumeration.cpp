#include<iostream>
using namespace std;

enum supercars
{
    venom_f5=301, ford=268, range_rover=850, mustang=541, roadster=875
}speed1,speed2;

int main()
{
    speed1=ford;
    speed2=roadster;

    if(speed1<speed2)
    {
        cout<<"It's a win for roadster with speed: "<<speed2;
    }
    else
    {
        cout<<"It's a win for ford with speed: "<<speed1;
    }

    return 0;
}