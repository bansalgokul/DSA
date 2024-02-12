#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isCyclic(int V, vector<vector<int>> &adj) {
    vector<int> output;
    queue<int> q;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (auto j : adj[i]) {
            indegree[j]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        output.push_back(curr);

        for (auto node : adj[curr]) {
            indegree[node]--;
            if (indegree[node] == 0) {
                q.push(node);
            }
        }
    }

    if (output.size() < V) {
        return true;
    }

    return false;
}

bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> adj(N);
    for (int i = 0; i < P; i++) {
        int u = prerequisites[i].second;
        int v = prerequisites[i].first;

        adj[u].push_back(v);
    }

    return isCyclic(N, adj);
}