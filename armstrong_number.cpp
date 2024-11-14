#include<iostream>
using namespace std;

int main()
{
    int copy,n,original,r,arm=0,count=0;
    cout<<"Enter a number: "<<endl;
    cin>>n;
    original=n;
    copy=n;

    // for(;z.0;)
    // {
    //     z=z/10;              This also works
    //     count++;
    // }

    for(int i=n;i>0;i=i/10) // or just simply use while for counting
    {
        copy=copy/10;
        count++;
    }

    cout<<"Number of digits are: "<<endl<<count<<endl;

    for(int j=0;j<=count;j++)
    {
        r=n%10;
        arm=arm+pow(r,count);
        n=n/10;
    }

    if(original==arm)
        cout<<"Number is armstrong.";
    else
        cout<<"Number is not armstrong.";

    return 0;
}