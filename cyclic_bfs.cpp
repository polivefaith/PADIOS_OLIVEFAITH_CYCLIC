#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclicBFS(vector<vector<int>>& adj, int V) {
    vector<int> indegree(V, 0);

    // Step 1: Calculate indegree of each node
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            if (adj[i][j] == 1)
                indegree[j]++;

    // Make a copy of original indegree
    vector<int> originalIndegree = indegree;

    queue<int> q;
    for (int i = 0; i < V; ++i)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;

    // Step 2: BFS using Kahn's algorithm
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int i = 0; i < V; ++i) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
    }

    // Step 3: If not all nodes are processed, cycle exists
    if (count != V) {
        cout << "Cycle Detected using BFS!\n";
        cout << "Vertices involved in the cycle: ";
        for (int i = 0; i < V; ++i) {
            // If a node still has non-zero indegree after BFS, it's part of the cycle
            if (indegree[i] > 0)
                cout << i << " ";
        }
        cout << endl;
        return true;
    } else {
        cout << "No Cycle Detected using BFS.\n";
        return false;
    }
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

    isCyclicBFS(adj, V);
    return 0;
}
