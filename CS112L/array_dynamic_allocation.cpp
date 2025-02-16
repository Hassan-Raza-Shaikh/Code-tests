#include<iostream>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the initial array size"<<endl;
    cin>>size;
    int *arr = new int[size];
    cout<<"Enter "<<size<<" Values : "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Original array : "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }

    size*=2;

    cout<<"\nEnter "<<size/2<<" More values : "<<endl;
    for(int i=size/2;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Expanded array : "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }

    delete [] arr;

    return 0;
}