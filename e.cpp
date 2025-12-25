#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    int count;   // number of nodes

public:
    LinkedList() {
        head = NULL;
        count = 0;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        count++;   // increment node count
    }

    // Bubble Sort using FOR loops (array-style)
    void bubbleSort() {
       if(head==nullptr)
       {
        return;
       }
       for(int i=0;i<count-1;i++){
        Node*curr=head;
        for(int j=0;j<count-i-1;j++){
           
               if(curr->data > curr->next->data)
               {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data=temp;
               }
               curr=curr->next;
        }
       }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insert(5);
    list.insert(1);
    list.insert(4);
    list.insert(2);
    list.insert(8);

    cout << "Before Sorting:\n";
    list.display();

    list.bubbleSort();

    cout << "After Sorting:\n";
    list.display();

    return 0;
}
