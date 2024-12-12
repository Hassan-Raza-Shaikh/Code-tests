#include<iostream>
using namespace std;

void multiplyMatrix(int arr1[10][10],int arr2[10][10],int c1,int r2,int c2,int r1);
{
    if(c1==r2)
    {
        for(int i=0,)
    }
    else
    {
        cout<<"matrices are not comfertable for multiplication. "<<endl
    }
}


int main()
{
    int r1,r2,c1,c2;
    cin>>r1;
    cin>>c1;
    cin>>r2;
    cin>>c2;
    int arr1[10][10];
    int arr2[10][10];

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            cout<<"Enter the value in matrix 1 at ["<<i+1<<"]["<<j+1<<"]"<<endl;
            cin>>arr1[i][j];
        }
    }

    cout<<"The matrix 1 is: "<<endl;
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            cout<<arr1[i][j]<<"\t";
        }
        cout<<endl;
    }    

    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<"Enter the value in matrix 2 at ["<<i+1<<"]["<<j+1<<"]"<<endl;
            cin>>arr2[i][j];
        }
    }

    cout<<"The matrix 2 is: "<<endl;
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<arr2[i][j]<<"\t";
        }
        cout<<endl;
    }    

    multiplyMatrix(arr1,arr2,c1,r2,c2,r1);

    return 0;
}