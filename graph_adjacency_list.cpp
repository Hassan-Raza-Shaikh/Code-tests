#include <iostream>
using namespace std;

#define MAX 10   // maximum vertices allowed

// Node for adjacency list
struct Node {
    int v;
    Node* next;
};

class Graph {
private:
    Node* head[MAX];   // array of linked lists
    int n;             // current number of vertices
    bool directed;

public:
    Graph(int vertices, bool isDirected) {
        n = vertices;
        directed = isDirected;

        for (int i = 0; i < MAX; i++)
            head[i] = nullptr; // initialize all heads to null
    }

    void addVertex() {
        if (n >= MAX) {
            cout << "Maximum vertices reached!\n";
            return;
        }
        head[n] = nullptr; // empty list for new vertex
        cout << "Vertex " << n << " added.\n";
        n++;
    }

    void addEdge(int u, int v) {
        if (u >= n || v >= n) {
            cout << "Invalid edge!\n";
            return;
        }

        Node* newNode = new Node{v, head[u]};
        head[u] = newNode;

        if (!directed) {
            Node* newNode2 = new Node{u, head[v]};
            head[v] = newNode2;
        }
    }

    void deleteEdge(int u, int v) {
        if (u >= n || v >= n) {
            cout << "Invalid edge!\n";
            return;
        }

        // delete v from u's list
        Node* curr = head[u];
        Node* prev = nullptr;

        while (curr != nullptr && curr->v != v) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != nullptr) {
            if (prev == nullptr) head[u] = curr->next;
            else prev->next = curr->next;
            delete curr;
        }

        if (!directed) {
            // delete u from v's list
            curr = head[v];
            prev = nullptr;

            while (curr != nullptr && curr->v != u) {
                prev = curr;
                curr = curr->next;
            }

            if (curr != nullptr) {
                if (prev == nullptr) head[v] = curr->next;
                else prev->next = curr->next;
                delete curr;
            }
        }
    }

    void deleteVertex(int v) {
        if (v < 0 || v >= n) {
            cout << "Invalid vertex!\n";
            return;
        }

        // Step 1: delete entire adjacency list of vertex v
        Node* curr = head[v];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }

        // Shift lists up
        for (int i = v; i < n - 1; i++) {
            head[i] = head[i + 1];
        }
        head[n - 1] = nullptr;

        // Step 2: remove v from all other adjacency lists
        for (int i = 0; i < n; i++) {
            deleteEdge(i, v);
        }

        // Step 3: shift all vertex numbers down by 1
        for (int i = 0; i < n; i++) {
            Node* ptr = head[i];
            while (ptr != nullptr) {
                if (ptr->v > v) ptr->v--;
                ptr = ptr->next;
            }
        }

        n--;
        cout << "Vertex " << v << " deleted.\n";
    }

    void printGraph() {
        cout << "\nAdjacency List (" << n << " vertices):\n";
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            Node* temp = head[i];
            while (temp != nullptr) {
                cout << temp->v << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4, false);  // 4 vertices, undirected

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();

    cout << "\nDeleting edge 1-2...\n";
    g.deleteEdge(1, 2);
    g.printGraph();

    cout << "\nAdding new vertex...\n";
    g.addVertex();
    g.printGraph();

    cout << "\nDeleting vertex 1...\n";
    g.deleteVertex(1);
    g.printGraph();

    return 0;
}
