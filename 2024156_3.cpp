#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

struct node 
{
    int x;
    node* next;
};

class Stack 
{
    node* head;
    public:
    Stack() 
    { head = nullptr; }

    bool isempty() 
    { return head == nullptr; }

    void push(int v) 
    {
        node* nn = new node;
        nn->x = v;
        nn->next = head;
        head = nn;
    }

    void pop() 
    {
        if (!isempty()) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int peak() 
    { return isempty() ? 0 : head->x; }

    void printStack() {
        node* temp = head;
        cout << "[ ";
        while (temp) {
            cout << temp->x << " ";
            temp = temp->next;
        }
        cout << "]";
    }
};

void arrangement() 
{
    int n, k;
    cout << "Enter number of railroad cars: ";
    cin >> n;
    cout << "Enter number of holding tracks: ";
    cin >> k;

    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    srand(time(0));
    for (int i = n - 1; i > 0; i--) swap(arr[i], arr[rand() % (i + 1)]);

    cout << "Incoming order: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    Stack s[k];
    int nextExpected = 1;
    int output[n];
    int outIndex = 0;

    for (int i = 0; i < n; i++) {
        int car = arr[i];
        cout << "\nIncoming car: " << car << endl;

        if (car == nextExpected) 
        {
            output[outIndex++] = car;
            nextExpected++;

            bool moved = true;
            while (moved) {
                moved = false;
                for (int j = 0; j < k; j++) {
                    if (!s[j].isempty() && s[j].peak() == nextExpected) {
                        output[outIndex++] = nextExpected;
                        s[j].pop();
                        nextExpected++;
                        moved = true;
                    }
                }
            }
        } 
        else 
        {
            int bestTrack = -1;
            int bestDiff = INT_MAX;

            // Store all tops first
            int tops[k];
            for (int j = 0; j < k; j++) tops[j] = s[j].peak();

            for (int j = 0; j < k; j++) {
                if (s[j].isempty()) {
                    if (bestTrack == -1) bestTrack = j; // fallback if no better
                } else if (tops[j] > car) {
                    int diff = tops[j] - car;
                    if (diff < bestDiff) {
                        bestDiff = diff;
                        bestTrack = j;
                    }
                }
            }

            if (bestTrack == -1) {
                cout << " Rearrangement not possible.\n";
                return;
            }

            s[bestTrack].push(car);
            cout << "→ Pushed car " << car << " into track " << bestTrack + 1 << endl;
        }

        cout << "Holding tracks: ";
        for (int j = 0; j < k; j++) {
            s[j].printStack();
            cout << " ";
        }
        cout << endl;
    }

    cout << "\n Final output order: ";
    for (int i = 0; i < outIndex; i++)
        cout << output[i] << " ";
    cout << endl;
}

int main() 
{
    arrangement();
    return 0;
}