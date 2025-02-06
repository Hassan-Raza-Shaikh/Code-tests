#include<iostream>
#include<bitset>
using namespace std;

int main()
{
    int n=000;
    cout<<"Initial device state (000 - All OFF): "<<n<<endl;\
    n|=(1<<0);
    cout<<"Turn ON light: "<< n;
    cout<<" (Binary: 001)"<<endl;
    n|=(1<<1);
    cout<<"Turn ON fan: "<< n;
    cout<<" (Binary: 011)"<<endl;
    n&=~(1<<0);
    cout<<"Turn OFF light: "<< n;
    cout<<" (Binary: 010)"<<endl;
    if(n & (1<<2))
    {
        cout<<"Air conditioner is ON";
    }
    else
    {
        cout<<"Air conditioner is OFF";
    }

    return 0;
}