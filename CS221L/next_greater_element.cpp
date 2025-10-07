#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }
    void push(int x) {
        if (top == MAX - 1) return;
        arr[++top] = x;
    }
    void pop() {
        if (top == -1) return;
        top--;
    }
    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }
    bool isEmpty() {
        return (top == -1);
    }
};

void printNGE(int arr[], int n) {
    int result[n];
    Stack st;
    for (int i = n - 1; i >= 0; i--) {
        // Pop smaller or equal elements
        while (!st.isEmpty() && st.peek() <= arr[i]) {
            st.pop();
        }
        // If empty → no greater element
        result[i] = st.isEmpty() ? -1 : st.peek();
        // Push current element
        st.push(arr[i]);
    }
    // Print result
    for (int i = 0; i < n; i++) {
        cout << "NGE(" << arr[i] << ") -> " << result[i] << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}