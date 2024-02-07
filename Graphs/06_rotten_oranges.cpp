
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int xy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int orangesRotting(vector<vector<int>> &grid) {

    vector<vector<int>> oranges = grid;
    int n = grid.size();
    int m = grid[0].size();
    int t = 0;
    int fresh = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (oranges[i][j] == 2) {
                q.push({i, j});
            } else if (oranges[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) {
        return t;
    }

    while (!q.empty()) {

        int s = q.size();

        for (int i = 0; i < s; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nr = r + xy[j][0];
                int nc = c + xy[j][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && oranges[nr][nc] == 1) {
                    oranges[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                }
            }
        }

        t++;
    }

    if (fresh == 0) {
        return t - 1;
    }

    return -1;
}

int main() {

    return 0;
}