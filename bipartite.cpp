#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS function to check bipartite
bool isBipartite(vector<vector<int>> &graph, int n) {

    vector<int> col(n, -1);

    for (int i = 0; i < n; i++) {

        if (col[i] == -1) {

            queue<int> q;
            q.push(i);
            col[i] = 0;

            while (!q.empty()) {

                int curr = q.front();
                q.pop();

                // Traverse adjacency list
                for (int neigh : graph[curr]) {

                    if (col[neigh] == -1) {

                        col[neigh] = 1 - col[curr];
                        q.push(neigh);
                    }

                    else if (col[neigh] == col[curr]) {

                        return false;
                    }
                }
            }
        }
    }

    return true;
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
        graph[v].push_back(u);
    }

    // Printing adjacency list
    cout << "\nAdjacency List:\n";

    for (int i = 0; i < n; i++) {

        cout << i << " : ";

        for (int neigh : graph[i]) {
            cout << neigh << " ";
        }

        cout << endl;
    }

    if (isBipartite(graph, n))
        cout << "\nYes Bipartite\n";
    else
        cout << "\nNot Bipartite\n";

    return 0;
}