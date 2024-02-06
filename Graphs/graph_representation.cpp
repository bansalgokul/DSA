#include <iostream>
#include <vector>
using namespace std;

// Two ways to represent a graph:
// 1. Adjacency matrix
// 2. Adjacency list
// Storing Space - Adjacency matrix: O(V^2), Adjacency list: O(V + E)
// Adding a vertex - Adjacency matrix: O(V^2), Adjacency list: O(1)
// Adding an edge - Adjacency matrix: O(1), Adjacency list: O(1)
// Removing a vertex - Adjacency matrix: O(V^2), Adjacency list: O(V + E)
// Removing an edge - Adjacency matrix: O(1), Adjacency list: O(E)
// Querying - Adjacency matrix: O(1), Adjacency list: O(V)

// Adjacency matrix
// For weighted graphs ,store weight in matrix instead on one
void adjMatrix() {
    int n, m;
    cin >> n >> m;

    int adjm[n][n];
    int u, v;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adjm[u][v] = 1;

        // if directed graph, remove the below line
        adjm[v][u] = 1;
    }
}

// Adjacency List
// For weighted graphs ,store as pair of (v, weight) in list
void adjList() {
    int n, m;
    cin >> n >> m;

    vector<int> adjL[n];
    // vector<pair<int, int>> adjL[n];
    int u, v;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;

        // adjL[u].push_back({v, w});
        adjL[u].push_back(v);

        // if directed graph, remove the below line
        adjL[v].push_back(u);
    }
}

int main() {
    adjMatrix();
    return 0;
}