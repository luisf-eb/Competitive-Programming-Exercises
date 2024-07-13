#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int di[] = {1, -1};
int dj[] = {1, -1};
int n;

bool isValid(int i, int j) {
    if ( (i < 0 || i >= n) || (j < 0 || j >= n)) return false;
    else return true;
}

void floodfill(int i, int j, char c1, char c2, vector<string>& grid) {
    if(!isValid(i, j)) return;
    if( grid[i][j] == '.') return;
    
    grid[i][j] = '.';
    
    if ( (isValid(i+1, j) and grid[i+1][j] != '.') || (isValid(i-1, j) and grid[i-1][j] != '.')) {
        for (int d = 0; d < 2; d++) 
            floodfill(i + di[d], j, c1, c2, grid);
    }
    else if ( (isValid(i, j+1) and grid[i][j+1] != '.') || (isValid(i, j-1) and grid[i][j-1] != '.')) {
        for (int d = 0; d < 2; d++) 
            floodfill(i, j + dj[d], c1, c2, grid);
    }
    
}

int32_t main() { 
    fastio;

    string input;
    int t;
    cin >> t;
    int cases = 1;

    while (t--) {
        cin >> n;
        vector<string> grid(n);
        int total = 0;
        grid.clear();

        for (int i = 0; i < n; i++) {
            cin >> input;
            grid.push_back(input);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '@' and grid[i][j] != '.') {
                    floodfill(i, j, 'x', '.', grid);
                    total++;
                }
            }
        }
        cout << "Case " << cases++ << ": " << total << '\n';
    }
    

    return 0;
}
