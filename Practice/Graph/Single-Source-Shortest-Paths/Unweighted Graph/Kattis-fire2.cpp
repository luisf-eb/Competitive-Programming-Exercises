#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F

using namespace std;

int n, m;

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int main() { 
    fastio;
    
    vector<pair<int,int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        
        vector<string> grid(n);
        vector<pair<int, int>> flames;
        vector<vector<int>> visited(n, vector<int>(m, INF)), fireSpreading(n, vector<int>(m, INF));
        int startingX, startingY;
        
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            for (int k = 0; k < m; k++) {
                if(grid[i][k] == '*') flames.push_back({i, k});
                else if(grid[i][k] == '@') {
                    startingX = i, startingY = k;
                }
            }
        }

        queue<pair<int, int>> q1;
        for (auto& fire : flames) {
            int x1 = fire.first, y1 = fire.second;
            fireSpreading[x1][y1] = 0;
            q1.push({x1, y1});
        }

        while (!q1.empty()) {
            auto [i, j] = q1.front(); q1.pop();

            for(auto& move : directions) {
                int ni = i + move.first;
                int nj = j + move.second;

                if(!isValid(ni, nj) || grid[ni][nj] == '#') continue;

                if(fireSpreading[i][j] + 1 < fireSpreading[ni][nj]) {
                    fireSpreading[ni][nj] = fireSpreading[i][j]+1;
                    q1.push({ni, nj});
                }
            }   
        }

        queue<tuple<int, int>> q;
        q.push({startingX, startingY});
        visited[startingX][startingY] = 0;
        int steps = INF;

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            if(i == 0 || i == n-1 || j == 0 || j == m-1)
                steps = min(steps, visited[i][j]+1);

            for(auto& move : directions) {
                int ni = i + move.first;
                int nj = j + move.second;
                if(!isValid(ni, nj) || grid[ni][nj] != '.') continue;
                if(visited[ni][nj] > visited[i][j]+1 && visited[i][j]+1 < fireSpreading[ni][nj]) {
                    visited[ni][nj] = visited[i][j]+1;
                    q.push({ni, nj});
                }
            }
        }
        
        if(steps != INF) cout << steps << '\n';
        else cout << "IMPOSSIBLE\n";
    }
    
    
      
    return 0;
}
