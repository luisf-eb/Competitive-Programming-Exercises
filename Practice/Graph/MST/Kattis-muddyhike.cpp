#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int r, c;
vector<vector<int>> grid;
vector<vector<bool>> visited;

// Directions for moving up, down, left, and right
int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, -1, 1};

// Function to check if a cell is within the grid and hasn't been visited yet
bool isValid(int x, int y, int maxDepth) {
    return x >= 0 && x < r && y >= 0 && y < c && !visited[x][y] && grid[x][y] <= maxDepth;
}

// Function to perform BFS and check if it's possible to reach the rightmost column
bool bfs(int maxDepth) {
    queue<pair<int, int>> q;
    visited.assign(r, vector<bool>(c, false));

    // Initialize the queue with all cells from the leftmost column
    for (int i = 0; i < r; ++i) {
        if (grid[i][0] <= maxDepth) {
            q.push({i, 0});
            visited[i][0] = true;
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // If we reached the rightmost column, return true
        if (y == c - 1) {
            return true;
        }

        // Explore the four possible directions
        for (int d = 0; d < 4; ++d) {
            int newX = x + dirX[d];
            int newY = y + dirY[d];

            if (isValid(newX, newY, maxDepth)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    return false;
}

int main() {
    cin >> r >> c;
    grid.assign(r, vector<int>(c));

    // Read the grid
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }

    // Binary search to find the minimum possible maximum depth
    int left = 0, right = 1e6, result = 1e6;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (bfs(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
