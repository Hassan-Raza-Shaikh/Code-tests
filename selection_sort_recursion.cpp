#include <iostream>
using namespace std;

// Recursive function to perform Selection Sort
void recursiveSelectionSort(int arr[], int n) {
    // Base case: If the array is fully sorted
    if (n <= 1) {
        return;
    }

    // Find the index of the maximum element in the current array
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    // Swap the maximum element with the last element
    swap(arr[maxIndex], arr[n - 1]);

    // Recur for the rest of the array (excluding the last element)
    recursiveSelectionSort(arr, n - 1);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    recursiveSelectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
