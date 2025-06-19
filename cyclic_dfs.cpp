// cyclic_dfs.cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool dfsCycle(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, vector<int>& path) {
    visited[v] = true;
    recStack[v] = true;
    path.push_back(v);

    for (int i = 0; i < adj.size(); ++i) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfsCycle(i, adj, visited, recStack, path))
                    return true;
            } else if (recStack[i]) {
                path.push_back(i); // cycle end node
                return true;
            }
        }
    }

    recStack[v] = false;
    path.pop_back();
    return false;
}

bool isCyclicDFS(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false), recStack(V, false);
    vector<int> path;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfsCycle(i, adj, visited, recStack, path)) {
                cout << "Cycle Detected using DFS! Vertices in the cycle: ";
                for (int v : path) cout << v << " ";
                cout << endl;
                return true;
            }
        }
    }
    cout << "No Cycle Detected using DFS.\n";
    return false;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V, vector<int>(V));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> adj[i][j];

    isCyclicDFS(adj, V);
    return 0;
}
