#include <iostream>
using namespace std;

class HashTable {
    static const int SIZE = 10;
    int table[SIZE];

public:
    HashTable() {
        // -1 means empty slot
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    // hash function
    int hashFunction(int key) {
        return key % SIZE;
    }

    // insert using quadratic probing
    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        // quadratic probing: h(key, i) = (h + i*i) % SIZE
        while (table[(index + i * i) % SIZE] != -1) {
            i++;
            if (i == SIZE) {
                cout << "Hash table full\n";
                return;
            }
        }

        table[(index + i * i) % SIZE] = key;
    }

    // search using quadratic probing
    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[(index + i * i) % SIZE] != -1) {
            if (table[(index + i * i) % SIZE] == key)
                return true;

            i++;
            if (i == SIZE)
                break;
        }
        return false;
    }

    // display hash table
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << " -> ";
            if (table[i] == -1)
                cout << "EMPTY";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(12);
    ht.insert(22);
    ht.insert(32);
    ht.insert(42);
    ht.insert(15);

    ht.display();

    cout << "\nSearching 22: "
         << (ht.search(22) ? "Found" : "Not Found") << endl;

    return 0;
}
