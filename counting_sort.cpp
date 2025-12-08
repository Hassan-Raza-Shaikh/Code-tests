#include <iostream>
using namespace std;

void countingSort(int arr[], int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int count[50] = {0};
    int result[50];

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int idx = 0;
    for (int i = 0; i <= maxVal; i++)
    {
        while (count[i] > 0)
        {
            result[idx] = i;
            idx++;
            count[i]--;
        }
    }

    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}

int main()
{
    int arr[7] = {4, 2, 2, 8, 3, 3, 1};
    int n = 7;

    countingSort(arr, n);

    cout << "Counting Sort Result:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
