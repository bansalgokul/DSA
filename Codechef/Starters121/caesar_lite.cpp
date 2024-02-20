#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string p, c;
    cin >> p >> c;

    for (int i = 0; i < n; i++) {
        int a = int(p[i]) - int('A');
        int b = int(c[i]) - int('A');
        cout << "a : " << a << " b: " << b << endl;
        int x = 0;

        while (true) {
            if ((a + 3 * x) % 26 == b) {
                cout << x << " ";
                break;
            }
            x++;
        }
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