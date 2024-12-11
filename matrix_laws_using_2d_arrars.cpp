#include<iostream>
using namespace std;

int main()
{
    double arr[2][2];

    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            cout<<"Enter the value in 2D array at ["<<r+1<<"]["<<c+1<<"]"<<endl;
            cin>>arr[r][c];
        }
    }

    cout<<"The matrix is: "<<endl;
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            cout<<arr[r][c]<<"\t";
        }
        cout<<endl;
    }

    //transpose of a matrix

    cout<<"Transpose of the matrix is: "<<endl;
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            cout<<arr[c][r]<<"\t";                     
        }
        cout<<endl;
    }

    //determinant of a matrix

    double det = arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
    cout<<"Determinant of the matrix is: "<<endl<<det<<endl;

    //adjoint of a matrix

    double arradj[2][2];
    arradj[0][0]=arr[1][1];
    arradj[1][1]=arr[0][0];
    arradj[0][1]= -1*arr[0][1];
    arradj[1][0]= -1*arr[1][0];

    cout<<"Adjoint of the matrix is: "<<endl;
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            cout<<arradj[r][c]<<"\t";                     
        }
        cout<<endl;
    }

    //inverse of matrix

    double arrinv[2][2];

    cout<<"Inverse of the matrix is: "<<endl;
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            arrinv[r][c]=arradj[r][c]/det;
            cout<<arrinv[r][c]<<"\t";                     
        }
        cout<<endl;
    }

    return 0;
}