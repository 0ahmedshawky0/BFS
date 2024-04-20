#include <iostream>
#include <queue>
using namespace std;

class Graph
{
    int V;
    int **adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new int *[V];
        for (int i = 0; i < V; ++i)
            adj[i] = new int[V];
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                adj[i][j] = 0;
    }

    void addEdge(int v, int w)
    {
        adj[v][w] = 1;
    }

    void BFS(int s)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            s = q.front();
            cout << s << " ";
            q.pop();

            for (int i = 0; i < V; ++i)
            {
                if (adj[s][i] && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal (starting from vertex 2): ";
    g.BFS(2);

    return 0;
}
