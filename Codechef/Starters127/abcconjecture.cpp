#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool isNumOfEachCharEqual(string a, string b) {
    int n = a.length();
    vector<int> A(3, 0);
    vector<int> B(3, 0);
    for (int i = 0; i < n; i++) {
        A[a[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
        B[b[i] - 'a']++;
    }

    for (int i = 0; i < 3; i++) {
        if (A[i] != B[i]) {
            return false;
        }
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "YES" << endl;
        return;
    }

    if (!isNumOfEachCharEqual(a, b)) {
        cout << "NO" << endl;
        return;
    }

    vector<vector<int>> indexes(3);

    for (int i = 0; i < n; i++) {
        indexes[a[i] - 'a'].push_back(i);
    }

    int a_index = 0, b_index = 0, c_index = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            a_index++;
            b_index++;
            c_index++;
            continue;
        } else if (a[i] == 'b' || b[i] == 'b') {
            cout << "NO" << endl;
            return;
        } else if (a[i] == 'a') {
            if (b_index == indexes[1].size()) {
                cout << "NO" << endl;
                return;
            } else {
                if (indexes[1][b_index] < indexes[2][c_index] && indexes[1][b_index] < indexes[0][a_index]) {
                    a_index++;
                    b_index++;
                    c_index++;
                } else {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}