#include <iostream>
#include <string>
using namespace std;

// Person class
class Person {
public:
    string name;
    string address;
    string phone;

    Person() {}
    Person(string n, string a, string p) {
        name = n;
        address = a;
        phone = p;
    }
};

// Node class for linked list
class Node {
public:
    Person data;
    Node* next;
    Node(Person p) {
        data = p;
        next = NULL;
    }
};

// Linked List class
class AddressBook {
private:
    Node* head;

public:
    AddressBook() {
        head = NULL;
    }

    // Insert in alphabetical order
    void insert(Person p) {
        Node* newNode = new Node(p);

        // If list is empty OR new node comes before head
        if (!head || p.name < head->data.name) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Otherwise, find position
        Node* temp = head;
        while (temp->next && temp->next->data.name < p.name) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Find person by name
    void find(string name) {
        Node* temp = head;
        while (temp) {
            if (temp->data.name == name) {
                cout << "Record Found:\n";
                cout << "Name: " << temp->data.name << endl;
                cout << "Address: " << temp->data.address << endl;
                cout << "Phone: " << temp->data.phone << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Record not found for: " << name << endl;
    }

    // Print all records
    void display() {
        Node* temp = head;
        cout << "\nAddress Book Records:\n";
        while (temp) {
            cout << temp->data.name << " | " 
                 << temp->data.address << " | " 
                 << temp->data.phone << endl;
            temp = temp->next;
        }
    }
};

// Driver code
int main() {
    AddressBook book;

    int n;
    cout << "Enter number of records: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string name, address, phone;
        cout << "\nEnter name: ";
        getline(cin, name);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter phone: ";
        getline(cin, phone);

        Person p(name, address, phone);
        book.insert(p);
    }

    book.display();

    // Find example
    string searchName;
    cout << "\nEnter name to search: ";
    getline(cin, searchName);
    book.find(searchName);

    return 0;
}