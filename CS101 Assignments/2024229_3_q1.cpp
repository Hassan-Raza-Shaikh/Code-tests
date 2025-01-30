#include <iostream>
#include <string>
using namespace std;

// Function to display family details or Iffat's house
void DISPLAY(string names[], string status[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << names[i] << ": " << status[i] << endl;
    }
    cout << endl;
}

// Function to swap names and their corresponding statuses
void SWAP(string& name1, string& status1, string& name2, string& status2) 
{
    string tempName = name1;
    string tempStatus = status1;
    name1 = name2;
    status1 = status2;
    name2 = tempName;
    status2 = tempStatus;
}

// Function to sort the family details based on status
// 'P' are sorted before 'N'
void SELECTION_SORT(string names[], string status[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        int maxIndex = i;
        // Find the member with the highest priority ('P') in the unsorted part of the array
        for (int j = i + 1; j < size; j++) 
        {
            if (status[j] > status[maxIndex]) 
            {
                maxIndex = j;
            }
        }
        // Swap the current member with the highest-priority member
        if (maxIndex != i) 
        {
            SWAP(names[i], status[i], names[maxIndex], status[maxIndex]);
        }
    }
}

// Function to transfer non-COVID family members ('N') to Iffat's house roster
void TRANSFER_NON_COVID(string names[], string status[], string iffatNames[], string iffatStatus[], int size, int& iffatCount) 
{
    for (int i = 0; i < size; i++) 
    {
        if (status[i] == "N")  // Check if the member is negative
        { 
            iffatNames[iffatCount] = names[i];
            iffatStatus[iffatCount] = status[i];
            iffatCount++;
        }
    }
}

int main() 
{
    // Initial family details: names and their statuses
    string names[10] = {"Amna", "Father", "Mother", "Sister", "Brother1", "Brother2", "Grandfather", "Grandmother", "Uncle", "Aunt"};
    string status[10] = {"P", "N", "P", "N", "P", "N", "N", "N", "N", "N"};

    // Arrays to hold details of family members at Iffat's house
    string iffatNames[10];
    string iffatStatus[10];
    int iffatCount = 0; // Counter for members transferred to Iffat's house

    cout << "Initial Family Details: \n";
    DISPLAY(names, status, 10);

    SELECTION_SORT(names, status, 10);

    cout << "Sorted Family Details: \n";
    DISPLAY(names, status, 10);

    TRANSFER_NON_COVID(names, status, iffatNames, iffatStatus, 10, iffatCount);

    cout << "Iffat's House members: \n";
    DISPLAY(iffatNames, iffatStatus, iffatCount);

    return 0;
}