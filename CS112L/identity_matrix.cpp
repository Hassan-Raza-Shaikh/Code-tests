#include<iostream>
using namespace std;

class MatrixAnalyzer
{
    protected:
    int mat[10][10];
    int n;
    public:
    void MatrixInput()
    {
        cout << "Enter dimensions of matrix (n x n): ";
        cin >> n;
        cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];

    }
    void DisplayMatrix()
    {
        cout<<"The matrix is: "<<endl;
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                cout<<mat[r][c]<<"\t";
            }
            cout<<endl;
        }
    }
};

class IdentityChecker : public MatrixAnalyzer
{
    public:
    void checkIdentity()
    {
    int diag=0;
        int nondiag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    if(mat[i][j]==1)
                    {
                        diag++;
                    }
                }
                if(i!=j)
                {
                    if(mat[i][j]==0)
                    {
                        nondiag++;
                    }
                }
            }
        }
        if(diag==n && nondiag==pow(n,2)-n)
        {
        cout<<"It is an identity matrix"<<endl;
        }
        else
        {
            cout<<"It is not an identity matrix"<<endl;
        }
    }
};

int main()
{
    IdentityChecker m;
    m.MatrixInput();
    m.DisplayMatrix();
    m.checkIdentity();

    return 0;
}