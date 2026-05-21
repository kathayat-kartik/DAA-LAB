#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int wt;

    Edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        wt = w;
    }
};

class Pair
{
public:
    int v;
    int cost;

    Pair(int v, int c)
    {
        this->v = v;
        cost = c;
    }

    bool operator>(const Pair &p2) const
    {
        return cost > p2.cost;
    }
};

// Prim's Algorithm
void prims(vector<Edge> graph[], int V)
{
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    vector<bool> vis(V, false);

    pq.push(Pair(0, 0));

    int finalCost = 0;

    while (!pq.empty())
    {
        Pair curr = pq.top();
        pq.pop();

        if (!vis[curr.v])
        {
            vis[curr.v] = true;

            finalCost += curr.cost;

            for (int i = 0; i < graph[curr.v].size(); i++)
            {
                Edge e = graph[curr.v][i];

                if (!vis[e.dest])
                {
                    pq.push(Pair(e.dest, e.wt));
                }
            }
        }
    }

    cout << "Minimum Cost = " << finalCost;
}

int main()
{
    int V, E;

    cin >> V >> E;

    vector<Edge> graph[V];

    // Input edges
    for (int i = 0; i < E; i++)
    {
        int src, dest, wt;

        cin >> src >> dest >> wt;

        graph[src].push_back(Edge(src, dest, wt));
        graph[dest].push_back(Edge(dest, src, wt));
    }

    prims(graph, V);

    return 0;
}