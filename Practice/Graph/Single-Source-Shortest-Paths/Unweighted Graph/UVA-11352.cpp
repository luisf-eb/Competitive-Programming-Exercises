#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, m;
vector<pair<int, int>> knightMoves = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
vector<pair<int, int>> kingMoves = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        vector<string> board(n);
        vector<vector<int>> visited(n, vector<int>(m, 0)), distances(n, vector<int>(m, 0));
        pair<int, int> posKing, posPrincess;
    
        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j] == 'Z') {
                    for(auto& move : knightMoves) {
                        int ni = i + move.first;
                        int nj = j + move.second;
                        if(!isValid(ni, nj)) continue;
                        if(board[ni][nj] != 'A' && board[ni][nj] != 'B' && board[ni][nj] != 'Z')
                            board[ni][nj] = 'X';
                    }
                }
                else if (board[i][j] == 'A') {
                    posKing = {i, j};
                }
                else if (board[i][j] == 'B') {
                    posPrincess = {i, j};
                }
            }
        }

        queue<pair<int, int>> q;
        q.push(posKing);
        visited[posKing.first][posKing.second] = 1;

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            if (i == posPrincess.first && j == posPrincess.second) break;

            for(auto& move : kingMoves) {
                int ni = i + move.first;
                int nj = j + move.second;

                if(isValid(ni, nj) && !visited[ni][nj] && (board[ni][nj] == '.' || board[ni][nj] == 'B')) {
                    visited[ni][nj] = 1;
                    distances[ni][nj] = distances[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        
        if (visited[posPrincess.first][posPrincess.second] == 0) 
            cout << "King Peter, you can't go now!\n";
        else 
            cout << "Minimal possible length of a trip is " << distances[posPrincess.first][posPrincess.second] << '\n';
    }
    
    return 0;
}
