#include<iostream>
#include<bitset>
#include<iomanip>
using namespace std;

int main()
{
    int n=127; //000
    n = (1<<6);           /// turns position of the second digit according to computer architecture to be to be the first parameter only if the number i a power of 2 otherwise it resets the whole bit
    cout<<n;
    
    return 0;
}