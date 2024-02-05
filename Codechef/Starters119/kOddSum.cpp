#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if ((n - k + 1) % 2 == 0) {
        for (int i = 1; i < n - k + 1; i += 2) {
            cout << i << " ";
        }
        for (int i = 2; i < n - k + 1; i += 2) {
            cout << i << " ";
        }
    } else {
        for (int i = 2; i < n - k + 1; i += 2) {
            cout << i << " ";
        }
        for (int i = 1; i < n - k + 1; i += 2) {
            cout << i << " ";
        }
    }

    for (int i = n - k + 1; i <= n; i++) {
        if (i == n) {
            cout << i << endl;
        } else {

            cout << i << " ";
        }
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