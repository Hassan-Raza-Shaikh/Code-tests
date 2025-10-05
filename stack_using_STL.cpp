#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Declare a stack of integers
    stack<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30

    // Pop an element
    s.pop();
    cout << "After pop, top element: " << s.top() << endl; // 20

    // Check size
    cout << "Stack size: " << s.size() << endl;

    // Check if empty
    if (s.empty())
        cout << "Stack is empty!" << endl;
    else
        cout << "Stack is not empty!" << endl;

    // Display all elements by popping
    cout << "Stack elements (from top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
