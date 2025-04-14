#include <iostream>
using namespace std;

template <typename T>
class Stack 
{
private:
    T* arr;
    int capacity;
    int top;
public:
    Stack(int size = 10) : arr(new T[size]), capacity(size), top(-1) {}

    ~Stack() { delete[] arr; }

    void push(T elem) 
    {
        if (top < capacity - 1)
            arr[++top] = elem;
        else
            cout << "Stack overflow!" <<endl;
    }

    T pop() 
    {
        if (top > -1)
            return arr[top--];
        cout << "Stack underflow!" <<endl;
        return T();
    }

    friend ostream& operator<<(ostream& os, const Stack<T>& stack) 
    {
        for (int i = stack.top; i >= 0; --i) 
        {
            os << stack.arr[i] << " ";
        }
        return os;
    }
};


int main() 
{
    Stack<int> s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1.pop() <<endl;
    cout << s1.pop() << endl;

    Stack<double> s2(3);
    s2.push(1.23);
    s2.push(4.56);
    cout << s2.pop() <<endl;

    return 0;
}
