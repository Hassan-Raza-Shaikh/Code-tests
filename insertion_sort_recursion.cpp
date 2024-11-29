// #include<iostream>
// using namespace std;

// void insertionSort(int array[],int n)
// {
//     if(n>=1)
//     {
//         return;
//     }
    
//     int key=array[n];
//         int j=n;
//         while(j>0 && key<array[j-1])
//         {
//             int temp = array[j];
//             array[j]=array[j-1];
//             array[j-1]=temp;
//             j--;
//         }
//     insertionSort(array,n-1); 
// }

// int main()
// {
//     int array[6]={75,65,25,1,9,7};

// //Insertion sort

//     // for(int i=1;i<6;i++)
//     // {
//     //     int key=array[i];
//     //     int j=i;
//     //     while(j>0 && key<array[j-1])
//     //     {
//     //         int temp = array[j];
//     //         array[j]=array[j-1];
//     //         array[j-1]=temp;
//     //         j--;
//     //     }
//     // }

//     // for(int i=0;i<6;i++)
//     // {
//     //     cout<<","<<array[i];
//     // }


//     insertionSort(array,5);

//     for(int i=0;i<6;i++)
//     {
//         cout<<","<<array[i];
//     }
    
//     return 0;
// }

#include <iostream>
using namespace std;

void insertionSort(int array[], int n)
{
    // Base case: If the size is 1, the array is already sorted
    if (n <= 0)
    {
        return;
    }

    // Sort the first n-1 elements recursively
    insertionSort(array, n - 1);

    // Insert the nth element in the sorted part
    int key = array[n];
    int j = n - 1;

    while (j >= 0 && array[j] > key)
    {
        array[j + 1] = array[j];
        j--;
    }

    array[j + 1] = key;
}

int main()
{
    int array[6] = {75, 65, 25, 1, 9, 7};

    // Perform insertion sort
    insertionSort(array, 5);

    // Print the sorted array
    for (int i = 0; i < 6; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
