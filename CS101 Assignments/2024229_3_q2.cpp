#include <iostream>
#include <cmath>
using namespace std;

void displayMenu() 
{
    cout << "\nMatrix Operations Menu:\n";
    cout << "1. Check Matrix Type\n";
    cout << "2. Find Transpose of the Matrix\n";
    cout << "3. Find Adjoint of the Matrix\n";
    cout << "4. Find Inverse of the Matrix\n";
    cout << "5. Multiply Two Matrices\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void checkMatrixOrder(int r, int c) 
{
    cout << "Order of the matrix is: " << r << " x " << c << endl;
}

void checkMatrixType(double arr[10][10], int r, int c) 
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

void calculateMatrixTranspose(double arr[10][10], int r, int c) 
{
    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < c; i++) 
    {
        for (int j = 0; j < r; j++) 
        {
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }
}

double determinant(double matrix[10][10], int n) 
{
    if (n == 1) return matrix[0][0];

    double det = 0;
    double temp[10][10];
    int sign = 1;

    for (int f = 0; f < n; f++) 
    {
        int subi = 0;
        for (int i = 1; i < n; i++) 
        {
            int subj = 0;
            for (int j = 0; j < n; j++) 
            {
                if (j == f) continue;
                temp[subi][subj++] = matrix[i][j];
            }
            subi++;
        }
        det += sign * matrix[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return det;
}

void adjoint(double matrix[10][10], double adj[10][10], int n) 
{
    if (n == 1) 
    {
        adj[0][0] = 1;
        return;
    }

    double temp[10][10];
    int sign;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int subi = 0;
            for (int row = 0; row < n; row++) 
            {
                if (row == i) continue;
                int subj = 0;
                for (int col = 0; col < n; col++) 
                {
                    if (col == j) continue;
                    temp[subi][subj++] = matrix[row][col];
                }
                subi++;
            }
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, n - 1);
        }
    }
}

void calculateMatrixInverse(double matrix[10][10], int n) {
    double det = determinant(matrix, n);

    if (det == 0) 
    {
        cout << "Matrix is singular and cannot have an inverse.\n";
        return;
    }

    double adj[10][10];
    adjoint(matrix, adj, n);

    cout << "Inverse of the matrix:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << adj[i][j] / det << "\t";
        }
        cout << endl;
    }
}

void multiplyMatrices(double mat1[10][10], double mat2[10][10], int r1, int c1, int r2, int c2) 
{
    if (c1 != r2) 
    {
        cout << "Matrix multiplication is not possible. Columns of the first matrix must equal rows of the second matrix.\n";
        return;
    }

    double result[10][10] = {0};
    for (int i = 0; i < r1; i++) 
    {
        for (int j = 0; j < c2; j++) 
        {
            for (int k = 0; k < c1; k++) 
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout << "Result of matrix multiplication:\n";
    for (int i = 0; i < r1; i++) 
    {
        for (int j = 0; j < c2; j++) 
        {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() 
{
    int choice, r, c;
    double matrix[10][10], matrix2[10][10];

    do 
    {
        displayMenu();
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter dimensions of matrix (rows and columns): ";
                cin >> r >> c;
                cout << "Enter elements of the matrix:\n";
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        cin >> matrix[i][j];
                checkMatrixOrder(r, c);
                checkMatrixType(matrix, r, c);
                break;

            case 2:
                cout << "Enter dimensions of matrix (rows and columns): ";
                cin >> r >> c;
                cout << "Enter elements of the matrix:\n";
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        cin >> matrix[i][j];
                calculateMatrixTranspose(matrix, r, c);
                break;

            case 3:
                cout << "Enter dimensions of matrix (n x n): ";
                cin >> r;
                cout << "Enter elements of the matrix:\n";
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < r; j++)
                        cin >> matrix[i][j];
                adjoint(matrix, matrix2, r);
                cout << "Adjoint of the matrix:\n";
                for (int i = 0; i < r; i++) 
                {
                    for (int j = 0; j < r; j++) 
                    {
                        cout << matrix2[i][j] << "\t";
                    }
                    cout << endl;
                }
                break;

            case 4:
                cout << "Enter dimensions of matrix (n x n): ";
                cin >> r;
                cout << "Enter elements of the matrix:\n";
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < r; j++)
                        cin >> matrix[i][j];
                calculateMatrixInverse(matrix, r);
                break;

            case 5:
                int r1, c1, r2, c2;
                cout << "Enter dimensions of first matrix (rows and columns): ";
                cin >> r1 >> c1;
                cout << "Enter elements of the first matrix:\n";
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        cin >> matrix[i][j];
                cout << "Enter dimensions of second matrix (rows and columns): ";
                cin >> r2 >> c2;
                cout << "Enter elements of the second matrix:\n";
                for (int i = 0; i < r2; i++)
                    for (int j = 0; j < c2; j++)
                        cin >> matrix2[i][j];
                multiplyMatrices(matrix, matrix2, r1, c1, r2, c2);
                break;

            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}