#include<iostream>
using namespace std;

int main()
{
    int arr[10]={8,0,7,5,3,9,1,4,6,2};
    int *ptr=arr;
    
    for(int i=0;i<10;i++)
    {
        cout<<*ptr<<" "<<ptr<<endl;
        ptr++;
    }

    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<10;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    cout<<"Max: "<<max<<endl;
    cout<<"Min: "<<min<<endl;

    ptr=&arr[9];
    for(int i=10;i>=0;i--)
    {
        cout<<*ptr<<endl;
        ptr--;
    }
}