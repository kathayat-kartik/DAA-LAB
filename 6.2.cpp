#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> &graph,
         vector<bool> &visited, vector<bool> &recStack) {

    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // Cycle found
        }
    }

    recStack[node] = false;
    return false;
}

int main() {

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n);

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";

    // Creating adjacency list
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);

        // Uncomment for undirected graph
        // graph[v].push_back(u);
    }

    // Printing adjacency list
    cout << "\nAdjacency List:\n";

    for (int i = 0; i < n; i++) {
        cout << i << " : ";

        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }

        cout << endl;
    }

    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    bool hasCycle = false;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            if (dfs(i, graph, visited, recStack)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "\nYes Cycle Exists\n";
    else
        cout << "\nNo Cycle Exists\n";

    return 0;
}