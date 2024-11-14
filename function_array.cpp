#include<iostream>
using namespace std;

void showArray(int x[],int n)
{
     for(int i=0;i<n;i++)
    {
        cout<<"The values are: "<<endl;
        cout<<x[i]<<endl;
    }
}

int main()
{
    int arr1[5]={1,2,3,4,5};
    showArray(arr1,5);

    return 0;
}