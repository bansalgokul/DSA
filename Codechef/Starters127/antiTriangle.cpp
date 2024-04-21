#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;

    int i = 0;
    int num = 0;
    while (i < n && num <= l / 2) {
        num++;
        cout << num << " ";
        i++;
    }

    while (i < n) {
        num += l;
        cout << num << " ";
        i++;
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