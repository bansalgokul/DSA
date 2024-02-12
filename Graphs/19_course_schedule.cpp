#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> isCyclic(int V, vector<vector<int>> &adj) {
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
        return {};
    }

    return output;
}

vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) {

    vector<vector<int>> adj(N);
    for (int i = 0; i < P; i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];

        adj[u].push_back(v);
    }

    return isCyclic(N, adj);
}