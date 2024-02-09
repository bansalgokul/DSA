
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool helper(int V, vector<int> adj[], vector<bool> &vis, int start) {
    queue<pair<int, int>> q; // destination node, previous node

    q.push({start, -1});
    vis[start] = true;

    while (!q.empty()) {
        int u = q.front().first;
        int prev = q.front().second;
        // cout << u << " " << prev << " u , prev" << endl;
        q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != prev && vis[v]) {
                // cout << u << " " << v << endl;
                return true;
            } else if (!vis[v]) {
                q.push({v, u});
                vis[v] = true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {

    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            bool small = helper(V, adj, vis, i);
            if (small) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    return 0;
}