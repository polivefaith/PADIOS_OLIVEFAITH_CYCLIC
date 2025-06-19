#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for DFS cycle detection
bool dfsFindCycle(int node, const vector<vector<int>>& graph,
                  vector<bool>& visited,
                  vector<bool>& inRecStack,
                  vector<int>& currentPath,
                  vector<int>& cyclePath) {
    
    visited[node] = true;
    inRecStack[node] = true;
    currentPath.push_back(node);

    for (int neighbor = 0; neighbor < graph.size(); neighbor++) {
        if (graph[node][neighbor] == 1) {
            if (!visited[neighbor]) {
                if (dfsFindCycle(neighbor, graph, visited, inRecStack, currentPath, cyclePath))
                    return true;
            }
            else if (inRecStack[neighbor]) {
                // Cycle found: backtrack the path
                auto it = find(currentPath.begin(), currentPath.end(), neighbor);
                if (it != currentPath.end()) {
                    while (it != currentPath.end()) {
                        cyclePath.push_back(*it);
                        ++it;
                    }
                    cyclePath.push_back(neighbor); // Complete the cycle loop
                }
                return true;
            }
        }
    }

    inRecStack[node] = false;
    currentPath.pop_back();
    return false;
}

// Main function to check for cycles using DFS
bool detectCycleDFS(const vector<vector<int>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    vector<bool> inRecStack(numVertices, false);
    vector<int> currentPath;
    vector<int> cyclePath;

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (dfsFindCycle(i, graph, visited, inRecStack, currentPath, cyclePath)) {
                cout << "Cycle Detected using DFS!\n";
                cout << "Vertices involved in the cycle: ";
                for (int j = 0; j < cyclePath.size(); j++) {
                    cout << cyclePath[j];
                    if (j < cyclePath.size() - 1)
                        cout << " -> ";
                }
                cout << endl;
                return true;
            }
        }
    }

    cout << "No Cycle Detected using DFS.\n";
    return false;
}

int main() {
    int numVertices;
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }

    detectCycleDFS(graph, numVertices);

    return 0;
}
