#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void helper(int V, vector<int> adj[], vector<int> &vis, stack<int> &output, int node) {

    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            helper(V, adj, vis, output, it);
        }
    }

    output.push(node);
    return;
}

vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int> output;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            helper(V, adj, vis, output, i);
        }
    }

    vector<int> arr;
    while (!output.empty()) {
        arr.push_back(output.top());
        output.pop();
    }
    return arr;
}