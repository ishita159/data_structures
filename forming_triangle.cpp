
#include <bits/stdc++.h>
using namespace std;


int minEdges(vector<pair<int, int> > v, int n)
{

    vector<vector<int> > adj;
    adj.resize(n + 1);
    for (int i = 0; i < adj.size(); i++)
        adj[i].resize(n + 1, 0);

    for (int i = 0; i < v.size(); i++)
    {
        adj[v[i].first][v[i].second] = 1;
        adj[v[i].second][v[i].first] = 1;
    }

    int edgesNeeded = 3;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {

                // If the vertices form a triangle
                if (adj[i][j] && adj[j][k] && adj[k][i])
                    return 0;

                // If no edges are present
                if (!(adj[i][j] || adj[j][k] || adj[k][i]))
                    edgesNeeded = min(edgesNeeded, 3);

                else
                {

                    // If only 1 edge is required
                    if ((adj[i][j] && adj[j][k]) || (adj[j][k] && adj[k][i]) || (adj[k][i] && adj[i][j]))
                    {
                        edgesNeeded = 1;
                    }

                    // Two edges are required
                    else
                        edgesNeeded = min(edgesNeeded, 2);
                }
            }
        }
    }
    return edgesNeeded;
}

int main()
{

    int n = 3;

    vector<pair<int, int> > v = {{1, 2}, {1, 3}};

    cout << minEdges(v, n);

    return 0;
}
