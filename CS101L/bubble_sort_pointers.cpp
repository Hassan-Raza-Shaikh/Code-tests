// Bubble sort in C++

#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) 
{
    int *ptr=array;
  for (int step = 0; step < size -1; ++step) 
  {
    for (int i = 0; i < size - step - 1; ++i) 
    {
      if (*(ptr+i) > *(ptr+i+1)) 
      {
        int temp = *(ptr+i);
        *(ptr+i) = *(ptr+i+1);
        *(ptr+i+1) = temp;
      }
    }
  }
}

void printArray(int array[], int size) 
{
  for (int i = 0; i < size; ++i) 
  {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() 
{
  int data[] = {-2, 45, 0, 11, -9};
  
  int size = sizeof(data) / sizeof(data[0]);
  
  bubbleSort(data, size);
  
  cout << "Sorted Array in Ascending Order:\n";  
  printArray(data, size);
}