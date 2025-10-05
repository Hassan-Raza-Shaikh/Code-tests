#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front; // front of queue
    Node* rear;  // rear of queue

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue: insert element at rear
    void enqueue(int x) {
        Node* temp = new Node(x);

        if (rear == nullptr) {
            // Queue is empty
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    // Dequeue: remove element from front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << temp->data << endl;

        front = front->next;

        if (front == nullptr) // if queue became empty
            rear = nullptr;

        delete temp;
    }

    // Peek front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    return 0;
}
