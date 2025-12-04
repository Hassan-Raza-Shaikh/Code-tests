#include <iostream>
using namespace std;

#define MAX 10   // static maximum graph size

class Graph {
private:
    int adj[MAX][MAX];
    int n;            // current number of vertices
    bool directed;

public:
    Graph(int vertices, bool isDirected) {
        n = vertices;
        directed = isDirected;

        // initialize full matrix
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                adj[i][j] = 0;
    }

    void addVertex() {
        if (n >= MAX) {
            cout << "Maximum vertices reached!\n";
            return;
        }

        for (int i = 0; i <= n; i++) {
            adj[n][i] = 0;
            adj[i][n] = 0;
        }

        cout << "Vertex " << n << " added.\n";
        n++;
    }

    void deleteVertex(int v) {
        if (v < 0 || v >= n) {
            cout << "Invalid vertex!\n";
            return;
        }

        // Shift rows UP
        for (int i = v; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = adj[i + 1][j];
            }
        }

        // Shift columns LEFT
        for (int j = v; j < n - 1; j++) {
            for (int i = 0; i < n; i++) {
                adj[i][j] = adj[i][j + 1];
            }
        }

        // Clear last row/column
        for (int i = 0; i < n; i++) {
            adj[n - 1][i] = 0;
            adj[i][n - 1] = 0;
        }

        n--;
        cout << "Vertex " << v << " deleted.\n";
    }

    void addEdge(int u, int v) {
        if (u >= n || v >= n) {
            cout << "Invalid edge!\n";
            return;
        }
        adj[u][v] = 1;
        if (!directed)
            adj[v][u] = 1;
    }


    void deleteEdge(int u, int v) {
        if (u >= n || v >= n) {
            cout << "Invalid edge!\n";
            return;
        }
        adj[u][v] = 0;
        if (!directed)
            adj[v][u] = 0;
    }

    void printMatrix() {
        cout << "\nAdjacency Matrix (" << n << " vertices):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(4, false); // 4 vertices, undirected

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printMatrix();

    cout << "\nDeleting edge 1-2...\n";
    g.deleteEdge(1, 2);
    g.printMatrix();

    cout << "\nAdding new vertex...\n";
    g.addVertex();
    g.printMatrix();

    cout << "\nDeleting vertex 1...\n";
    g.deleteVertex(1);
    g.printMatrix();

    return 0;
}
