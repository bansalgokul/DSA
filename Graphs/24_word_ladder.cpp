#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

bool isTargetinList(string targetWord, vector<string> &wordList) {
    for (string word : wordList) {
        if (word == targetWord) {
            return true;
        }
    }

    return false;
}

bool isOneDiff(string a, string b) {
    int diff = 0;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            diff++;
        }
    }

    return diff == 1 ? true : false;
}

int leastCount(vector<vector<int>> &adj, int src, int dest) {
    int n = adj.size();
    vector<int> vis(n, 0);

    queue<pair<int, int>> q;
    q.push({src, 1});
    vis[src] = 1;

    while (!q.empty()) {
        int u = q.front().first;
        int wt = q.front().second;
        q.pop();

        if (u == dest) {
            return wt;
        }

        for (int node : adj[u]) {
            if (!vis[node]) {
                if (node == dest) {
                    return wt + 1;
                }
                vis[node] = 1;
                q.push({node, wt + 1});
            }
        }
    }

    return 0;
}

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList) {
    if (!isTargetinList(targetWord, wordList)) {
        return 0;
    }

    unordered_map<string, int> wordMap;
    vector<string> wordListCopy = wordList;
    int id = 0;
    for (string word : wordList) {
        wordMap[word] = id++;
    }
    if (wordMap.count(startWord) == 0) {
        wordMap[startWord] = id++;
        wordListCopy.insert(wordListCopy.begin(), startWord);
    }

    vector<vector<int>> adj(id);
    int n = wordListCopy.size();

    for (int i = 0; i < n; i++) {
        string a = wordListCopy[i];
        for (int j = 0; j < i; j++) {
            string b = wordListCopy[j];

            if (isOneDiff(a, b)) {
                int anum = wordMap[a];
                int bnum = wordMap[b];

                adj[anum].push_back(bnum);
                adj[bnum].push_back(anum);
            }
        }
    }

    // for (int i = 0; i < id; i++) {
    //     cout << i << " : ";
    //     for (int v : adj[i]) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    int src = wordMap[startWord];
    int dest = wordMap[targetWord];
    vector<int> vis(id, 0);
    return leastCount(adj, src, dest);
}