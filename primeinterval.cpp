#include <iostream>

using namespace std;

int main()
{
    int a,b,flag ;
    cout<<"enter lower interval: "<<endl;
    cin>>a;
    cout<<"enter upper interval: "<<endl;
    cin>>b;

    for(int j=a;j<=b;j++)
    {
        flag=1;
        for(int i=2;i<j;i++)
        {
            if(j%i==0)
            {
                flag=0;
                break;
            }
        }

        if(flag==1)
        {cout<<"number is prime: "<<j<<endl;}
        if(flag==0)
        cout<<"number is composite: "<<j<<endl;}
    }
    
    return 0;
} 
  
