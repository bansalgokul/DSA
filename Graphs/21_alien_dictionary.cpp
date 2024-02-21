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

string findOrder(string dict[], int N, int K) {
    vector<vector<int>> adj(K);

    for (int i = 0; i < N - 1; i++) {
        string a = dict[i];
        string b = dict[i + 1];

        int len1 = a.length();
        int len2 = b.length();

        int x = min(len1, len2);

        for (int j = 0; j < x; j++) {
            if (a[j] == b[j]) {
                continue;
            } else {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }
    // for (int i = 0; i < K; i++) {
    //     cout << char('a' + i) << " : ";
    //     for (int j : adj[i]) {
    //         cout << char('a' + j) << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> small = isCyclic(K, adj);
    string output = "";
    for (int i = 0; i < small.size(); i++) {
        output.push_back(char('a' + small[i]));
    }
    return output;
}