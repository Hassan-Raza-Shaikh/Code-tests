#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    string address;
    string phone;

    Person() {}
    Person(string n, string a, string p)
    {
        name = n;
        address = a;
        phone = p;
    }

    void display()
    {
        cout << "Name: " << name << ", Address: " << address << ", Phone: " << phone << endl;
    }
};

struct Node
{
    Person data;
    Node *next;
    Node(Person p)
    {
        data = p;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // tO nsert in alphabetical order
    void insert(Person p)
    {
        Node *newNode = new Node(p);

        // if empty list or new node should be first
        if (head == nullptr || p.name < head->data.name)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        // otherwise find correct position
        Node *current = head;
        while (current->next != nullptr && current->next->data.name < p.name)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Display all
    void displayAll()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            temp->data.display();
            temp = temp->next;
        }
    }

    // Find by name
    void find(string name)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data.name == name)
            {
                cout << "Record found: ";
                temp->data.display();
                return;
            }
            temp = temp->next;
        }
        cout << "No record found with name: " << name << endl;
    }
};

int main()
{
    LinkedList addressBook;
    int n;
    cout << "How many persons do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name, address, phone;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter phone: ";
        cin >> phone;

        Person p(name, address, phone);
        addressBook.insert(p);
    }

    cout << "\nAll Records in Address Book (Alphabetical Order):\n";
    addressBook.displayAll();

    string searchName;
    cout << "\nEnter a name to search: ";
    cin >> searchName;
    addressBook.find(searchName);

    return 0;
}
