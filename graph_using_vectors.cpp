#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // -------------------- BFS --------------------
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

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

    // -------------------- DFS (Recursive) --------------------
    void DFS_recursive_util(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFS_recursive_util(neighbor, visited);  // running stack DFS
            }
        }
    }

    void DFS_recursive(int start) {
        vector<bool> visited(V, false);
        cout << "DFS (Recursive): ";
        DFS_recursive_util(start, visited);
        cout << endl;
    }

    // -------------------- DFS (Iterative using explicit stack) --------------------
    void DFS_iterative(int start) {
        vector<bool> visited(V, false);
        stack<int> st;

        st.push(start);
        cout << "DFS (Iterative Stack): ";

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                cout << node << " ";
                visited[node] = true;
            }

            // Push neighbors in reverse so order matches recursive DFS
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);  // suspension stack DFS
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.BFS(0);
    g.DFS_recursive(0);
    g.DFS_iterative(0);

    return 0;
}
