#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<pair<int, int>> kingMoves = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

bool isValid(int i, int j) {
    return (i > 0 && i <= 8 && j > 0 && j <= 8);
}

int main() {
    fastio;
    
    int r1, c1, r2, c2, r3, c3;
    int cases = 1;

    while (cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3) {
        vector<vector<int>> visited(9, vector<int>(9, 0));
        visited[r3][c3] = 1;
        visited[r1][c1] = 1; 

        queue<tuple<int, int, int>> q;
        q.push({r1, c1, 0});
        int moves = 0;

        while (!q.empty()) {
            auto [i, j, d] = q.front(); q.pop();

            if(i == r2 && j == c2) {
                moves = d;
                break;
            }

            for(auto& move : kingMoves) {
                int ni = i + move.first;
                int nj = j + move.second;

                if(isValid(ni, nj) && !visited[ni][nj]) {
                    visited[ni][nj] = 1;
                    q.push({ni, nj, d+1});
                }
            }
        }

        cout << "Case " << cases++ << ": " << moves << '\n';
        
    }
    
    
    return 0;
}
