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

vector<vector<int>> sequences(vector<vector<int>> &adj, int src, int dest) {
    int n = adj.size();
    vector<int> prevVis(n, 0);
    vector<int> currVis(n, 0);
    vector<vector<int>> output;

    queue<vector<int>> q;
    q.push({src});
    currVis[src] = 1;

    bool isLastCycle = false;
    while (!q.empty()) {

        int qsize = q.size();
        prevVis = currVis;

        for (int i = 0; i < qsize; i++) {

            vector<int> arr = q.front();
            int u = arr.back();
            int wt = arr.size();
            q.pop();

            if (u == dest) {
                output.push_back(arr);
                isLastCycle = true;
            }

            for (int node : adj[u]) {
                if (!prevVis[node]) {
                    currVis[node] = 1;
                    vector<int> temp = arr;
                    temp.push_back(node);
                    q.push(temp);
                }
            }
        }

        if (isLastCycle) {
            break;
        }
    }

    return output;
}

vector<vector<string>> findSequences(string startWord, string targetWord, vector<string> &wordList) {
    if (!isTargetinList(targetWord, wordList)) {
        return {};
    }

    unordered_map<string, int> wordMap;
    unordered_map<int, string> idMap;
    vector<string> wordListCopy = wordList;
    int id = 0;
    for (string word : wordList) {
        idMap[id] = word;
        wordMap[word] = id++;
    }
    if (wordMap.count(startWord) == 0) {
        idMap[id] = startWord;
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
    vector<vector<int>> output = sequences(adj, src, dest);

    vector<vector<string>> final;
    for (int i = 0; i < output.size(); i++) {
        final.push_back({});
        for (int j = 0; j < output[i].size(); j++) {
            final[i].push_back(idMap[output[i][j]]);
        }
    }

    return final;
}
