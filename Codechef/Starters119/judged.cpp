#include <iostream>
using namespace std;

void solve() {
    int a, x = 0;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        x += a;
    }

    if (x >= 4) {
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