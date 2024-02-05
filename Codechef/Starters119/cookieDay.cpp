#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cookies(n, 0);

    bool cookiesDistributed = false;
    int output = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> cookies[i];
        if (cookies[i] >= k) {
            cookiesDistributed = true;
            output = min(output, cookies[i] % k);
        }
    }

    if (cookiesDistributed) {
        cout << output << endl;
    } else {
        cout << -1 << endl;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}