#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int m, n, total;
int di[] = {1, 0, -1, 0};
int dj[] = {0, -1, 0, 1};

int floodFill(int i, int j, char c1, char c2, vector<string>& grid) {
    if ( (i < 0) || (i >= m) ) return 0;
    if ( grid[i][j] != c1 ) return 0;

    grid[i][j] = c2;
    int ans = 1;

    for (int d = 0; d < 4; d++) {
        ans += floodFill(i + di[d], (j + dj[d] + n)%n, c1, c2, grid);
    }

    return ans;
}

int32_t main() { 
    fastio;
    string input;
    int x, y;
    while (cin >> m >> n){

        vector<string> grid(m);
        vector<int> ans;
        grid.clear();
        ans.clear();

        for (int i = 0; i < m; i++) {
            cin >> input;
            grid.push_back(input);
        }

        cin >> x >> y;
        char c1 = grid[x][y];
        floodFill(x, y, c1, '.', grid);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == c1) {
                    int total = floodFill(i, j, c1, '.', grid);
                    ans.push_back(total);
                }
            }
            
        }
        
        if(ans.empty()) cout << 0 << '\n';
        else cout << *max_element(ans.begin(), ans.end()) << '\n';
        cin.ignore();
    }
    
   
    return 0;
}