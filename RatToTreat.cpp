#include <bits/stdc++.h>
using namespace std;

vector<int> di = {0, 0, 1, -1};
vector<int> dj = {1, -1, 0, 0};

vector<vector<int>> computeCatDistance(vector<vector<char>>& grid, int n, int m, pair<int,int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[start.first][start.second] = true;
    vector<vector<int>> dis(n, vector<int>(m, -1));
    dis[start.first][start.second] = 0;
    int path = 1;

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + di[d];
                int ny = y + dj[d];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    !visited[nx][ny] && grid[nx][ny] != 'W') {
                    visited[nx][ny] = true;
                    dis[nx][ny] = path;
                    q.push({nx, ny});
                }
            }
        }
        path++;
    }
    return dis;
}

bool canReach(vector<vector<char>>& grid, vector<vector<int>>& distFromCat,
              int n, int m, int sx, int sy, int tx, int ty, int minSafeDist) {
    if (distFromCat[sx][sy] < minSafeDist) return false;

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    q.push({sx, sy});
    vis[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == tx && y == ty) return true;

        for (int k = 0; k < 4; k++) {
            int nx = x + di[k];
            int ny = y + dj[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                !vis[nx][ny] && grid[nx][ny] != 'W' &&
                distFromCat[nx][ny] >= minSafeDist) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int maxMinDistance(vector<vector<char>>& grid, int n, int m,
                   pair<int, int> start, pair<int, int> treat, pair<int, int> cat) {
    auto distFromCat = computeCatDistance(grid, n, m, cat);

    int lo = 0, hi = n + m, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canReach(grid, distFromCat, n, m, start.first, start.second, treat.first, treat.second, mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<vector<char>> grid = {
        {'.', '.', '.', 'W', '.'},
        {'S', 'W', '.', '.', '.'},
        {'.', '.', '.', 'W', '.'},
        {'W', '.', '.', '.', 'T'},
        {'.', '.', 'C', '.', '.'}
    };

    pair<int, int> start = {1, 0};
    pair<int, int> cat = {4, 2};
    pair<int, int> treat = {3, 4};

    int result = maxMinDistance(grid, grid.size(), grid[0].size(), start, treat, cat);
    cout << "Max minimal distance from cat along the path = " << result << endl;
    return 0;
}
