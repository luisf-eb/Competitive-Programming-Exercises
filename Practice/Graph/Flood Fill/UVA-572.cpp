#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int m, n, total;
int di[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int floodFill(int i, int j, char c1, char c2, vector<string>& grid) {
    if ( (i < 0) || (i >= m) ) return 0;
    if ( (j < 0) || (j >= n) ) return 0;
    if ( grid[i][j] != c1 ) return 0;

    grid[i][j] = c2;
    int ans = 1;

    for (int d = 0; d < 8; d++) {
        ans += floodFill(i + di[d], j + dj[d], c1, c2, grid);
    }

    return ans;
}

int32_t main() { 
    fastio;
    string input;

    while (cin >> m >> n and m != 0){
        vector<string> grid(m);
        grid.clear();
        int res = 0;

        for (int i = 0; i < m; i++) {
            cin >> input;
            grid.push_back(input);
        }

        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                total = floodFill(i, j, '@', '.', grid);
                if (total) res++;
            }
        }

        cout << res << '\n';
    }
    
   
    return 0;
}
