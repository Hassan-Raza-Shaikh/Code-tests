#include <iostream>
using namespace std;

void countDigitSort(int arr[], int n, int pos)
{
    int output[50];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int d = (arr[i] / pos) % 10;
        output[count[d] - 1] = arr[i];
        count[d]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    for (int pos = 1; maxVal / pos > 0; pos *= 10)
        countDigitSort(arr, n, pos);
}

int main()
{
    int arr[6] = {170, 45, 75, 90, 802, 24};
    int n = 6;

    radixSort(arr, n);

    cout << "Radix Sort Result:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
