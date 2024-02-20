#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int xy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(vector<vector<int>> &grid, int r, int c, int n, vector<vector<bool>> &visited) {
    if (r < 0 || r >= n || c < 0 || c >= n || visited[r][c] || grid[r][c] == -1) {
        return;
    }

    if (r == n - 1 && c == n - 1) {
        cout << "YES" << endl;
        exit(0);
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + xy[i][0];
        int nc = c + xy[i][1];
        dfs(grid, nr, nc, n, visited);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        grid[x - 1][y - 1] = -1;
    }

    dfs(grid, 0, 0, n, visited);

    cout << "NO" << endl;
}

// void solve() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> grid(n, vector<int>(n, 0));
//     int x, y;
//     for (int i = 0; i < m; i++) {
//         cin >> x >> y;
//         grid[x - 1][y - 1] = -1;
//     }

//     queue<pair<int, int>> q;
//     q.push({0, 0});
//     grid[0][0] = 1;

//     while (!q.empty()) {
//         int r = q.front().first;
//         int c = q.front().second;

//         cout << r << " " << c << endl;
//         if (r == n - 1 && c == n - 1) {
//             cout << "YES" << endl;
//             return;
//         }
//         q.pop();

//         for (int i = 0; i < 4; i++) {
//             int nr = r + xy[i][0];
//             int nc = c + xy[i][1];

//             if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
//                 q.push({nr, nc});
//                 grid[nr][nc] = 2;
//             }
//         }
//     }

//     cout << "NO" << endl;
//     return;
// }

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}