
#include <bits/stdc++.h>
using namespace std;
#define INFINITE 10000

void shortestPathLength(int n, int graph[4][4], int dis[4][4])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

void checkShortestPath(int length, int path[], int dis[4][4])
{
    if (dis[path[0] - 1][path[length - 1] - 1] == length - 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

// Driver code
int main()
{
  
    const int n = 4;
    int graph[n][n] = {{0, 1, 1, INFINITE},
                       {INFINITE, 0, 1, INFINITE},
                       {INFINITE, INFINITE, 0, 1},
                       {1, INFINITE, INFINITE, 0}};
    //store the length of shortest
    int dis[n][n];

    // path between all pairs of vertices
    shortestPathLength(n, graph, dis);

    int path1[] = {1, 2, 3, 4};
    checkShortestPath(n, path1, dis);

    int path2[] = {1, 3, 4};
    checkShortestPath(3, path2, dis);

    return 0;
}
