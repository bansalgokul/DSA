#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (x >= pow(2, (k - 1))) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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