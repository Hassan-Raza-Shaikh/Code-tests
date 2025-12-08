#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;                 // Number of vertices
    list<int>* adj;        // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Add edge
    void addEdge(int u, int v, bool undirected = true) {
        adj[u].push_back(v);
        if (undirected)
            adj[v].push_back(u);
    }

    // Print graph
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adj[i])
                cout << v << " ";
            cout << endl;
        }
    }

    // BFS traversal
    void BFS(int start) {
        bool* visited = new bool[V]{false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // DFS traversal
    void DFSUtil(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

    void DFS(int start) {
        bool* visited = new bool[V]{false};
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency List:\n";
    g.printGraph();

    cout << "\nBFS from node 0: ";
    g.BFS(0);

    cout << "DFS from node 0: ";
    g.DFS(0);

    return 0;
}
