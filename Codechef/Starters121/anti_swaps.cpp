#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n > 3 || n == 1) {
        cout << "YES" << endl;
        return;
    }

    if (n == 2) {
        if (arr[0] <= arr[1]) {
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    if ((arr[1] >= arr[0] && arr[1] <= arr[2]) || (arr[1] <= arr[0] && arr[1] >= arr[2])) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}