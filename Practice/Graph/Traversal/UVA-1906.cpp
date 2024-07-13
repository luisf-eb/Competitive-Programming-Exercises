#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int r, c, m, n;

void dfs(int i, int j, int grafo[100][100], int visited[100][100]) {
    visited[i][j] = 1;
    vector<int> i_moves = {m, m, -m, -m, n, n, -n, -n};
    vector<int> j_moves = {n, -n, n, -n, m, -m, m, -m};

    set<pair<int, int>> b;

    for (int k = 0; k < 8; k++) {
        int x = i + i_moves[k]; 
        int y = j + j_moves[k];

        if (x >= 0 and x < r and y >= 0 and y < c and grafo[x][y] != -1 and b.find({x,y}) == b.end()) {
            b.insert({x, y});
            grafo[x][y]++;
            if (!visited[x][y]) dfs(x, y, grafo, visited);
        }
    } 
}


int main() {
    fastio;
    
    int t, waters;
    int cases = 0;
    cin >> t;
    while (t--) {
        int grafo[100][100];
        int visited[100][100];
        cin >> r >> c >> m >> n;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                grafo[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        
        cin >> waters;
        while (waters--) {
            int i, j;
            cin >> i >> j;
            grafo[i][j] = -1;
        }

        dfs(0, 0, grafo, visited);
        int odds = 0;
        int evens = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grafo[i][j] != 0 and grafo[i][j] != -1 or (i == 0 and j == 0)) {
                    if(grafo[i][j] & 1) evens++;
                    else odds++;
                }
            }
        }

        cout << "Case " << ++cases << ": " << odds << " " << evens << '\n';
            
    }
    
   
    return 0;
}
