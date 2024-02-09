#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int xy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void helper(int n, int m, vector<vector<char>> &mat, vector<vector<char>> &output, int r, int c) {
    // cout << r << " " << c << endl;
    output[r][c] = 'O';

    for (int i = 0; i < 4; i++) {
        int nr = r + xy[i][0];
        int nc = c + xy[i][1];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 'O' && output[nr][nc] == 'X') {
            helper(n, m, mat, output, nr, nc);
        }
    }
    return;
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    vector<vector<char>> output(n, vector<char>(m, 'X'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && mat[i][j] == 'O' && output[i][j] == 'X') {
                helper(n, m, mat, output, i, j);
            }
        }
    }

    return output;
}

int main() {

    return 0;
}