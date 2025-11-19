#include <iostream>
using namespace std;

class Graph {
private:
    int adj[100][100];     // adjacency matrix
    int vertices;          // number of vertices
    bool exists[100];      // tracks which vertices exist

public:
    Graph() {
        vertices = 0;
        for (int i = 0; i < 100; i++) {
            exists[i] = false;
            for (int j = 0; j < 100; j++)
                adj[i][j] = 0;
        }
    }

    // ------------------------------
    // ADDING A VERTEX
    // ------------------------------
    void addVertex(int v) {
        if (exists[v]) {
            cout << "Vertex already exists.\n";
            return;
        }
        exists[v] = true;
        vertices++;
        cout << "Vertex " << v << " added.\n";
    }

    // ------------------------------
    // ADDING AN EDGE
    // ------------------------------
    void addEdge(int u, int v) {
        addVertex(u);
        addVertex(v);

        adj[u][v] = 1;
        adj[v][u] = 1;
        cout << "Edge (" << u << ", " << v << ") added.\n";
    }

    // ------------------------------
    // DELETING AN EDGE
    // ------------------------------
    void deleteEdge(int u, int v) {
        if (!adj[u][v]) {
            cout << "Edge does not exist.\n";
            return;
        }

        adj[u][v] = 0;
        adj[v][u] = 0;
        cout << "Edge (" << u << ", " << v << ") deleted.\n";
    }

    // ------------------------------
    // SEARCH OPERATIONS
    // ------------------------------
    bool hasVertex(int v) {
        return exists[v];
    }

    bool hasEdge(int u, int v) {
        return adj[u][v] == 1;
    }

    // ------------------------------
    // BFS (NO STL)
    // ------------------------------
    void BFS(int start) {
        if (!exists[start]) {
            cout << "Start vertex does not exist.\n";
            return;
        }

        bool visited[100] = {false};
        int queue[100], front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "BFS: ";

        while (front < rear) {
            int curr = queue[front++];

            cout << curr << " ";

            for (int i = 0; i < 100; i++) {
                if (exists[i] && adj[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }

        cout << endl;
    }

    // ------------------------------
    // DFS (NO STL)
    // ------------------------------
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < 100; i++) {
            if (exists[i] && adj[v][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        if (!exists[start]) {
            cout << "Start vertex does not exist.\n";
            return;
        }

        bool visited[100] = {false};
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // ------------------------------
    // SORT --- manual bubble sort on adjacency row
    // ------------------------------
    void sortGraph() {
        for (int r = 0; r < 100; r++) {
            if (!exists[r]) continue;

            // bubble sort row r
            for (int i = 0; i < 100; i++) {
                for (int j = i + 1; j < 100; j++) {
                    if (adj[r][i] < adj[r][j]) {
                        int temp = adj[r][i];
                        adj[r][i] = adj[r][j];
                        adj[r][j] = temp;
                    }
                }
            }
        }
        cout << "Graph sorted.\n";
    }

    // ------------------------------
    // PRINT GRAPH
    // ------------------------------
    void print() {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < 100; i++) {
            if (!exists[i]) continue;
            cout << i << ": ";
            for (int j = 0; j < 100; j++) {
                if (exists[j])
                    cout << adj[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
};

// ----------------------------------------------------------

int main() {
    Graph g;

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.print();

    g.BFS(1);
    g.DFS(1);

    g.deleteEdge(1, 3);
    g.print();

    cout << "Has vertex 3? " << g.hasVertex(3) << endl;
    cout << "Has edge 1-5? " << g.hasEdge(1, 5) << endl;

    return 0;
}