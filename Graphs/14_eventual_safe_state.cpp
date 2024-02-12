#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool helper(int V, vector<int> adj[], vector<int> vis, vector<int> &pathVis, vector<int> &cycleNodes, int node) {
    vis[node] = 1;
    pathVis[node] = 1;
    cycleNodes[node] = 1;

    for (auto v : adj[node]) {
        if (!vis[v]) {
            if (helper(V, adj, vis, pathVis, cycleNodes, v)) {
                return true;
            }
        } else if (pathVis[v]) {

            return true;
        }
    }

    cycleNodes[node] = 0;
    pathVis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> cycleNodes(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            helper(V, adj, vis, pathVis, cycleNodes, i);
        }
    }

    vector<int> output;
    for (int i = 0; i < V; i++) {
        if (!cycleNodes[i]) {
            output.push_back(i);
        }
    }
    return output;
}