#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int di[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};
int rows, col;

int floodfill(int i, int j, char c1, char c2, vector<string>& grid) {
    if( (i < 0) || (i >= rows) ) return 0;
    if( (j < 0) || (j >= col) ) return 0;
    if( grid[i][j] != c1) return 0;
    int ans = 1;
    grid[i][j] = c2;
    for (int k = 0; k < 8; k++) 
        ans += floodfill(i+di[k], j+dj[k], c1, c2, grid);
    
    return ans;
}

int32_t main() { 
    fastio;

    int t;
    string entrada;

    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--) {
        
        vector<string> grid;
        while (getline(cin, entrada) && (entrada[0] == 'L' || entrada[0] == 'W')) 
            grid.push_back(entrada);
        
        rows = grid.size();
        col = grid[0].size();

        vector<string> originalGrid = grid;
        
        stringstream ss(entrada);
        int i, j;

        ss >> i >> j;
        int total = floodfill(i-1, j-1, 'W', '.', grid);
        cout << total << '\n';

        while (getline(cin, entrada) && !entrada.empty()) {
            stringstream ss(entrada);
            ss >> i >> j;
            grid = originalGrid;
            total = floodfill(i - 1, j - 1, 'W', '.', grid);
            cout << total << '\n';
        }

        if (t > 0) cout << '\n';
    } 

    return 0;
}
