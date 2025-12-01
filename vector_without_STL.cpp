#include <iostream>
using namespace std;

class MyVector {
private:
    int* arr;        // pointer to array
    int capacity;    // total allocated space
    int current;     // number of elements

public:
    // constructor
    MyVector() {
        arr = new int[1];
        capacity = 1;
        current = 0;
    }

    // push_back
    void push_back(int value) {
        if (current == capacity) {
            // resize: create larger array
            int* temp = new int[capacity * 2];

            for (int i = 0; i < capacity; i++)
                temp[i] = arr[i];

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = value;
        current++;
    }

    // pop_back
    void pop_back() {
        if (current > 0)
            current--;
    }

    // get element
    int operator[](int index) {
        if (index < current)
            return arr[index];
        cout << "Index out of bounds\n";
        return -1;
    }

    // size of vector
    int size() {
        return current;
    }

    // destructor
    ~MyVector() {
        delete[] arr;
    }
};

// ------------------ TEST ------------------
int main() {
    MyVector v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Vector elements: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\nSize: " << v.size() << endl;

    v.pop_back();

    cout << "After pop_back: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}