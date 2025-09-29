#include <iostream>
#include <string>
using namespace std;

class Contact {
public:
    string fullName;
    string homeAddress;
    string phoneNumber;

    Contact() {}
    Contact(string n, string a, string p) {
        fullName = n;
        homeAddress = a;
        phoneNumber = p;
    }

    void show() {
        cout << "Name: " << fullName 
             << ", Address: " << homeAddress 
             << ", Phone: " << phoneNumber << endl;
    }
};

struct Node {
    Contact info;
    Node* next;
    Node(Contact c) {
        info = c;
        next = nullptr;
    }
};

class AddressBook {
private:
    Node* head;

public:
    AddressBook() {
        head = nullptr;
    }

    void addContact(Contact c) {
        Node* newNode = new Node(c);

        if (head == nullptr || c.fullName < head->info.fullName) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->info.fullName < c.fullName) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void showAll() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->info.show();
            temp = temp->next;
        }
    }

    void searchByName(string name) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->info.fullName == name) {
                cout << "Contact found: ";
                temp->info.show();
                return;
            }
            temp = temp->next;
        }
        cout << "No contact exists with name: " << name << endl;
    }
};

int main() {
    AddressBook myBook;
    int total;
    cout << "How many contacts would you like to add? ";
    cin >> total;

    for (int i = 0; i < total; i++) {
        string n, a, p;
        cout << "Enter name: ";
        cin >> n;
        cout << "Enter address: ";
        cin >> a;
        cout << "Enter phone: ";
        cin >> p;

        Contact c(n, a, p);
        myBook.addContact(c);
    }

    cout << "\nContacts in Address Book (Sorted by Name):\n";
    myBook.showAll();

    string query;
    cout << "\nEnter a name to search: ";
    cin >> query;
    myBook.searchByName(query);

    return 0;
}
