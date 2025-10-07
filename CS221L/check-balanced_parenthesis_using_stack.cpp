#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(char x) {
        if (top == MAX - 1) return;
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) return;
        top--;
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

bool isBalanced(string expr) {
    Stack st;
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.isEmpty()) return false;
            char top = st.peek();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.isEmpty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Balanced " << endl;
    else
        cout << "Not Balanced " << endl;
    return 0;
}