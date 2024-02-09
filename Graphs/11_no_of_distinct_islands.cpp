#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int xy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

string generateString(int r, int c) {
    string output = to_string(r) + "." + to_string(c);
    return output;
}

string helper(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &copy, int r, int c, int startr, int startc) {

    copy[r][c] = 0;
    string output = generateString(r - startr, c - startc);
    for (int i = 0; i < 4; i++) {
        int nr = r + xy[i][0];
        int nc = c + xy[i][1];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && copy[nr][nc] == 1) {
            string str = helper(n, m, grid, copy, nr, nc, startr, startc);
            output += "." + str;
        }
    }
    return output;
}
int countDistinctIslands(vector<vector<int>> &grid) {

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> copy = grid;
    unordered_set<string> st; // stores shape of islands

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && copy[i][j] == 1) {
                string str = helper(n, m, grid, copy, i, j, i, j);
                st.insert(str);
            }
        }
    }

    return st.size();
}

int main() {

    return 0;
}