#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main() { 
    fastio;
    

    vector<pair<int,int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m, 0)), visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0}); visited[0][0] = 1;
    int steps = -1;

    while(!q.empty()) {
        auto[i, j, moves] = q.front(); q.pop();

        if(i == n-1 && j == m-1) {
            steps = moves;
            break;
        }

        for (auto& d : directions) {
            int ni = i + (d.first*grid[i][j]);
            int nj = j + (d.second*grid[i][j]);

            if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                if(!visited[ni][nj]) {
                    visited[ni][nj] = 1;
                    q.push({ni, nj, moves+1});
                }
            }
        } 
    }
    
    cout << steps;
    
    return 0;
}
