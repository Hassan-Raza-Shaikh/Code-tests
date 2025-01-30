#include<iostream>
using namespace std;

int main()
{
    int num,numcopy,numofdigits=0,reverse;
    cout<<"Enter a number: "<<endl;
    cin>>num;
    numcopy=num;
    while(numcopy>=1)
    {
        numcopy=numcopy/10;
        numofdigits++;
    }

    for(int i=1;i<=numofdigits;i++)
    {
        reverse=num%10;
        cout<<reverse;
        num=num/10;
    }

    return 0;
}