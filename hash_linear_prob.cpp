#include <iostream>
using namespace std;

class HashTable {
    static const int SIZE = 10;
    int table[SIZE];

public:
    HashTable() {
        // initialize table with -1 (means empty)
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    // hash function
    int hashFunction(int key) {
        return key % SIZE;
    }

    // insert using linear probing
    void insert(int key) {
        int index = hashFunction(key);

        // find next empty slot
        while (table[index] != -1) {
            index = (index + 1) % SIZE;
        }

        table[index] = key;
    }

    // search key
    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;

            index = (index + 1) % SIZE;

            // full loop done
            if (index == startIndex)
                break;
        }
        return false;
    }

    // display table
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
