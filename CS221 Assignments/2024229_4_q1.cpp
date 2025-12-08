#include <iostream>
using namespace std;

void countSort(int data[], int size, int maxNum)
{
    int freq[1000];
    int temp[50];

    for (int i = 0; i <= maxNum; i++)
        freq[i] = 0;

    for (int i = 0; i < size; i++)
        freq[data[i]]++;

    int k = 0;
    for (int i = 0; i <= maxNum; i++)
    {
        while (freq[i] != 0)
        {
            temp[k] = i;
            k++;
            freq[i]--;
        }
    }

    for (int i = 0; i < size; i++)
        data[i] = temp[i];
}

void digitSort(int data[], int size, int place)
{
    int store[50];
    int cnt[10];

    for (int i = 0; i < 10; i++)
        cnt[i] = 0;

    for (int i = 0; i < size; i++)
        cnt[(data[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        int d = (data[i] / place) % 10;
        store[cnt[d] - 1] = data[i];
        cnt[d]--;
    }

    for (int i = 0; i < size; i++)
        data[i] = store[i];
}

void radixSort(int data[], int size)
{
    int biggest = data[0];
    for (int i = 1; i < size; i++)
    {
        if (data[i] > biggest)
            biggest = data[i];
    }

    for (int pos = 1; biggest / pos > 0; pos = pos * 10)
        digitSort(data, size, pos);
}

int main()
{
    int nums[6] = {170, 45, 75, 90, 802, 24};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Before Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";

    radixSort(nums, n);

    cout << "\n\nAfter Radix Sort:\n";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";

    int num2s[8] = {4, 2, 2, 8, 3, 3, 1, 7};
    int m = sizeof(num2s) / sizeof(num2s[0]);

    cout << "\n\nBefore Counting Sort:\n";
    for (int i = 0; i < m; i++)
        cout << num2s[i] << " ";

    countSort(num2s, m, 8);

    cout << "\n\nAfter Counting Sort:\n";
    for (int i = 0; i < m; i++)
        cout << num2s[i] << " ";

    return 0;
}
