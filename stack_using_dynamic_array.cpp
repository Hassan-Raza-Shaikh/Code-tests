#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;     // array to store stack elements
    int top;      // index of the top element
    int capacity; // maximum size of the stack

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1; // stack is empty initially
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
    }

    // Pop the top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    // Peek at the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Driver code
int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70); // will cause overflow
    s.display();

    return 0;
}
