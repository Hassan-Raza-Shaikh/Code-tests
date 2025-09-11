#include<iostream>
using namespace std;

int main()
{
    int r,c;
    cout<<"Enter the no rows of matrix: "<<endl;
    cin>>r;
    cout<<"Enter the no columns of matrix: "<<endl;
    cin>>c;
    int** arr=new int*[r];
    for(int i=0;i<r;i++)
    {   
        arr[i]=new int[c];
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<"Enter value for arr["<<i+1<<"]["<<j+1<<"] ";
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum=0;
    cout<<"Sum of each row is: "<<endl;
    for(int i=0;i<r;i++)
    {
       for(int j=0;j<c;j++)
       {
            sum+=arr[i][j];
       }
         cout<<"Sum of row "<<i+1<<" is "<<sum<<endl;
         sum=0;
    }

    sum=0;
    cout<<"Sum of each column is: "<<endl;
    for(int i=0;i<c;i++)
    {
       for(int j=0;j<r;j++)
       {
            sum+=arr[j][i];
       }
         cout<<"Sum of column "<<i+1<<" is "<<sum<<endl;
         sum=0;
    }

    for(int i=0; i<r; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}