
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int xy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> nearest(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> output(n, vector<int>(m, INT_MAX));
    int currDistance = 0;
    queue<pair<int, int>> q; // row, col

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({i, j});
                output[i][j] = currDistance;
            }
        }
    }

    currDistance++;
    while (!q.empty()) {
        int s = q.size();

        for (int i = 0; i < s; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + xy[i][0];
                int nc = c + xy[i][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && output[nr][nc] == INT_MAX) {
                    q.push({nr, nc});
                    output[nr][nc] = currDistance;
                }
            }
        }

        currDistance++;
    }

    return output;
}

int main() {

    return 0;
}