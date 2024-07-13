#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<pair<int,int>> directions = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

int main() { fastio;

    int r, c, bombs, total;

    while (cin >> r >> c) {
        if(r == 0 && c == 0) break;

        vector<vector<int>> grid(r, vector<int>(c, 0));
        vector<vector<int>> visited(r, vector<int>(c, 0));
        
        cin >> bombs;
        while (bombs--) {
            int i, j, n;
            cin >> i >> n;
            while (n--) {
                cin >> j;
                grid[i][j] = 1;
            }
        }

        int x_start, y_start, x_end, y_end;

        cin >> x_start >> y_start;
        cin >> x_end >> y_end;

        queue<tuple<int, int, int>> q;
        q.push({x_start, y_start, 0});
        visited[x_start][y_start] = 1;

        while (!q.empty()) {
            auto [i, j, d] = q.front(); q.pop();

            if (i == x_end && j == y_end) {
                total = d;
                break;
            }
            for (int dire = 0; dire < 4; dire++) {
                int ni = i + directions[dire].first;
                int nj = j + directions[dire].second;
                
                
                if (ni >= 0 && ni < r && nj >= 0 && nj <c) {
                    if (!visited[ni][nj] && grid[ni][nj] != 1) {
                        visited[ni][nj] = 1;
                        q.push({ni, nj, d+1});        
                    } 
                }
            }
        }

        
        cout << total << '\n';
    }
return 0;
}