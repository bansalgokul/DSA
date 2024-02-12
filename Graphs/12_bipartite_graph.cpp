// bipartite graph - a graph that can be divided into two disjoint sets of vertices where there is no edge between vertices of same set.
// also means that if we can color a graph with 2 colors such that no adjacent nodes have same color, it is bipartite graph

// Graph without cycle will always be a bipartite graph
// Graph with all cycles of even length will be bipartite graphs
// Graph with a cycle of odd length can not be bipartite graph.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool helper(int V, vector<int> adj[], vector<int> &colors) {
    queue<pair<int, int>> q;

    colors[0] = 1;
    q.push({0, 1});

    while (q.empty()) {
        int u = q.front().first;
        int c = q.front().second;

        for (int v : adj[u]) {
            if (colors[v] == c) {
                return false;
            } else if (colors[v] == -1) {
                colors[v] = c == 1 ? 2 : 1;
                q.push({v, colors[v]});
            }
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[]) {
    vector<int> colors(V, -1);

    for (int i = 0; i < V; i++) {
        if (colors[i] == -1) {
            bool small = helper(V, adj, colors);
            if (!small) {
                return false;
            }
        }
    }

    return true;
}