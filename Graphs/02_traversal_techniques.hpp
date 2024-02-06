#include "graph_representation.hpp"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(int V, vector<vector<int>> adjL) {
    vector<int> vis(V, 0);
    vector<int> bfs;

    queue<int> q;
    vis[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        bfs.push_back(u);

        for (int i = 0; i < adjL[u].size(); i++) {
            if (!vis[adjL[u][i]]) {
                vis[adjL[u][i]] = 1;
                q.push(adjL[u][i]);
            }
        }
    }
    return bfs;
}

void dfsHelper(vector<vector<int>> adjL, vector<int> &vis, vector<int> &output, int currNode) {
    output.push_back(currNode);
    vis[currNode] = 1;

    for (auto node : adjL[currNode]) {
        if (!vis[node]) {
            dfsHelper(adjL, vis, output, node);
        }
    }
    return;
}

vector<int> dfs(int V, vector<vector<int>> adjL) {
    vector<int> vis(V, 0);
    vector<int> output;

    dfsHelper(adjL, vis, output, 0);
    return output;
}

// int main() {

//     return 0;
// }