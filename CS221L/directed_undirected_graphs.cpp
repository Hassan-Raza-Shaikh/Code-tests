#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    bool isDirected;

    // adjacency list stored using arrays
    // adj[i][j] = j-th neighbor of vertex i
    int adj[100][100];

    // size of each list
    int size[100];

public:
    Graph(int v, bool directed) {
        vertices = v;
        isDirected = directed;

        // initialize sizes to 0
        for (int i = 0; i < vertices; i++) {
            size[i] = 0;
        }
    }

    // Add edge u -> v (and v -> u if undirected)
    void addEdge(int u, int v) {
        adj[u][size[u]++] = v;

        if (!isDirected) {
            adj[v][size[v]++] = u;
        }
    }

    // Display adjacency list
    void display() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";

            for (int j = 0; j < size[i]; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    Graph undirectedGraph(v, false);
    Graph directedGraph(v, true);

    cout << "\nEnter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, vtx;
        cin >> u >> vtx;

        undirectedGraph.addEdge(u, vtx);
        directedGraph.addEdge(u, vtx);
    }

    cout << "\nUndirected Graph:\n";
    undirectedGraph.display();

    cout << "\nDirected Graph:\n";
    directedGraph.display();

    return 0;
}
