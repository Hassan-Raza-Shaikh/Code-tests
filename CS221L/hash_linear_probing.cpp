#include<iostream>
using namespace std;

#define SIZE 10

class HashTable
{
    private:
    
    int table[SIZE];

    public:

    HashTable()
    {
        for(int i=0;i<SIZE;i++)
            table[i] = -1;
    }
    
    int HashFunction(int key)
    {
        return key % SIZE;
    }

    void insert(int key)
    {
        int index = HashFunction(key);
        int i=0;
        while(table[index] != -1 && i<SIZE)
        {
            i++;
            index = (index + 1) % SIZE;
        }
        table[index] = key;
    }

    bool search(int key)
    {
        int index = HashFunction(key);
        int i=0;
        while(table[index] != -1 && i<SIZE)
        {
            if(table[index] == key)
                return true;
            i++;
            index = (index + 1) % SIZE;
        }
        return false;
    }

    void display()
    {
        for(int i=0;i<SIZE;i++)
        {
            cout<<i<<" -> ";
            if(table[i] == -1)
                cout<<"EMPTY";
            else
                cout<<table[i];
            cout<<endl;
        }
    }
};

int main()
{
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(25);
    ht.insert(35);
    ht.display();

    int key = 25;
    if(ht.search(key))
        cout<<key<<" found in hash table"<<endl;
    else
        cout<<key<<" not found in hash table"<<endl;

    key = 40;
    if(ht.search(key))
        cout<<key<<" found in hash table"<<endl;
    else
        cout<<key<<" not found in hash table"<<endl;

    return 0;
}