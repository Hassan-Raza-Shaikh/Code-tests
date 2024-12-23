#include<iostream>
using namespace std;

int fibonacci(int n, int &a, int &b, int &nextterm)
{
    if(n==0)
        return 0;

    nextterm=nextterm+a;
    cout<<nextterm<<"\t";
    a=b;
    b=nextterm;

    fibonacci(n-1,a,b,nextterm);

}

int main()
{
    int nth;
    cout<<"Enter the number of terms till which you want to print sequence: "<<endl;
    cin>>nth;

    int a=0;
    int b=1;
    int nextterm=0;

    if(nth<=0)
        cout<<"Invalid no. of terms! "<<endl;

    else
    {
        fibonacci(nth, a, b, nextterm);
    }

    return 0;
}