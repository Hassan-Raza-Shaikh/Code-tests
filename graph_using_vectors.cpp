#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;  // adjacency list using vectors
    bool directed;

public:
    Graph(bool isDirected) {
        directed = isDirected;
    }

    void addVertex() {
        adj.push_back(vector<int>());  // create empty adjacency list
        cout << "Vertex " << adj.size() - 1 << " added.\n";
    }

    void addEdge(int u, int v) {
        if (u >= adj.size() || v >= adj.size()) {
            cout << "Invalid edge!\n";
            return;
        }

        adj[u].push_back(v);

        if (!directed)
            adj[v].push_back(u);
    }

    void deleteEdge(int u, int v) {
        if (u >= adj.size() || v >= adj.size()) {
            cout << "Invalid edge!\n";
            return;
        }

        // remove v from u's adjacency list
        removeFromList(adj[u], v);

        // remove u from v's adjacency list (if undirected)
        if (!directed)
            removeFromList(adj[v], u);
    }

    // Helper to remove element from vector
    void removeFromList(vector<int> &list, int val) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == val) {
                list.erase(list.begin() + i);
                return;
            }
        }
    }

    void deleteVertex(int v) {
        if (v < 0 || v >= adj.size()) {
            cout << "Invalid vertex!\n";
            return;
        }

        // Step 1: Remove edges pointing to v, and shift numbered vertices
        for (int i = 0; i < adj.size(); i++) {
            removeFromList(adj[i], v);

            // fix edge numbers after deleting vertex
            for (int &to : adj[i]) {
                if (to > v) to--;   // shift indices down
            }
        }

        // Step 2: Delete the vertex's adjacency list
        adj.erase(adj.begin() + v);

        cout << "Vertex " << v << " deleted.\n";
    }

    void printGraph() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < adj.size(); i++) {
            cout << i << " -> ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(false);  // undirected graph

    g.addVertex();  // 0
    g.addVertex();  // 1
    g.addVertex();  // 2
    g.addVertex();  // 3

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();

    cout << "\nDeleting edge 1-2...\n";
    g.deleteEdge(1, 2);
    g.printGraph();

    cout << "\nAdding vertex...\n";
    g.addVertex();   // new vertex 4
    g.printGraph();

    cout << "\nDeleting vertex 1...\n";
    g.deleteVertex(1);
    g.printGraph();

    return 0;
}
