#include <iostream>

using namespace std;

int main()
{
    int a,flag=1 ;
    cout<<"enter a number to check if it is prime: ";
    cin>>a;


    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {cout<<"number is prime";}
    if(flag==0)
    {cout<<"number is composite";}

    return 0;
} 
  
