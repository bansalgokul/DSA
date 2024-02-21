#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> helper(int V, vector<vector<int>> &adj) {
    vector<int> output(V, 0);
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
        output[curr] = 1;

        for (auto node : adj[curr]) {
            indegree[node]--;
            if (indegree[node] == 0) {
                q.push(node);
            }
        }
    }

    return output;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<vector<int>> reversed(V);
    for (int i = 0; i < V; i++) {
        for (int j : adj[i]) {
            reversed[j].push_back(i);
        }
    }
    vector<int> arr = helper(V, reversed);
    vector<int> output;
    for (int i = 0; i < V; i++) {
        if (arr[i]) {
            output.push_back(i);
        }
    }
    return output;
}