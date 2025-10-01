#include <iostream>
using namespace std;

#define MAX 100  // maximum size of stack

class Stack {
private:
    int arr[MAX]; // static array
    int top;      // index of top element

public:
    // Constructor
    Stack() {
        top = -1; // empty stack
    }

    // Push element into stack
    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
    }

    // Pop element from stack
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    // Peek at the top element
    int peek() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if empty
    bool isEmpty() {
        return top == -1;
    }

    // Display elements
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
    Stack s;

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
    s.display();

    return 0;
}
