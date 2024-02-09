#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int xy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void helper(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &copy, int r, int c) {
    // cout << r << " " << c << endl;
    copy[r][c] = 0;

    for (int i = 0; i < 4; i++) {
        int nr = r + xy[i][0];
        int nc = c + xy[i][1];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && copy[nr][nc] == 1) {
            helper(n, m, grid, copy, nr, nc);
        }
    }
    return;
}
int numberOfEnclaves(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> copy = grid;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1 && copy[i][j] == 1) {
                helper(n, m, grid, copy, i, j);
            }
        }
    }

    int output = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (copy[i][j] == 1) {
                output++;
            }
        }
    }
    return output;
}

int main() {

    return 0;
}