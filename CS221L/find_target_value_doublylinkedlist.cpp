#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Function to insert node at end (for demo)
void insertEnd(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "DLL Elements: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to search target value and show positions + count
void findOccurrences(int target)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    int position = 1, count = 0;
    bool found = false;
    cout << "Positions of value " << target << ": ";
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            cout << position << " ";
            count++;
            found = true;
        }
        temp = temp->next;
        position++;
    }
    cout << endl;
    if (found)
        cout << "Total occurrences: " << count << endl;
    else
        cout << "Value not found in the list." << endl;
}

int main()
{
    // Sample data
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(20);
    insertEnd(40);
    insertEnd(20);
    display();
    int target;
    cout << "Enter value to search: ";
    cin >> target;
    findOccurrences(target);
    return 0;
}