
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool helper(int V, vector<int> adj[], vector<int> vis, vector<int> &pathVis, int node) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (int i = 0; i < adj[node].size(); i++) {
        if (pathVis[i]) {
            return true;
        } else if (!vis[i]) {
            bool small = helper(V, adj, vis, pathVis, node);
            if (small) {
                return true;
            }
        }
    }

    pathVis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            bool small = helper(V, adj, vis, pathVis, i);
            if (small) {
                return true;
            }
        }
    }
    return false;
}