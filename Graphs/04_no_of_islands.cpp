
#include <iostream>
#include <vector>
using namespace std;

int x[3] = {-1, 0, 1};
int y[3] = {-1, 0, 1};

void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis, int n, int m) {
    vis[i][j] = true;

    for (int p = 0; p < 3; p++) {
        for (int q = 0; q < 3; q++) {
            int newX = i + x[p];
            int newY = j + y[q];
            // cout << newX << " " << newY << endl;
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1' && !vis[newX][newY]) {
                dfs(grid, newX, newY, vis, n, m);
            }
        }
    }
    return;
}

int numIslands(vector<vector<char>> &grid) {
    int output = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && !vis[i][j]) {
                output++;
                dfs(grid, i, j, vis, n, m);
            }
        }
    }

    return output;
}

int main() {

    return 0;
}