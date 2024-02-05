#include <algorithm>
#include <iostream>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int longest = 1;
    char currChar = s[0];
    int currLen = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == currChar) {
            currLen++;
            longest = max(longest, currLen);
        } else {
            currChar = s[i];
            currLen = 1;
        }
    }
    cout << longest << " ";
    char c;
    for (int i = 0; i < q; i++) {
        cin >> c;
        if (c == currChar) {
            currLen++;
            longest = max(longest, currLen);
        } else {
            currChar = c;
            currLen = 1;
        }
        cout << longest << " ";
    }
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}