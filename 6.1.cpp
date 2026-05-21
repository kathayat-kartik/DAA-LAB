#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> &graph, int src, int dest, vector<bool> &visited) {
    if (src == dest)
        return true;

    visited[src] = true;

    for (int neighbor : graph[src]) {
        if (!visited[neighbor]) {
            if (dfs(graph, neighbor, dest, visited))
                return true;
        }
    }

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

    int src, dest;

    cout << "\nEnter source vertex: ";
    cin >> src;

    cout << "Enter destination vertex: ";
    cin >> dest;

    vector<bool> visited(n, false);

    if (dfs(graph, src, dest, visited))
        cout << "Yes Path Exists\n";
    else
        cout << "No Such Path Exists\n";

    return 0;
}