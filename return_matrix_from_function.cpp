#include<iostream>
using namespace std;

void returnarray(int arr[2][2])
{
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            cout<<"Enter the value in 2D array at ["<<r+1<<"]["<<c+1<<"]"<<endl;
            cin>>arr[r][c];
        }
    }
}

int main()
{
    int arr[2][2];
    returnarray(arr);

    cout<<"The matrix is: "<<endl;
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            cout<<arr[r][c]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}