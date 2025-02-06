#include<iostream>
using namespace std;

void puzzle(int n)
{
    cout<<"Your current number is: "<<n<<endl;
    if(n==1)
        return ;
    
    if(n%2==0)
    {
        n=n/2;
        puzzle(n);
    }
    else
    {
        n=3*n+1;
        puzzle(n);
    }
}

int main()
{
    int n;
    do
    {
    cout<<"Enter a starting number for your puzzle: "<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"Invalid number! Enter a positive number. "<<endl;
    }
    }while(n<=0);
    puzzle(n);
    return 0;
}