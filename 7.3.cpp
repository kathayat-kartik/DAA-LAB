#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:

    // Edge class
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

    // Info class
    class Info
    {
    public:
        int v;
        int cost;
        int edges;

        Info(int v, int c, int e)
        {
            this->v = v;
            cost = c;
            edges = e;
        }
    };

    // Create Graph
    static void createGraph(vector<vector<int>> &flights,
                            vector<Edge> graph[],
                            int E)
    {
        for (int i = 0; i < E; i++)
        {
            int src = flights[i][0];
            int dest = flights[i][1];
            int wt = flights[i][2];

            Edge e(src, dest, wt);

            graph[src].push_back(e);
        }
    }

    // Shortest path with exactly K edges
    static int shortestPathK(int V,
                             vector<vector<int>> &flights,
                             int src,
                             int dest,
                             int k)
    {
        vector<Edge> graph[V];

        createGraph(flights, graph, flights.size());

        queue<Info> q;

        q.push(Info(src, 0, 0));

        int ans = INT_MAX;

        while (!q.empty())
        {
            Info curr = q.front();
            q.pop();

            // If edges exceed k
            if (curr.edges > k)
            {
                continue;
            }

            // Destination reached with exactly k edges
            if (curr.v == dest && curr.edges == k)
            {
                ans = min(ans, curr.cost);
            }

            // Traverse neighbors
            for (int i = 0; i < graph[curr.v].size(); i++)
            {
                Edge e = graph[curr.v][i];

                q.push(Info(e.dest,
                            curr.cost + e.wt,
                            curr.edges + 1));
            }
        }

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};

int main()
{
    int V;
    cin >> V;

    int E;
    cin >> E;

    vector<vector<int>> flights(E, vector<int>(3));

    // Input edges
    for (int i = 0; i < E; i++)
    {
        cin >> flights[i][0]
            >> flights[i][1]
            >> flights[i][2];
    }

    int src, dest;
    cin >> src >> dest;

    int k;
    cin >> k;

    int result = Solution::shortestPathK(V,
                                         flights,
                                         src,
                                         dest,
                                         k);

    if (result == -1)
    {
        cout << "no path of length k is available";
    }
    else
    {
        cout << result;
    }

    return 0;
}