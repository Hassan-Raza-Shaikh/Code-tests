#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> matrix;
    vector<list<int>> adj;

public:
    Graph(int vertix = 0)
    {
        V = vertix;
        matrix = vector<vector<int>>(V, vector<int>(V, 0));
        adj = vector<list<int>>(V);
    }

    void addEdge(int v, int u)
    {
        if (v >= V || u >= V)
        {
            cout << "Invalid /n";
            return;
        }
        matrix[v][u] = 1;
        matrix[u][v] = 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void removee(int v, int u)
    {
        if (v >= V || u >= V)
        {
            cout << "Invalid /n";
            return;
        }

        matrix[v][u] = 0;
        matrix[u][v] = 0;
        adj[u].remove(v);
        adj[v].remove(u);
    }

    void addVertex()
    {
        V++;
        for (auto &row : matrix)
        {
            row.push_back(0);
        }
        matrix.push_back(vector<int>(V, 0));

        adj.push_back(list<int>());
    }

    void deleteV(int v)
    {
        matrix.erase(matrix.begin() + v);
        for (auto &row : matrix)
        {
            row.erase(row.begin() + v);
        }

        vector<list<int>> newadj(V - 1);

        for (int i = 0, j = 0; i < V; i++)
        {
            if (i == v)
                continue;
            for (int x : adj[i])
            {
                if (x != v)
                {
                    newadj[j].push_back(x > v ? x - 1 : x);
                }
            }
            j++;
        }
        adj = newadj;

        V--;
    }
    void display()
    {

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displaya()
    {

        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (auto x : adj[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start)
    {
        queue<int> q;
        vector<bool> visited(V, false);
        visited[start] = true;
        q.push(start);
        for(;!q.empty();)
        {
            int n = q.front();
            cout<<n<<" ";
            q.pop();
            for(int x : adj[n])
            {
                if(!visited[x])
                {
                    visited[x]= true;
                    q.push(x);
                }
            }
        }
    }

    void DFS_sus(int start)
    {
        stack<int> s;
        vector<bool> visited(V, false);
        s.push(start);
        visited[start] = true;
        for(;!s.empty();)
        {
            int n = s.top();
            cout<<n<<" ";
            s.pop();
            for(int x : adj[n])
            {
                if(!visited[x])
                {
                    visited[x]= true;
                    s.push(x);
                }
            }
        }
    }

    void DFS_run_util(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                DFS_run_util(neighbor, visited);
            }
        }
    }

    void DFS_run(int start)
    {
        vector<bool> visited(V,false);
        DFS_run_util(start,visited);
        cout<<" ";
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 4);
    g.removee(0, 1);
    // g.deleteV(2);
    g.display();
    g.displaya();
    g.BFS(0);
    g.DFS_sus(0);
}