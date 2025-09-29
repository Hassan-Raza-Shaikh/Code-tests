#include <iostream>
using namespace std;

struct Compartment {
    int id;
    int capacity;
    Compartment* prev;
    Compartment* next;
    Compartment(int cid, int cap) {
        id = cid;
        capacity = cap;
        prev = NULL;
        next = NULL;
    }
};

Compartment* head = NULL;

void insertAtBeginning(int cid, int cap) {
    Compartment* newCompartment = new Compartment(cid, cap);
    newCompartment->next = head;
    if (head != NULL)
        head->prev = newCompartment;
    head = newCompartment;
    cout << "Compartment " << cid << " added at the beginning.\n";
}

void insertAtEnd(int cid, int cap) {
    Compartment* newCompartment = new Compartment(cid, cap);
    if (head == NULL) {
        head = newCompartment;
        cout << "Compartment " << cid << " added as the first compartment.\n";
        return;
    }
    Compartment* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newCompartment;
    newCompartment->prev = temp;
    cout << "Compartment " << cid << " added at the end.\n";
}

void insertAtPosition(int cid, int cap, int pos) {
    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1) {
        insertAtBeginning(cid, cap);
        return;
    }
    Compartment* newCompartment = new Compartment(cid, cap);
    Compartment* temp = head;
    int count = 1;
    while (count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Position out of range!\n";
        delete newCompartment;
        return;
    }
    newCompartment->next = temp->next;
    newCompartment->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newCompartment;
    temp->next = newCompartment;
    cout << "Compartment " << cid << " added at position " << pos << ".\n";
}

void deleteAtPosition(int pos) {
    if (head == NULL || pos < 1) {
        cout << "Train is empty or invalid position!\n";
        return;
    }
    Compartment* temp = head;
    if (pos == 1) { // Delete head
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        cout << "Compartment " << temp->id << " removed from position 1.\n";
        delete temp;
        return;
    }
    int count = 1;
    while (count < pos && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Position out of range!\n";
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    cout << "Compartment " << temp->id << " removed from position " << pos << ".\n";
    delete temp;
}

void displayForward() {
    if (head == NULL) {
        cout << "Train is empty.\n";
        return;
    }
    Compartment* temp = head;
    cout << "\nTrain Compartments (Forward):\n";
    while (temp != NULL) {
        cout << "[ID: " << temp->id << ", Capacity: " << temp->capacity << "] ";
        temp = temp->next;
    }
    cout << "\n";
}

void displayBackward() {
    if (head == NULL) {
        cout << "Train is empty.\n";
        return;
    }
    Compartment* temp = head;
    while (temp->next != NULL)
        temp = temp->next; // Move to last compartment
    cout << "\nTrain Compartments (Backward):\n";
    while (temp != NULL) {
        cout << "[ID: " << temp->id << ", Capacity: " << temp->capacity << "] ";
        temp = temp->prev;
    }
    cout << "\n";
}

void totalCapacity() {
    if (head == NULL) {
        cout << "Train is empty.\n";
        return;
    }
    int total = 0;
    Compartment* temp = head;
    while (temp != NULL) {
        total += temp->capacity;
        temp = temp->next;
    }
    cout << "\nTotal Passenger Capacity of the Train: " << total << "\n";
}

int main() {
    int choice, id, capacity, position;
    do {
        cout << "\n--- Train Compartment Manager ---\n";
        cout << "1. Add Compartment at Beginning\n";
        cout << "2. Add Compartment at End\n";
        cout << "3. Add Compartment at Specific Position\n";
        cout << "4. Delete Compartment from Position\n";
        cout << "5. Display Train Forward\n";
        cout << "6. Display Train Backward\n";
        cout << "7. Show Total Passenger Capacity\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Compartment ID and Capacity: ";
                cin >> id >> capacity;
                insertAtBeginning(id, capacity);
                break;
            case 2:
                cout << "Enter Compartment ID and Capacity: ";
                cin >> id >> capacity;
                insertAtEnd(id, capacity);
                break;
            case 3:
                cout << "Enter Compartment ID, Capacity, and Position: ";
                cin >> id >> capacity >> position;
                insertAtPosition(id, capacity, position);
                break;
            case 4:
                cout << "Enter Position to Delete: ";
                cin >> position;
                deleteAtPosition(position);
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                totalCapacity();
                break;
            case 8:
                cout << "Exiting Train Compartment Manager...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}