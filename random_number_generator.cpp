#include<iostream>
#include<stdlib.h> // not necessary-maybe just in mac then like the math.h
using namespace std;

int main()
{
    int a,b,n,randnum;
    cout<<"Enter the lower limit: "<<endl;
    cin>>a;
    cout<<"Enter the upper limit: "<<endl;
    cin>>b;

    n=b-a+1;

    srand(time(NULL));

    for(int i=1;i<=10;i++)
    {
        randnum=a+rand()%n;
        cout<<randnum<<endl;
    }

    return 0;
}