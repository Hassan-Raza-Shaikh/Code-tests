#include<iostream>
#include<bitset>
#include<iomanip>
using namespace std;

void binary(int u)
{
    cout<<setw(5)<<u<<": ";
    cout<< bitset<8>((int)u);
    cout<<"\n";
}

int main()
{
    int n=127; //000
    n = (1>>2);           
    cout<<n;

    binary(5);
    
    
   
    return 0;
}