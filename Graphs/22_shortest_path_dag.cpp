#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfsTopoSort(vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &sorted, int node) {
    vis[node] = 1;

    for (auto v : adj[node]) {
        int next = v.first;
        if (!vis[next]) {
            dfsTopoSort(adj, vis, sorted, next);
        }
    }

    sorted.push(node);
    return;
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> adj(N);

    for (int i = 0; i < M; i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    vector<int> vis(N, 0);
    stack<int> sorted;
    dfsTopoSort(adj, vis, sorted, 0);

    vector<int> output(N, -1);
    output[0] = 0;

    while (!sorted.empty()) {
        int node = sorted.top();
        sorted.pop();
        if (output[node] == -1) {
            continue;
        }
        int distance = output[node];

        for (auto v : adj[node]) {
            int next = v.first;
            int weight = v.second;

            if (output[next] == -1 || output[next] > distance + weight) {
                output[next] = distance + weight;
            }
        }
    }

    return output;
}

// For any source
vector<int> shortestPathWithSource(int N, int M, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int, int>>> adj(N);

    for (int i = 0; i < M; i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    vector<int> vis(N, 0);
    stack<int> sorted;
    dfsTopoSort(adj, vis, sorted, 0);

    vector<int> output(N, -1);
    output[src] = 0;

    while (!sorted.empty()) {
        int node = sorted.top();
        sorted.pop();
        if (output[node] == -1) {
            continue;
        }
        int distance = output[node];

        for (auto v : adj[node]) {
            int next = v.first;
            int weight = v.second;

            if (output[next] == -1 || output[next] > distance + weight) {
                output[next] = distance + weight;
            }
        }
    }

    return output;
}