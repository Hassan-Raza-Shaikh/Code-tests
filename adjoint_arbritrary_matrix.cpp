#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the determinant of a submatrix
double determinant(double matrix[10][10], int n) 
{
    if (n == 1) 
    {
        return matrix[0][0];
    }

    double det = 0;
    double temp[10][10]; // Temporary matrix for cofactors
    int sign = 1;

    for (int f = 0; f < n; f++) 
    {
        // Create a submatrix by excluding row 0 and column f
        int subi = 0; // Row index for temp
        for (int i = 1; i < n; i++) 
        {
            int subj = 0; // Column index for temp
            for (int j = 0; j < n; j++) 
            {
                if (j == f) continue; // Skip the excluded column
                temp[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }

        // Recursive determinant calculation
        det += sign * matrix[0][f] * determinant(temp, n - 1);
        sign = -sign; // Alternate the sign
    }

    return det;
}

// Function to calculate the adjoint of a matrix
void adjoint(double matrix[10][10], double adj[10][10], int n) 
{
    if (n == 1) 
    {
        adj[0][0] = 1;
        return;
    }

    double temp[10][10]; // Temporary matrix for cofactors
    int sign;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            // Create a submatrix by excluding row i and column j
            int subi = 0; // Row index for temp
            for (int row = 0; row < n; row++) 
            {
                if (row == i) continue; // Skip the excluded row
                int subj = 0; // Column index for temp
                for (int col = 0; col < n; col++) 
                {
                    if (col == j) continue; // Skip the excluded column
                    temp[subi][subj] = matrix[row][col];
                    subj++;
                }
                subi++;
            }

            // Calculate cofactor
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, n - 1); // Transpose while assigning
        }
    }
}

// Function to print a matrix
void printMatrix(double matrix[10][10], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() 
{
    int n;
    cout << "Enter the order of the square matrix (2 to 10): ";
    cin >> n;

    if (n < 2 || n > 10) 
    {
        cout << "Invalid size! Please enter a size between 2 and 10." << endl;
        return 1;
    }

    double matrix[10][10], adj[10][10];
    cout << "Enter the elements of the " << n << "x" << n << " matrix:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Input Matrix:" << endl;
    printMatrix(matrix, n);

    adjoint(matrix, adj, n);

    cout << "Adjoint of the Matrix:" << endl;
    printMatrix(adj, n);

    return 0;
}
