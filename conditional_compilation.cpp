#include<iostream>
using namespace std;

// #define PI 3.14
#define AGE 18

int main()
{
#ifdef PI
    cout<<"PI value: "<<PI;
#elif defined(AGE)                //defined here not necessary, without it also works
    cout<<"Age is : "<<AGE;
#else
    cout<<"Not defined";
#endif
}