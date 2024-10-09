#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int n;
vector<ii> dir = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool isValid(vector<string>& grid, int i, int j) {
    if(i < 0 || i >= n || j < 0 || i >= n || grid[i][j] == '*' || grid[i][j] == 'X') return false;
    for (int r = i+1; r < n; r++) {
        if(grid[r][j] == 'X') break;
        if(grid[r][j] == '*') return false;
    }
    for (int r = i-1; r >= 0; r--){
        if(grid[r][j] == 'X') break;
        if(grid[r][j] == '*') return false;
    }
    
    for (int c = j+1; c < n; c++){
        if(grid[i][c] == 'X') break;
        if(grid[i][c] == '*') return false;
    }
    for (int c = j-1; c >= 0; c--){
        if(grid[i][c] == 'X') break;
        if(grid[i][c] == '*') return false;
    }

    return true;
}

int backtrack(vector<string>& grid, int i, int j) {
    if(i == n-1 && j == n-1) {
        if(isValid(grid, i, j)) return 1;
        else return 0;
    }


    int ans = 0, with = 0, without = 0;
    if(isValid(grid, i, j)) {
        grid[i][j] = '*';
        if(i == n-1) with = 1 + backtrack(grid, 0, j+1);
        else with = 1 + backtrack(grid, i+1, j);

        grid[i][j] = '.';
        if(i == n-1) without = backtrack(grid, 0, j+1);
        else without = backtrack(grid, i+1, j);
    } else {
        if(i == n-1) without = backtrack(grid, 0, j+1);
        else without = backtrack(grid, i+1, j);
    }

    ans = max(with, without);
    return ans;
}

int main() { fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    while(cin >> n && n){
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        
        int ans = backtrack(grid, 0, 0);
        cout << ans << "\n";
    }

    return 0;
}