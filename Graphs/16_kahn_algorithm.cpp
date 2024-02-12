#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
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

    return output;
}
