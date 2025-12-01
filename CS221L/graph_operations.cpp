#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    bool isDirected;

    // Adjacency Matrix
    int adjMatrix[100][100];

    // Adjacency List (stored using arrays)
    int adjList[100][100];
    int size[100];

public:
    Graph(int v, bool directed) {
        vertices = v;
        isDirected = directed;

        // Initialize matrix
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                adjMatrix[i][j] = 0;

        // Initialize adjacency list sizes
        for (int i = 0; i < vertices; i++)
            size[i] = 0;
    }

    // Add Edge u -> v
    void addEdge(int u, int v) {
        // Update adjacency matrix
        adjMatrix[u][v] = 1;

        // Update adjacency list
        adjList[u][size[u]++] = v;

        if (!isDirected) {
            // For undirected graph, add reverse edge
            adjMatrix[v][u] = 1;
            adjList[v][size[v]++] = u;
        }
    }

    // 1. Count isolated nodes
    int countIsolated() {
        int count = 0;

        for (int i = 0; i < vertices; i++) {
            // Degree 0 → isolated
            if (size[i] == 0)  
                count++;
        }
        return count;
    }

    // 2. Detect self-loops using adjacency matrix
    bool hasSelfLoopMatrix() {
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[i][i] == 1)
                return true;
        }
        return false;
    }

    // 2. Detect self-loops using adjacency list
    bool hasSelfLoopList() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < size[i]; j++) {
                if (adjList[i][j] == i)
                    return true;
            }
        }
        return false;
    }

    // 3. Check if an undirected graph is complete (Adjacency Matrix)
    bool isCompleteMatrix() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (i == j) continue; // skip diagonal
                if (adjMatrix[i][j] == 0)
                    return false;
            }
        }
        return true;
    }

    // 3. Check if complete graph (Adjacency List)
    bool isCompleteList() {
        for (int i = 0; i < vertices; i++) {
            // In a complete graph, degree = vertices - 1
            if (size[i] != vertices - 1)
                return false;
        }
        return true;
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
        int u, w;
        cin >> u >> w;

        undirectedGraph.addEdge(u, w);
        directedGraph.addEdge(u, w);
    }

    cout << "\n------------------------------";
    cout << "\n   UNDIRECTED GRAPH RESULTS";
    cout << "\n------------------------------\n";

    cout << "Isolated nodes: " << undirectedGraph.countIsolated() << endl;

    cout << "Self-loop (Adjacency Matrix): "
         << (undirectedGraph.hasSelfLoopMatrix() ? "YES" : "NO") << endl;

    cout << "Self-loop (Adjacency List):   "
         << (undirectedGraph.hasSelfLoopList() ? "YES" : "NO") << endl;

    cout << "Is complete (Adjacency Matrix): "
         << (undirectedGraph.isCompleteMatrix() ? "YES" : "NO") << endl;

    cout << "Is complete (Adjacency List):   "
         << (undirectedGraph.isCompleteList() ? "YES" : "NO") << endl;


    cout << "\n------------------------------";
    cout << "\n     DIRECTED GRAPH RESULTS";
    cout << "\n------------------------------\n";

    cout << "Isolated nodes: " << directedGraph.countIsolated() << endl;

    cout << "Self-loop (Adjacency Matrix): "
         << (directedGraph.hasSelfLoopMatrix() ? "YES" : "NO") << endl;

    cout << "Self-loop (Adjacency List):   "
         << (directedGraph.hasSelfLoopList() ? "YES" : "NO") << endl;

    return 0;
}
