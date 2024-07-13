#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<pair<int, int>> directions = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };
vector<vector<int>> grid;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;
vector<vector<int>> taken;
int m, n;

bool isValid(int i, int j) {
    return (i >= 0 && i < m && j >= 0 && j < n);
}

void process(int i, int j) {
    taken[i][j] = 1;

    for (int d = 0; d < 4; d++) {
        int ni = i + directions[d].first;
        int nj = j + directions[d].second;
        if(isValid(ni, nj) && !taken[ni][nj]) {
            int dist = max(0, grid[ni][nj] - grid[i][j]);
            pq.push({-dist, -ni, -nj});
        }
    }
    
}

int main() {
    fastio;
    cin >> m >> n;
    
    grid.assign(m, vector<int>(n, 0));
    taken.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    while (!pq.empty()) pq.pop();
    
    process(0, 0);
    int minHeight = 0;
    while (!pq.empty()) {
        auto [d, i, j] = pq.top(); pq.pop();
        if(taken[-i][-j]) continue;
        minHeight = max(minHeight, -d);
        process(-i, -j);
        if(taken[m-1][n-1]) break;
    }
    
    cout << minHeight << '\n';

    return 0;
}
