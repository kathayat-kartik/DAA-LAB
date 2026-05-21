#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Edge class
class Edge {
public:
    int src, dest, wt;

    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        wt = w;
    }
};

// Pair class
class Pair {
public:
    int node;
    int path;

    Pair(int n, int p) {
        node = n;
        path = p;
    }
};

// Comparator for min-heap
struct cmp {
    bool operator()(Pair a, Pair b) {
        return a.path > b.path;
    }
};

// Print Path
void printPath(vector<int> &parent, int j) {
    if (j == -1) return;
    printPath(parent, parent[j]);
    cout << j << " ";
}

// Dijkstra Algorithm
void dijkstra(vector<vector<Edge>> &graph, int src) {
    int V = graph.size();

    vector<int> dist(V, INT_MAX);
    vector<bool> vis(V, false);
    vector<int> parent(V, -1);

    priority_queue<Pair, vector<Pair>, cmp> pq;

    dist[src] = 0;
    pq.push(Pair(src, 0));

    while (!pq.empty()) {
        Pair curr = pq.top();
        pq.pop();

        if (!vis[curr.node]) {
            vis[curr.node] = true;

            for (int i = 0; i < graph[curr.node].size(); i++) {
                Edge e = graph[curr.node][i];

                int u = e.src;
                int v = e.dest;
                int wt = e.wt;

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                    pq.push(Pair(v, dist[v]));
                }
            }
        }
    }

    // Output
    cout << "\nShortest Distance and Paths:\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << " : ";
        if (dist[i] == INT_MAX) {
            cout << "No Path\n";
        } else {
            cout << "Distance = " << dist[i] << " Path = ";
            printPath(parent, i);
            cout << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V);

    // Input edges using loop
    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge(u, v, w));

        // If undirected graph, uncomment below:
        // graph[v].push_back(Edge(v, u, w));
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, src);

    return 0;
}