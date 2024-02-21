#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src) {
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N, -1);
    queue<pair<int, int>> q;

    q.push({src, 0});
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front().first;
        int wt = q.front().second;
        q.pop();

        for (int v : adj[node]) {
            if (dist[v] == -1) {
                dist[v] = wt + 1;
                q.push({v, wt + 1});
            }
        }
    }

    return dist;
}