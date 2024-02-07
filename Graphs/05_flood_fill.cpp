
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int xy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> output = image;
    int startingColor = image[sr][sc];

    queue<pair<int, int>> q;

    q.push({sr, sc});
    output[sr][sc] = newColor;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;

        for (int i = 0; i < 4; i++) {
            int nr = r + xy[i][0];
            int nc = c + xy[i][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && output[nr][nc] == startingColor) {
                output[nr][nc] = newColor;
                q.push({nr, nc});
            }
        }
    }

    return output;
}

int main() {

    return 0;
}