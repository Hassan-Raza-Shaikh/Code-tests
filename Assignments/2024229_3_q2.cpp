#include<iostream>
using namespace std;

void checkMatrixOrder(int r,int c)
{
    cout<<"Order of matrix is: "<<r<<" x "<<c<<endl;
}

void checkMatrixType(double arr[10][10],int r,int c)
{
    //square matrix check
    if(r==c)
    { cout<<"It is a square matrix"<<endl; }
    else
    { cout<<"It is a rectangular matrix"<<endl;}

    if(r==c)
    {
        //identity matrix
        int diag=0;
        int nondiag=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==j)
                {
                    if(arr[i][j]==1)
                    {
                        diag++;
                    }
                }
                if(i!=j)
                {
                    if(arr[i][j]==0)
                    {
                        nondiag++;
                    }
                }
            }
        }
        if(diag==r && nondiag==pow(c,2)-c)
        {
        cout<<"It is an identity matrix"<<endl;
        }

        //diagonal matrix
        diag=0;
        nondiag=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==j)
                {
                    if(arr[i][j]!=0)
                    {
                        diag++;
                    }
                }
                if(i!=j)
                {
                    if(arr[i][j]==0)
                    {
                        nondiag++;
                    }
                }
            }
        }
        if(diag==r && nondiag==pow(c,2)-c)
        {
            cout<<"It is a diagonal matrix"<<endl;
        }

        //scaler matrix
        diag=0;
        nondiag=0;
        int con=arr[0][0];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==j)
                {
                    if(arr[i][j]==con)
                    {
                        diag++;
                    }   
                }
                if(i!=j)
                {
                    if(arr[i][j]==0)
                    {
                        nondiag++;
                    }
                }
            }
        }
        if(diag==r && nondiag==pow(c,2)-c)
        {
            cout<<"It is a scaler matrix"<<endl;
        }

        //zero matrix
        int entries=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(arr[i][j]==0)
                {
                    entries++;
                }
            }
        }
        if(entries==pow(r,2))
        {
            cout<<"It is a zero matrix"<<endl;
        }
    }
    else
    {
        cout<<"The matrix will not posses properties like identity because it is not a square matrix"<<endl;
    }
}

void calculateMatrixTranspose(double arr[10][10],int r,int c)
{
    double arrtrans[10][10];

    cout<<"Transpose of the matrix is: "<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arrtrans[j][i]=arr[i][j];                    
        }
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<arrtrans[i][j]<<"\t";
        }
        cout<<endl;
    }
}

double determinant2X2(double arr[10][10],int r,int c)
{
    double det = arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
    cout<<"Determinant of the matrix is: "<<endl<<det<<endl;
    return det;
}

void calculateMatrixAdjoint(double arr[10][10],double arradj[10][10],int r,int c)
{
    arradj[0][0]=arr[1][1];
    arradj[1][1]=arr[0][0];
    arradj[0][1]= -1*arr[0][1];
    arradj[1][0]= -1*arr[1][0];

    cout<<"Adjoint of the matrix is: "<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arradj[i][j]<<"\t";                     
        }
        cout<<endl;
    }   
}

void calculateMatrixInverse(double arr[10][10],double arradj[10][10],double det,int r,int c)
{
     double arrinv[r][c];

    cout<<"Inverse of the matrix is: "<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arrinv[i][j]=arradj[i][j]/det;
            cout<<arrinv[i][j]<<"\t";                     
        }
        cout<<endl;
    }
}

int main()
{
    int r,c;

    cout<<"Enter the number of rows of the matrix: "<<endl;
    cin>>r;
    cout<<"Enter the number of columns of the matrix: "<<endl;
    cin>>c;
    double arr[10][10];
    double det;
    double arradj[10][10];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<"Enter the value in 2d array at ["<<i+1<<"]["<<j+1<<"]"<<endl;
            cin>>arr[i][j];
        }
    }

    cout<<"The matrix is: "<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }

    //check order of matrix
    checkMatrixOrder(r,c);

    //check type of matrix

    checkMatrixType(arr,r,c);

    //transpose of a matrix

    calculateMatrixTranspose(arr,r,c);

    //adjoint of a matrix1

    calculateMatrixAdjoint(arr,arradj,r,c);

    // //inverse of matrix

    calculateMatrixInverse(arr,arradj,det,r,c);

    return 0;
}