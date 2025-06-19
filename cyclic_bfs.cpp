#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to detect a cycle in a directed graph using Kahn's Algorithm (BFS)
bool detectCycleBFS(vector<vector<int>>& graph, int numVertices) {
    vector<int> indegree(numVertices, 0);  // To store incoming edges count

    // Step 1: Calculate indegree of every vertex
    for (int from = 0; from < numVertices; from++) {
        for (int to = 0; to < numVertices; to++) {
            if (graph[from][to] == 1) {
                indegree[to]++;
            }
        }
    }

    queue<int> q;  // Queue for BFS

    // Step 2: Push vertices with 0 indegree into the queue
    for (int i = 0; i < numVertices; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<bool> processed(numVertices, false); // Track processed vertices
    int processedCount = 0;

    // Step 3: Process vertices using Kahn's Algorithm
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        processed[current] = true;
        processedCount++;

        for (int neighbor = 0; neighbor < numVertices; neighbor++) {
            if (graph[current][neighbor] == 1) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    }

    // Step 4: Check if there was a cycle
    if (processedCount != numVertices) {
        cout << "Cycle Detected using BFS!\n";

        // Step 5: Find vertices that are part of the cycle
        vector<int> cycleVertices;
        for (int i = 0; i < numVertices; i++) {
            if (!processed[i]) {
                cycleVertices.push_back(i);
            }
        }

        // Step 6: Try to trace one path in the cycle
        vector<bool> visited(numVertices, false);
        vector<int> cyclePath;
        int start = cycleVertices[0];
        int current = start;

        while (!visited[current]) {
            visited[current] = true;
            cyclePath.push_back(current);

            // Find the next vertex in the cycle path
            bool foundNext = false;
            for (int next = 0; next < numVertices; next++) {
                if (graph[current][next] == 1 && !processed[next]) {
                    current = next;
                    foundNext = true;
                    break;
                }
            }

            if (!foundNext) break;  // Break if no next vertex in the cycle
        }

        // Complete the cycle by showing it loops back
        cyclePath.push_back(start);

        // Step 7: Print the cycle path
        cout << "Vertices involved in the cycle: ";
        for (int i = 0; i < cyclePath.size(); i++) {
            cout << cyclePath[i];
            if (i < cyclePath.size() - 1) cout << " -> ";
        }
        cout << endl;

        return true;
    } else {
        cout << "No Cycle Detected using BFS.\n";
        return false;
    }
}

int main() {
    int numVertices;
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    // Create adjacency matrix
    vector<vector<int>> graph(numVertices, vector<int>(numVertices));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }

    // Detect cycle in the graph
    detectCycleBFS(graph, numVertices);

    return 0;
}
