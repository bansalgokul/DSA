#include "02_traversal_techniques.hpp"
#include "graph_representation.hpp"
#include <iostream>
#include <vector>
using namespace std;

int noOfProvinces(vector<vector<int>> adj, int V) {
    vector<int> vis(V, 0);
    int output = 0;
    vector<int> lis;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            output++;
            dfsHelper(adj, vis, lis, i);
        }
    }

    return output;
}

int main() {

    return 0;
}