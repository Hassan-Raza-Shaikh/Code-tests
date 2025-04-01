#include<iostream>
using namespace std;

void print(int *arr)
{
    arr[0]=3;
    arr[1]=4;
    arr[2]=5;
    cout<<arr[2]<<endl<<arr[1];
}

int main()
{
    int size=1;               // Declaring a small size and letting it increase like this works but apparently may cause issues
    int *arr = new int[size];
   
    print(arr);

    delete [] arr;

    return 0;
}