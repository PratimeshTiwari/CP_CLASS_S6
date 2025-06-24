#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fillCrops(int n, int m, const vector<int>& crops) {
    vector<vector<int>> grid(n, vector<int>(m, 0));
    int cropType = 1, idx = 0, count = crops[0];
    bool leftToRight = true;
    int r = 0, c = 0;

    while (r < n) {
        grid[r][c] = cropType;
        count--;

        if (count == 0) {
            idx++;
            if (idx < crops.size()) {
                cropType = idx + 1;
                count = crops[idx];
            }
        }

        if (leftToRight) c++;
        else c--;

        if (c >= m || c < 0) {
            r++;
            if (r >= n) break;
            leftToRight = !leftToRight;
            c = leftToRight ? 0 : m - 1;
        }
    }

    return grid;
}

void printGrid(const vector<vector<int>>& grid) {
    for (auto& row : grid) {
        for (int cell : row) cout << cell << " ";
        cout << "\n";
    }
}

int main() {
    vector<int> crops = {4, 3, 3}; 
    int n = 2, m = 5;              
    auto grid = fillCrops(n, m, crops);
    printGrid(grid);
    return 0;
}